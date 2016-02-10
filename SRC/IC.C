//===============================================================================
// Input Capture Functions
//===============================================================================
//
////////////////////////////////////////////////////////////////////////
// Function Prototypes
void IC1_Config(void);											//IC
int UVCheck(void);

////////////////////////////////////////////////////////////////////////
// Globals / Constants 
char ACTIVE_SONAR = 1;
char IC_PASS = 0;
char SONAR_PULSE_SELECT = 1;
int SONAR_PULSE = 9;
int SONAR_DELAY_PULSE = 0;	// 40Hz on the 64 prescale timer. 
#define SONAR_40Hz 18425

int SONAR_REAR = 0, SONAR_FRONT = 0, SONAR_TURRET = 0;
int Current_Sonar = 0;

int TMR3_MAX = 0xFFFF;
char TMR3_PASS = 0;

int UV_ROOM_FOUND = 0;
int UVCheckProgress = 0;
int UVCount = 0;

////////////////////////////////////////////////////////////////////////
// Functions
//---------------------------------------------------------------------
//IC1Setup -- This function configures the Input Capture 1 register. During 
//execution of the code, the setup for each IC will change depending on the current
//state.
void IC1_Config(void)
{
	#if DEBUG>0
		printf("Loading Interrupt Capture...");
	#endif

	//Enable IC1, Interrupt on, Pri to 6
	ConfigIntCapture1(IC_INT_PRIOR_6 & IC_INT_ON);
	ConfigIntCapture3(IC_INT_PRIOR_6 & IC_INT_ON);
	
	//Configuration options
	//----Idle while in stop
	//----Use Timer 3 as timing source
	//----Interrupt on the first capture
	//----Capture on every edge 
	OpenCapture1(IC_IDLE_STOP & IC_TIMER3_SRC & IC_INT_1CAPTURE & IC_EVERY_EDGE);
	OpenCapture3(IC_IDLE_STOP & IC_TIMER3_SRC & IC_INT_1CAPTURE & IC_EVERY_FALL_EDGE);

	#if DEBUG>0
		printf("DONE\r\n");
	#endif

	return;

} 
/*
int UVCheck(void)
{
	TIMER5_COUNT = 0; //Clear the timer. 
	TMR5 = 0;
	UVCount = 0;
	UVCheckProgress = 1;	// This will allow the function to lock again when it is called. 
	while(UVCheckProgress);
		// do nothing for two seconds. HORRIBLE, but it is the only way to get consistant data
		// out of the -------F * * * I N G------ sensor. arggghhh!!!!!!!!!!!!!!
		
	if(UVCount > 2)
	{
		UV_ROOM_FOUND = 1;			// Check to see if the room is filled with UV
		///////////////////////////////
		printf("Found|%u\r\n",UVCount);
		///////////////////////////////
	}
	else
	{
		UV_ROOM_FOUND = 0;
		///////////////////////////////////
		printf("Not Found|%u\r\n",UVCount);
		///////////////////////////////////
	}	
	
	UVCheckProgress = 1;	// This will allow the function to lock again when it is called. 
	UVCount = 0;			// Clear counts
	
	return;	
}*/

int UVCheck(void) 
{
	UVCount = 0;
	//HardwareDelayNmSec(3000); //wait for a second of interrupt proccessing
	TIMER5_COUNT = 0;
while ((UVCount < 2) && (TIMER5_COUNT < 3000))
	{
	;
	}
	if(UVCount > 1)
	{
		return true;
	}
	else
	{
		return false;
	}		
}
