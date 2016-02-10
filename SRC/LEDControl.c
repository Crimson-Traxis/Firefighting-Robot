//===============================================================================
// LED Control
//===============================================================================
//
////////////////////////////////////////////////////////////////////////
// Function Prototypes
void LED_Turret(char Mode);

////////////////////////////////////////////////////////////////////////
// Global / Constants
int LED_TURRET_OFF = 0;
int LED_TURRET_SLOW = 507;
int LED_TURRET_FAST = 829; 
int LED_TURRET_MODE = 829;

#define boardLED_ON asm("BSET LATF,#6");
#define boardLED_OFF asm("BCLR LATF,#6");

////////////////////////////////////////////////////////////////////////
// Functions

//-------------------------------------------------------------------------------
// LED_Turret -- This function will change the settings based on the input from
// the function call. 
void LED_Turret(char Mode)
{
	switch(Mode)
	{
		case 0: 
			LED_TURRET_MODE = LED_TURRET_SLOW;
			LED_TURRET_OFF = 1;
		break;
		case 1:
			LED_TURRET_MODE = LED_TURRET_SLOW;
			LED_TURRET_OFF = 0;	
		break;
		case 2: 
			LED_TURRET_MODE = LED_TURRET_FAST;
			LED_TURRET_OFF = 0;
		break;
		default:
			LED_TURRET_MODE = LED_TURRET_SLOW;	// Incase of invalid input
			LED_TURRET_OFF = 0;
		break;
	};

	return;
}
