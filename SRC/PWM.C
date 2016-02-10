//===============================================================================
// PWM Functions
//===============================================================================
//
////////////////////////////////////////////////////////////////////////
// Function Prototypes
void PWM_Config(void);											// PWM setup
void PWM_Update(char Mode);

////////////////////////////////////////////////////////////////////////
// Globals / Constants 
#define MOTOR_LF *(unsigned int volatile *)(&PDC1) 		//Left Front
#define MOTOR_RF *(unsigned int volatile *)(&PDC2) 		//Right Front
#define MOTOR_REAR *(unsigned int volatile *)(&PDC4)	//Rear

#define PWM_UpdateOn	asm("BCLR PWMCON2,#0")
#define PWM_UpdateOff	asm("BSET PWMCON2,#0")

////////////////////////////////////////////////////////////////////////
// Functions
//
//---------------------------------------------------------------------
// InitPWMSetup -- This subroutine will initialize the PWM 
void PWM_Config(void)
{
	#if DEBUG>0
		printf("Loading PWM...");
	#endif

	PTCON = 0;
	PTMR = 0x0000;
	PTPER = 5000;
	SEVTCMP = 0;
	PWMCON1 = 0x0F0F;
	PWMCON2 = 0;
	DTCON1 = 0;
	DTCON2 = 0;
	FLTACON = 0;
	FLTBCON = 0;
	OVDCON = 0x5500;
	PDC1 = 0;
	PDC2 = 0;
	PDC3 = 0;
	PDC4 = 0;

	IEC2bits.PWMIE = 0;
//	PTCON = 0x8000;
	
	#if DEBUG>0
		printf("DONE\r\n");
	#endif

	return;
}

//---------------------------------------------------------------------
// PWM_Update -- This function will turn the update mode on or off
// on the PWM. 1 for on, 0 for off.  
void PWM_Update(char Mode)
{
	switch(Mode)
	{
		//Turn off PWM updates
		case 0:
			PWMCON2bits.UDIS = 1;		//Enables the lockout
		break;
		case 1:
			PWMCON2bits.UDIS = 0;		//Disables the lockout
		break;
	};
	
	return;		 
}
