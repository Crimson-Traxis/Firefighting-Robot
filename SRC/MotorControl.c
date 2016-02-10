////MotorControl.c

////Functions that directly control the motors

//define the direction bits
#define RightMotorForward 0x0000
#define RightMotorReverse 0x0002
#define LeftMotorForward  0x0000
#define LeftMotorReverse  0x0008
#define RearMotorForward  0x0000
#define RearMotorReverse  0x0020
void Forward_Dist(int);
int Forward_Dist_WL(int);
void Reverse_Dist(int);
void Turn(int);
void LocateAndExtinguish(void);
void ReturnFromLocateAndExtinguish(void);
//void Drive(int);	
//int InitEncoderValue;


int RecordedAngle[20];
int RecordedDistance[20];
int RecordPointer = 0;

void Forward_Dist(int X) //distance in encoder counts
{
int InitEncoderValue;
LATE = (RightMotorForward | LeftMotorForward | RearMotorForward);  //Set the LAT bits for forward	
InitEncoderValue = ((POSCNT + QEIS_COUNTER)/2);  //grab current avg of wheel encoders
// !!!!!!!!!!!NO Overshoot compensation here - adjust calling function values 
while (((POSCNT + QEIS_COUNTER)/2) < (InitEncoderValue + X)) 
	{
	PDC1 = 2500; //3000; //right
	PDC2 = 2625; //3080; //left	//5% more left motor
	PDC3 = PDC1 - 500;
	PTCON = 0x8000;
	}
PTCON = 0x0000;
PDC1 = PDC2 = PDC3 = 0;	
}

/*
void Drive(int X) //positive forward
{
int InitEncoderValue;
int TestValue;
int Error;
int Pterm;
int Integral = 0;
int LoopCount;
int j;
 
TestValue = (((POSCNT + QEIS_COUNTER)/2) + X);

for(LoopCount=0; LoopCount < 20; LoopCount++) //repeat this several times to correct overshoot issues
{
	do
	{
		if (Error < 5) //kill the integral if the wheel is close
		{					//mostly important if one wheel arrives earlier 
			Integral = 0;
		}

		//late bits by direction
		if (TestValue > ((POSCNT + QEIS_COUNTER)/2)) //needs to go forward
		{
			LATE = (RightMotorForward | LeftMotorForward | RearMotorForward);  //Set the LAT bits for forward	
			Error = TestValue - ((POSCNT + QEIS_COUNTER)/2);
			Pterm = Error / 4;
			Pterm = (Pterm > 3000) ? 3000 : Pterm; //Pterm saturation
			PDC1 = 500 + Pterm + (Integral/8);  //right wheel  //base value + (2*error) + integral
			PDC2 = PDC1 + (PDC1/20);  //left wheel //needs 5% more
			PDC3 = ((2 * (PDC1 + PDC2)) / 5); //80% of the average
		}
		else // need to go backwards
		{
			LATE = (RightMotorReverse | LeftMotorReverse | RearMotorReverse);
			Error = ((POSCNT + QEIS_COUNTER)/2) - TestValue;
			Pterm = Error / 4;
			Pterm = (Pterm > 3000) ? 3000 : Pterm; //Pterm saturation
			PDC1 = 500 + Pterm + (Integral/8);  //right wheel  //base value + (2*error) + integral
			PDC2 = PDC1 + ((3 * PDC1) / 500);  //left wheel //needs 0.6% more
			PDC3 = PDC1 + ((4 * PDC2) / 25); //116%% of PDC1

		}
	
		if (++Integral > 16000) // this is a little dependant on the speed of the loop
		{							//  
			Integral = 16000;		//these IFs limit the integral windup
		}
		PTCON = 0x8000;
		for(j=0;j < 150;j++); //just a little dead time
	}
	while (Error > 3); // this gives it a deadband
HardwareDelayNmSec(5); //a little bit of time to let the chassis loose inertia
}
PDC1 = PDC2 = 0;
PTCON = 0;
}

*/

int Forward_Dist_WL(int X) //distance in encoder counts //returns actual distance traveled
{
int InitEncoderValue;
LATE = (RightMotorForward | LeftMotorForward | RearMotorForward);  //Set the LAT bits for forward	
InitEncoderValue = ((POSCNT + QEIS_COUNTER)/2);  //grab current avg of wheel encoders
// !!!!!!!!!!!NO Overshoot compensation here - adjust calling function values 
///while (((POSCNT + QEIS_COUNTER)/2) < (InitEncoderValue + X))
while ((((POSCNT + QEIS_COUNTER)/2) < (InitEncoderValue + X)) && (WHITELINE == false))
	{
	PDC1 = 2500; //3000; //right
	PDC2 = 2625; //3080; //left	//5% more left motor
	PDC3 = PDC1 - 500;
	PTCON = 0x8000;
	}
PTCON = 0x0000;
PDC1 = PDC2 = PDC3 = 0;
if (WHITELINE)
	{  //return the actual distace traveled if white line was found
	return ((POSCNT + QEIS_COUNTER)/2) - InitEncoderValue;
	}
else
	{
	return X;
	}

	
}


void Reverse_Dist(int X) //distance in encoder counts
{
int InitEncoderValue;
//Set the LAT bits for forward	
LATE = RightMotorReverse | LeftMotorReverse | RearMotorReverse;

//grab current avg of wheel encoders
InitEncoderValue = ((POSCNT + QEIS_COUNTER)/2);
while (((POSCNT + QEIS_COUNTER)/2) > ((InitEncoderValue - X) + 17)) //minus a guessed overshoot value
	{
//Set the PDC bits for a global speed value

	PDC1 = 2500; //3000; //right
	PDC2 = 2515; //3080; //left	
	PDC3 = PDC1 + 400;

	//PDC1 = PDC2 = 5000;	
	//PDC3 = PDC1 - 600; //rear motor always a little lower torque
	PTCON = 0x8000;
	}
	PTCON = 0x0000;
	PDC1 = PDC2 = PDC3 = 0;	//all stop
}





void Turn(int X)
{
int InitLEncoderValue, InitREncoderValue;
int LtestValue, RtestValue, EncCounts;
int Lerror, Rerror;
int Lintegral = 0, Rintegral = 0;
int TempLATE;
int LoopCount;
int j;
InitLEncoderValue = QEIS_COUNTER;
InitREncoderValue = POSCNT;

	EncCounts = ((X*201)/37);  // 201/37 = 5.432, the number of encoder counts on each wheel per degree
	//right (hardware) decreasing and left (software) increasing
	RtestValue = (InitREncoderValue - EncCounts);
	LtestValue = (InitLEncoderValue + EncCounts); 

for(LoopCount=0; LoopCount < 20; LoopCount++) //repeat this several times to correct overshoot issues
{
	do
	{	//late bits by direction
		TempLATE = 0;
		if (RtestValue > POSCNT) //right motor needs to go forward
		{
			//LATE = LATE & RightMotorForward; //clear the bit for forward
			Rerror = RtestValue - POSCNT;
		}
		else //right motor need to go backwards
		{
			TempLATE = RightMotorReverse; //set the bit for reverse
			Rerror = POSCNT - RtestValue;
		}
		
		if (LtestValue > QEIS_COUNTER)  // left motor needs to go forward
		{
			//LATE = LATE & LeftMotorForward; //clear the bit for forward
			Lerror = LtestValue - QEIS_COUNTER;
		}
		else //left needs to go backward
		{
			TempLATE = TempLATE | LeftMotorReverse; //set a bit for reverse
			Lerror = QEIS_COUNTER - LtestValue;
		}
		
		LATE = TempLATE;
	
		if (++Rintegral > 16000) // this is a little dependant on the speed of the loop
		{							//  
			Rintegral = 16000;		//these IFs limit the integral windup
		}
		
		if (++Lintegral > 16000)
		{
			Lintegral = 16000;
		}	
	
		if (Lerror < 3) //kill the integral if the wheel is close
		{					//mostly important if one wheel arrives earlier 
			Lintegral = 0;
		}
	
		if (Rerror < 3)
		{
			Rintegral = 0;
		}
	
					///proportional (2*error) term limeted to about 10000 (10%) (90 degrees = 488 counts)
		PDC1 = 1000 + (2*Rerror) + (Rintegral/4);  //right wheel  //base value + (2*error) + integral
		PDC2 = 1000 + (2*Lerror) + (Lintegral/4);  //left wheel
		PTCON = 0x8000;
		for(j=0;j <150;j++); //just a little dead time
	}
	while (Rerror > 3 || Lerror > 3); // this gives it a deadband
HardwareDelayNmSec(5); //a little bit of time to let the chassis move if 
}
PDC1 = PDC2 = 0;
PTCON = 0;
}



void LocateAndExtinguish(void)
{

int TempAngle, TempDist;
 	LONG_THERMAL_ROOM_SCAN();	
	
	while(!WHITELINE) // Repeat until WhiteLine is found
	{
		RecordedAngle[RecordPointer] = SERVO_TURRET_ANGLE;
		SERVO_ADJUST_TURRET(0); //straight ahead 
		Turn(RecordedAngle[RecordPointer]);		
		RecordedDistance[RecordPointer++] = Forward_Dist_WL(1000);
		SHORT_THERMAL_ROOM_SCAN();
	}
	while(HOTSPOT != 3 && HOTSPOT != 4)
	{
		CANDLE_LOCATE();	// Locate and center on candle.
	}
	CANDLE_EXTINGUISH(); // Blow out candle and double check before leaving! 
}


void ReturnFromLocateAndExtinguish(void)	
{
	while(RecordPointer != 0)								// Loopback through the array until and return to starting point. 
	{
		Reverse_Dist(RecordedDistance[--RecordPointer]);
		HardwareDelayNmSec(100);
		Turn((-1 * RecordedAngle[RecordPointer]));
	}
	
	Turn(-90);	//Turn 180 degrees
	Turn(-90);
	
	if (HOTROOM ==1)
	{
			// Will probably need to adjust for code that enters room, etc. 
			
			Forward_Dist(500);
			HardwareDelayNmSec(100);
			Turn(-30);
			Forward_Dist(1200);
			HardwareDelayNmSec(100);

			Turn(90);
			Forward_Dist(5800);
			HardwareDelayNmSec(100);
	}
//			while(!WHITELINE)
//			{
//				Forward_Dist(100);
//				HardwareDelayNmSec(100);
//			}

	if (HOTROOM ==2)
	{			
			Forward_Dist(500);
			HardwareDelayNmSec(100);
			Turn(-30);
			Forward_Dist(1200);
			HardwareDelayNmSec(100);
			
			// Will probably need to adjust for code that enters room, etc. 
			Turn(-90);
			Forward_Dist(7500);
			HardwareDelayNmSec(100);
	}
//			while(!WHITELINE)
//			{
//				Forward_Dist(100);
//				HardwareDelayNmSec(100);
//			}
	if (HOTROOM ==3)
	{
			
			Forward_Dist(300);
			HardwareDelayNmSec(100);
			Turn(-30);
			Forward_Dist(1000);
			HardwareDelayNmSec(100);
	
			// Will probably need to adjust for code that enters room, etc.
			Turn(90);
			Forward_Dist(1900);
			HardwareDelayNmSec(100);
			Turn(90);
			Forward_Dist(4600);
			HardwareDelayNmSec(100);
}
//			while(!WHITELINE)
//			{
//				Forward_Dist(100);
//				HardwareDelayNmSec(100);
//			}
		if (HOTROOM ==4)
	{
			
			
			Forward_Dist(500);
			HardwareDelayNmSec(100);
			Turn(-30);
			Forward_Dist(1200);
			HardwareDelayNmSec(100);
			
			// Will probably need to adjust for cde taht enters room, etc. 
			Turn(-90);
			Forward_Dist(2500);
			HardwareDelayNmSec(100);
			Turn(-90);
			Forward_Dist(4200);
			HardwareDelayNmSec(100);
}
//			while(!WHITELINE)
//			{
//				Forward_Dist(100);
//				HardwareDelayNmSec(100);
//			}
		
	
	
	HardwareDelayNmSec(0xFFFF);	// Stop the processor from doing anything else. 	

}
