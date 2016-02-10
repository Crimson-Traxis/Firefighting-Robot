//===============================================================================
// Movement Control
//===============================================================================
// Uses : 	dsp.h
//			pidwDSPcommon.s
//			TIMERS.c
//			PWM.c
//			QEI.c
//			PID.c

//**********************************************************************************************//
// Function Prototypes																			//
//**********************************************************************************************//
void Forward_Dist_WL(int X);
int DistanceCalc(void);

void Forward_Dist(int X);
void Turn(int X);
void Reverse_Dist(int X);
void Forward_Dist_WL(int X);
//**********************************************************************************************//
// Globals / Constants 																			//
//**********************************************************************************************//
#define pi 3.1416
#define WheelDiameter 3.95
#define EncoderCountPerRev	1200
#define FrontWheelSeperation 6.625
#define CountDistance (EncoderCountPerRev/(WheelDiameter*pi))  //1200 counts/(dia.*pi)
#define TurnCountPerDegree (FrontWheelSeperation*pi*CountDistance/360)  //TurnDia.*pi*CountPERinch/(360degrees)

#define RAMP_STEP_FRONT_MOTORS 0.05
#define RAMP_THRESHOLD 0.20
#define RAMP_DOWN_THRESHOLD 0.20
#define RAMP_DOWN_MIN RAMP_DOWN_THRESHOLD*PTPER
#define MC_REAR_MOTOR_OFFSET 0.90
#define RAMP_STEP_REAR_MOTOR (RAMP_STEP_FRONT_MOTORS * MC_REAR_MOTOR_OFFSET)

//**********************************************************************************************//
// Functions																					//
//**********************************************************************************************//

int DistanceCalc(void)
{
	;
}

void Forward_Dist(int X)
{
	;
}
void Turn(int X)
{
	;
}
void Reverse_Dist(int X)
{
	;
}
void Forward_Dist_WL(int X)
{
	;
}
