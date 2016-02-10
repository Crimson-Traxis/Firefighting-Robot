//===============================================================================
// Servo Control Functions
//===============================================================================
//
////////////////////////////////////////////////////////////////////////
// Function Prototypes
void SERVO_ADJUST_TURRET(int Angle);
void SERVO_ENABLE_CO2(char Mode);


////////////////////////////////////////////////////////////////////////
// Globals / Constants 

int SERVO_50Hz = 9213;	//Timer period value for 50 Hz
char ACTIVE_SERVO = 0;	// Switch for active servo. See Interrupt routine for more details
int SERVO_DEAD_TIME = 0;

#define SERVO_CO2_ON 1116	//Servo timings for CO2 On/Off
#define SERVO_CO2_OFF 391	//

int SERVO_TURRET_POS = 741;  		// Position Variables for turret servos
int SERVO_TURRET_ANGLE = 0;			// 741 => Center Position

int SERVO_THERMAL_POS = 0;			// Variable for Thermal position.

int SERVO_CO2_POS = SERVO_CO2_OFF;	//Servo starting postion

#if DEBUG>0
	char SERVO_DEBUG_DIR_RIGHT[] = "right";	// Used for debugging.
	char SERVO_DEBUG_DIR_LEFT[] = "left";	//
#endif

////////////////////////////////////////////////////////////////////////
// Functions

//----------------------------------------------------------------------
// Servo Adjust Turret -- This function takes the angle desired and 
// calculates the time that is requried for the pulse length pulse.
void SERVO_ADJUST_TURRET(int Angle)
{
	float temp = 0;
	temp = (Angle + 177.84) / 0.24;	 // Calculates new timer value
	SERVO_TURRET_POS = temp;		//Stores new position
	SERVO_TURRET_ANGLE = Angle; 	// Stores the requested angle

	return;
}

//----------------------------------------------------------------------
// Servo Adjust CO2 -- This function sets the timer value to turn the 
// Co2 servo on or off. 
// 1 -> Co2 On
// 0 -> Co2 Off
void SERVO_ENABLE_CO2(char Mode)
{
	switch(Mode)
	{
		case 0:
			SERVO_CO2_POS = SERVO_CO2_OFF;
		break;
		case 1:
			SERVO_CO2_POS = SERVO_CO2_ON;
		break;
	};

	return;
}


