//===============================================================================
// A/D Conversion Functions
//===============================================================================
//
////////////////////////////////////////////////////////////////////////
// Function Prototypes

void ADC_Config(void);		
void IR_CalcDistance(void);									
void WhiteLineCheck(void);

int sr_Reading2Distance(int Sensor);
int lr_Reading2Distance(int Sensor);
int sonar_Reading2Distance(int Sensor);
int SensorDistanceCalc(char Type);

////////////////////////////////////////////////////////////////////////
// Globals / Constants 
int IR_LR_FRONT = 0, IR_SR_FRONT = 0, IR_LR_REAR = 0, 
	IR_LR_TURRET = 0, IR_SR_TURRET = 0, WHITE_LINE_READING = 0;
int AVG_IR_LR_FRONT = 0, AVG_IR_SR_FRONT = 0, AVG_IR_LR_REAR = 0, 
	AVG_IR_LR_TURRET = 0, AVG_IR_SR_TURRET = 0;
int ADC_count = 0;

#if DEBUG>0				// Only needed in debug mode.
int DEBUG_ADRead = 0;	//
#endif					//

int WhiteLineMax = 0;		// Must be set low for first test. 
int WhiteLineMin = 1024;	// Must be set high for first test.
int WhiteLineCount = 100;
char WHITELINE = 0;			// Flag indicating white line was found. 

#if DEBUG>0
int WHITELINE_DEBUG;		// Flag to send out information during debug. 
int SOUNDSTART_DEBUG = 0;
#endif


////////////////////////////////////////////////////////////////////////
// Functions
//
//-------------------------------------------------------------------------------
//ADCconfig -- This function configures the A/D coverter registers. 

void ADC_Config(void)
{
	#if DEBUG>0
		printf("Loading A/D Converter...");
	#endif

	ADCON1 = 0x0000;		// Clear ADC control registers
	ADCON2 = 0x0000;		// From Vaughn's Code
	ADCON3 = 0x0000;		//
	TRISB = 0;				// 
	

	TRISB |= 0x053F;		// Sets RB[0-4] and RB8,RB10 for inputs
							// for A/D
							// RB[4:5] are for QEI
		
	ADPCFG = 0xFAF0;		// Set ports to analog inputs
							// 1 Digital Input
							// 0 Analog Input 

	ADCON1 = 0x00E4;		
	ADCON2 = 0x0414;		//  Interrupt every 6th Sample
//	ADCON3 = 0x0302;		//  2Tad and 2Tcy
	ADCON3 = 0x1F3F;		// 	32Tad and 32Tcy
	ADCHS = 0x0000;			
	ADCSSL = 0x050F;		// Enable input scan on the pins
							
	IFS0bits.ADIF = 0;		// Clear Interrupt Flag.
	IEC0bits.ADIE = 1;		// Enable Interrupts
	ADCON1bits.ADON = 1;	// Turn ADC ON

	#if DEBUG>0
		printf("DONE\r\n");
	#endif

	return;
}


void WhiteLineCheck(void)
{
	//Rember: white = reflection = transistor on = low A/D Reading!!!!!!
	
	int WhiteLineThreshold;
	//Calculate new Max/Min values
	if(WHITE_LINE_READING < 600)
	{
		WhiteLineMax = (WhiteLineMax < WHITE_LINE_READING)?WHITE_LINE_READING:WhiteLineMax;
	}

	
	WhiteLineMin = (WhiteLineMin > WHITE_LINE_READING)?WHITE_LINE_READING:WhiteLineMin;
	
	WhiteLineThreshold = WhiteLineMin + ((WhiteLineMax-WhiteLineMin)/5); //20%
	
	if(WHITE_LINE_READING < WhiteLineThreshold)
	{
		WhiteLineCount++;
	}
	else
	{
		WhiteLineCount--;
	}
	
	if(WhiteLineCount > 110)
	{
		WHITELINE = 1;
		WhiteLineCount = 110;
	}
	else if(WhiteLineCount < 100)
	{
		WHITELINE = 0;
		WhiteLineCount = 100;
	}	
	WHITELINE ? (FF_OFFSET = 20) : (FF_OFFSET = 8);
	
	/////////////////////////
	#if DEBUG
		if(WHITELINE_DEBUG == 1)
		{
			printf("%u|%u||%u|%u|\%u||%u\r\n",WHITELINE,WhiteLineCount,WhiteLineMin,WhiteLineMax,WhiteLineThreshold,WHITE_LINE_READING);
		}
	#endif
	/////////////////////////
	
	return;
}

int SensorDistanceCalc(char Type)
{
	// Type is turret 0 , front 1  and rear 2. 
	
	int Distance = 0, DistanceFront = 0, LRSensor, LRSensorFront, SRSensor, SRSensorFront, Sonar;
		
	switch(Type)
	{
		case 0: // Turret Sensors. 
			LRSensor = AVG_IR_LR_TURRET;
			SRSensor = AVG_IR_SR_TURRET;
			Sonar = SONAR_TURRET;
			if(SRSensor >= 300)
			{
				// Past or close to LR alaising point, Ignore LR!!!
				Distance = sr_Reading2Distance(SRSensor); // Get distance for encoders
			}
			else if(LRSensor < 100)
			{
				// Go off of sonar only
				Distance = sonar_Reading2Distance(Sonar);
			}
			
			else
			{
				// Not close to aliasing point, ignore SR.
				Distance = lr_Reading2Distance(LRSensor);
			}
		break;
		case 1:	// Front sensors. 
			LRSensor = AVG_IR_LR_FRONT;
			SRSensor = AVG_IR_SR_FRONT;
			Sonar = SONAR_FRONT;
			if(SRSensor >= 300)
			{
				// Past or close to LR alaising point, Ignore LR!!!
				Distance = sr_Reading2Distance(SRSensor); // Get distance for encoders
			}
			else if(LRSensor < 100)
			{
				// Go off of sonar only
				Distance = sonar_Reading2Distance(Sonar);
			}
			
			else
			{
				// Not close to aliasing point, ignore SR.
				Distance = lr_Reading2Distance(LRSensor);
			}
		break;
		case 2: // Rear sensor.
			LRSensor = AVG_IR_LR_REAR;
			Sonar = SONAR_REAR;
			if(LRSensor > 100)
			{
				Distance = lr_Reading2Distance(LRSensor); 
			}
			else
			{
				Distance = sonar_Reading2Distance(Sonar);
			}
		break;
	};
	return Distance;
}

int lr_Reading2Distance(int Sensor)
{

	float result = 0.0;
	int count = 0;
	result = (float)1 / Sensor;
	result = result * 9349.5;
	count = result * 100;

	return count;

}

int sr_Reading2Distance(int Sensor)
{
	float result = 0.0;
	int count = 0;
	result = (float)10000 / Sensor;
	result = result / 5;
	count = result * 100;
	
	return count;
}

int sonar_Reading2Distance(int Sensor)
{
	int count = 0;
	float result = 0.0;
	result = (float)Sensor / 9996; //9996 counts/inch ---> 147us/in * 68counts/1us = 9996. 68 counts/us is based on a 64 prescale of timer 3. 
	count = result * 100;
	
	return count;
}
