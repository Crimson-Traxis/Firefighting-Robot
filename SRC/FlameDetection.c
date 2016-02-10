//===============================================================================
// Flame Detection
//===============================================================================
//
////////////////////////////////////////////////////////////////////////
// Function Prototypes
void UpdateThermalArray(void);
void UpdateHotspotValues(void);
void CANDLE_LOCATE(void);
int CANDLE_PRESENT(void);
void CANDLE_EXTINGUISH(void);
void LONG_THERMAL_ROOM_SCAN(void);
void SHORT_THERMAL_ROOM_SCAN(void);
//void LocateAndExtinquish(void);
void THERMAL_TILT(int Tilt);

////////////////////////////////////////////////////////////////////////
// Globals / Constants 


int FF_LAST_READ_ARRAY[8];
int FF_AMBIENT_TEMP = 0;


int CANDLE_LOCATED = 0;
char HOTSPOT = 0;
int HOTSPOT_VAL = 0;
int HOTROOM = 0;
char CANDLE_TURRET_SCAN_LOCATION = 0;
char ScanFail, ScanPass;
char FIND_CANDLE = 0;

//// Thermal scan
int ScanIncrement = 20; // X degrees
int ScanLeftMax = -60;
int ScanRightMax = 80;
int shortRoomAngleOffset = 20;
//// Candle Extinguish
#define AngleStartOffset 15
int TurretExtinguishCount = 2*AngleStartOffset;
////////////////////////////////////////////////////////////////////////
// Functions
//

void UpdateThermalArray()
{
	char i;
	FF_AMBIENT_TEMP = I2CReadWord(THERMAL_ADDRESS,1);				//Read Ambient Temp and store in global
	for(i = 2; i <= 9; i++)
	{
		FF_LAST_READ_ARRAY[i-2] = I2CReadWord(THERMAL_ADDRESS,i);	//Read other pixels into Global Array
	} 																
	return;
}

void UpdateHotspotValues()
{
	char i = 0, Max = 0; 
	int Temp = 0;
	HOTSPOT_VAL = 0;	//Clear global

	for(i = 0; i < 8; i++)
	{
		if((FF_LAST_READ_ARRAY[i] >= Temp))			// This loop will grab the highest value
		{											// from the last Thermal array read
			HOTSPOT = i;
			Temp = FF_LAST_READ_ARRAY[i];			
			HOTSPOT_VAL = FF_LAST_READ_ARRAY[i];	// Store highest as the Hotspot value
		}
	}

	return;
}


void CANDLE_LOCATE()
{
	int Max = 0;
	int x, j, k;
	UpdateThermalArray();	// Update values for most current data. 
	UpdateHotspotValues();	//

	////////////////////////////////////////////////////////////
	// Debugging infromation -- Remove when happy with. 
	
	//for(j=0; j < 8; j++)
	//{
	//	printf("%u |",FF_LAST_READ_ARRAY[j]);	
	//}
	//printf("A %u | HP %u |HPV %u",FF_AMBIENT_TEMP,HOTSPOT,(HOTSPOT_VAL));
	
	////////////////////////////////////////////////////////////

	if((HOTSPOT_VAL) >= (FF_AMBIENT_TEMP+FF_OFFSET))
	{
		ScanFail = 0;
		if(HOTSPOT < 3)
		{
			x = SERVO_TURRET_ANGLE + (3 - HOTSPOT);	
			if(x >= 90)
			{
				x = 90;
			}
			////////////////////
		//	printf(" %d\r\n",x);
			////////////////////
			SERVO_ADJUST_TURRET(x);
	
		}
		else if(HOTSPOT > 4)
		{
			x = SERVO_TURRET_ANGLE - (HOTSPOT - 4);
			if(x <= -90)
			{
				x = -90;
			}
			////////////////////
		//	printf(" %d\r\n",x);
			////////////////////
			SERVO_ADJUST_TURRET(x);
		}	
		else
		{
			/////////////////
	//		printf(" *\r\n");
			/////////////////
		}
	}
	else
	{
		////////////////
	//	printf("\r\n");
		////////////////
		ScanFail++;
	}

	HardwareDelayNmSec(5);

	return;

}

int CANDLE_PRESENT()
{
	//////////////////////////////////
	//printf("Checking for Candle...\r\n");
	//////////////////////////////////
	int i, present = 0;
	UpdateThermalArray();
	UpdateHotspotValues();
	
	for(i = 2; i <= 9; i++)
	{
		if((HOTSPOT_VAL) >= (FF_AMBIENT_TEMP+FF_OFFSET))
		{
			///////////////////////////
			//printf("CANDLE FOUND\r\n");
			///////////////////////////
			present = 1;
		}
	}

	return present;
}





///////////////////////////////////////////////////
// THERMAL SCAN
// 
void LONG_THERMAL_ROOM_SCAN(void)
{
	// This function will scan in X degree increments from
	// ScanLeftMax to ScanLeftRight, once the scan has completed
	// and the candle is not found, it will adjust the thermal tilt
	// (up then down) and repeat the scan. 
	//
	// Notes: There is some 'dead' time in this scan and it is only 
	// to make sure the servo is moving or moved to the new position
	// before checking the new value. 
	char scan = 1, candleFound = 0, x = 0, tilt = 0;
	char NextScanCount = 0;
	
	while(scan)
	{
		SERVO_ADJUST_TURRET(ScanLeftMax); // Set turret to -40
		if(tilt == 1)
		{
			HardwareDelayNmSec(800);	//a little bit longer since it is sweeping back
		}
		else
		{
			HardwareDelayNmSec(400);
		}
		
		while(!candleFound)
		{
			NextScanCount = 0;
			if(CANDLE_PRESENT())	// Check to see if candle is there.
			{
				scan = 0;			// Kill scan
				candleFound = 1;
				while(HOTSPOT != 3 && HOTSPOT != 4 && NextScanCount != 20)
				{
					CANDLE_LOCATE();	// Locate and center on candle.
					//NextScanCount++;
				}
			}
			else
			{
				if((SERVO_TURRET_ANGLE) == ScanRightMax)
				{
					break;	//We missed it, break out and try again. 
				}
				else
				{
					SERVO_ADJUST_TURRET(SERVO_TURRET_ANGLE+ScanIncrement); //Move turret another 20 degrees
					HardwareDelayNmSec(200);
				}
			}
		}
		
		if(!candleFound)
		{
			x++;
			THERMAL_TILT(x);
			///////////////////////////
			//printf("Tilt Thermal %u\r\n",x);
			///////////////////////////
			if(x == 2)	// Look straight ahead and tilt down. 
			{
				x = 0;
			}
			tilt = 1;
		}
	}
		
	return;
}


void SHORT_THERMAL_ROOM_SCAN(void)
{
	char scan = 1, candleFound = 0, x = 1, tilt = 0, ServoAdjust = 0;
	
	THERMAL_TILT(x);	// Put thermal at normal level. 
	while(scan)
	{
		
		while(!candleFound)
		{
			if(CANDLE_PRESENT())	// Check to see if candle is there.
			{
				scan = 0;			// Kill scan
				candleFound = 1;	//
				while(HOTSPOT != 3 && HOTSPOT != 4)
				{
					CANDLE_LOCATE();	// Locate and center on candle.
				}
			}
			else
			{
				x++;
				if(x == 3)
				{
					break;	//We missed it, break out and try again. 
				}
				else
				{
					THERMAL_TILT(x); 
					HardwareDelayNmSec(800);
				}
			}
		}
		
		if(!candleFound)
		{
			x = 0;
			THERMAL_TILT(x);
			ServoAdjust++;
			switch(ServoAdjust)
			{
				case 0:
					SERVO_ADJUST_TURRET(0);
				break;
				case 1:
					SERVO_ADJUST_TURRET(30);
				break;
				case 2:
					SERVO_ADJUST_TURRET(-30);
				break;
				case 3:
					SERVO_ADJUST_TURRET(60);
				break;
				case 4:
					SERVO_ADJUST_TURRET(-60);
				break;
				case 5:
					SERVO_ADJUST_TURRET(90);
				break;
				case 6:
					SERVO_ADJUST_TURRET(-90);
					ServoAdjust = -1;
				break;
				HardwareDelayNmSec(800);
			
			};
			
		}
	}
			
}





void THERMAL_TILT(int Tilt)
{
	switch(Tilt)
	{
		case 2:
			I2CWriteWord(THERMAL_ADDRESS,0,30);	//Look up									
		break;
		case 3:
			I2CWriteWord(THERMAL_ADDRESS,0,1); 	// Look down
		break;
		case 1:
			I2CWriteWord(THERMAL_ADDRESS,0,21);	// Look striaght ahead
		break;
	}
}


void CANDLE_EXTINGUISH()
{
	/////////////////////////
	// printf("EXTINGUISH\r\n");
	/////////////////////////
	char x=0;
	int StartAngle = SERVO_TURRET_ANGLE;
	while(UVCheck()) 
	{
		if(HOTSPOT == 3)
		{
			SERVO_ADJUST_TURRET((SERVO_TURRET_ANGLE + AngleStartOffset)); //Adjust turret back
		}
		else
		{
			SERVO_ADJUST_TURRET((SERVO_TURRET_ANGLE - AngleStartOffset)); //Adjust turret back
		}
	
		SERVO_ENABLE_CO2(1);	//Turn on Co2
		HardwareDelayNmSec(500); 		//Dead time for gas to come on

		while(x < TurretExtinguishCount)
		{
			if(HOTSPOT == 3)
			{
				SERVO_ADJUST_TURRET((SERVO_TURRET_ANGLE - 1)); //Adjust turret back
			}
			else
			{
				SERVO_ADJUST_TURRET((SERVO_TURRET_ANGLE + 1)); //Adjust turret back
			}
			HardwareDelayNmSec(20);								//
			x++;											//
		}
		SERVO_ENABLE_CO2(0);	// Turn off gas
								// Check for UV
		if(UVCheck())
		{
			SERVO_ENABLE_CO2(1);	//Turn on Co2
			HardwareDelayNmSec(500); 		//Dead time for gas to come on
			
			while(x > 0)
			{
				if(HOTSPOT == 3)
				{
					SERVO_ADJUST_TURRET((SERVO_TURRET_ANGLE + 1)); //Adjust turret back
				}
				else
				{
					SERVO_ADJUST_TURRET((SERVO_TURRET_ANGLE - 1)); //Adjust turret back
				}
				HardwareDelayNmSec(20);								//
				x--;											//
			}

			SERVO_ENABLE_CO2(0);	// Turn off gas
			UVCheck();				// Check for UV
			
			
			if(HOTSPOT == 3)
			{
				SERVO_ADJUST_TURRET((SERVO_TURRET_ANGLE - AngleStartOffset)); //Adjust turret back
			}
			else
			{
				SERVO_ADJUST_TURRET((SERVO_TURRET_ANGLE + AngleStartOffset)); //Adjust turret back
			}
				
		}
		else
		{
			SERVO_ADJUST_TURRET(StartAngle); // Return turret to start
		}
	}
		
	SERVO_ADJUST_TURRET(0); // Return turret to start
	///////////////////////
//	printf("CLEAR\r\n");
	//////////////////////
	return;	
}



/*
void LocateAndExtinquish(void)
{
	//////////////////////
	printf("Scanning for candle in room %u\r\n",HOTROOM);
	DelayNmSec(500);
	/////////////////////
 	THERMAL_SCAN();	
	while(!WHITELINE) // Repeat until WhiteLine is found
	{
		CANDLE_LOCATE(); 	//Locate candle
		Turn(SERVO_TURRET_ANGLE);		//MAKE SURE TO RECORD THIS 
		SERVO_ADJUST_TURRET(0);
		Forward_Dist_WL(DistanceCalc());	//MAKE SURE TO RECORD THIS 
	}
	CANDLE_LOCATE();	
	CANDLE_EXTINGUISH(); // Blow out candle and double check before leaving! 
}
*/	
