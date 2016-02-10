//===============================================================================
// Timer Functions
//===============================================================================
//
////////////////////////////////////////////////////////////////////////
// Function Prototypes

void TMR1_Config(int PrescaleValue, int MaxCount);				// Timer Configurations
void TMR2_Config(int PrescaleValue, int MaxCount);				// 
void TMR3_Config(int PrescaleValue, int MaxCount); 				// 
void TMR4_Config(int PrescaleValue, int MaxCount);				//
void TMR5_Config(int PrescaleValue, int MaxCount);				//

////////////////////////////////////////////////////////////////////////
// Globals / Constants 
long T1Cycles;
int TIMER5_COUNT = 0;


////////////////////////////////////////////////////////////////////////
// Functions
//
//---------------------------------------------------------------------
// InitTMR1 -- This subroutine will initialize the Timer 1 for periodic interrupts. 
void TMR1_Config(int PrescaleValue, int MaxCount)
{
	#if DEBUG>0
		printf("Starting Timer 1...");
	#endif

	TMR1 = 0x0000;			// Clear Timer1
	PR1 = MaxCount;			// Number of counts before the interrupt is called.
	T1CON = PrescaleValue;	// 1:256 Prescale Value and enables the timer.
	T1Cycles = (long)(PR1)*256;

	IFS0bits.T1IF = 0;		// Clear interrupt flag
	IEC0bits.T1IE = 1;		// Enable T1 interrutps
	IPC0bits.T1IP = 0x4;	// Sets interrupt prioirty to 3 out of 7. 
	
	#if DEBUG>0
		printf("DONE\r\n");
	#endif

	return;
}

//---------------------------------------------------------------------
// InitTMR2 -- This subroutine will initialize the Timer 2 for periodic 
// interrupts. During the interrupt, the 3 servos will be adjusted to 
// hold their present position or change to a new position. 
//
//    |----------- 50+ Hz -------------|
//	  |- 2ms -|
//     ________
// ___| S1     |_______________________|
//               ______
// _____________|  S2  |_______________
//                        ____
//_______________________| S3 |________
void TMR2_Config(int PrescaleValue, int MaxCount)
{
	#if DEBUG>0
		printf("Loading Timer 2...");
	#endif

	TMR2 = 0x0000;			// Clear Timer1
	PR2 = MaxCount;			// Number of counts before the interrupt is called.
	T2CON = PrescaleValue;	// 1:256 Prescale Value and enables the timer.
	
	IFS0bits.T2IF = 0;		// Clear interrupt flag
	IEC0bits.T2IE = 1;		// Enable T1 interrutps
	IPC1bits.T2IP = 0x5;	// Sets interrupt prioirty to 3 out of 7. 

	#if DEBUG>0
		printf("DONE\r\n");
	#endif

	return;
}

//---------------------------------------------------------------------
// InitTMR3 -- This subroutine will initialize the Timer 3 used for IC 
// timings. 
void TMR3_Config(int PrescaleValue, int MaxCount)
{
	#if DEBUG>0
		printf("Loading Timer 3...");
	#endif

	TMR3 = 0x0000;			// Clear Timer3
	PR3 = MaxCount;			// Number of counts before the interrupt is called.
	T3CON = PrescaleValue;	// 1:256 Prescale Value and enables the timer.
	
	IFS0bits.T3IF = 0;		// Clear interrupt flag
	IEC0bits.T3IE = 1;		// Enable T3 interrutps
	IPC1bits.T3IP = 0x5;	// Sets interrupt prioirty to 3 out of 7. 

	#if DEBUG>0
		printf("DONE\r\n");
	#endif

	return;
}

//---------------------------------------------------------------------
// InitTMR4 -- This subroutine will initialize the Timer 4 for the
// Ramping functions
void TMR4_Config(int PrescaleValue, int MaxCount)
{
	#if DEBUG>0
		printf("Loading Timer 4...");
	#endif

	TMR4 = 0x0000;			// Clear Timer3
	PR4 = MaxCount;			// Number of counts before the interrupt is called.
	T4CON = PrescaleValue;	// 1:256 Prescale Value and enables the timer.
	
	IFS1bits.T4IF = 0;		// Clear interrupt flag
	IEC1bits.T4IE = 1;		// Enable T3 interrutps
	IPC5bits.T4IP = 0x3;	// Sets interrupt prioirty to 3 out of 7. 

	#if DEBUG>0
		printf("DONE\r\n");
	#endif

	return;
}

//---------------------------------------------------------------------
// TMR5_Config -- Configures Timer 5 for 'heartbeat' or for cyclic 
// interrupts for status flags and other bits. 
void TMR5_Config(int PrescaleValue, int MaxCount)
{
	#if DEBUG>0
		printf("Loading Timer 5...");
	#endif

	TMR5 = 0x0000;			// Clear Timer5
	PR5 = MaxCount;			// Number of counts before the interrupt is called.
	T5CON = PrescaleValue;	// 1:256 Prescale Value and enables the timer.
	
	IFS1bits.T5IF = 0;		// Clear interrupt flag
	IEC1bits.T5IE = 1;		// Enable T3 interrutps
	IPC5bits.T5IP = 0x3;	// Sets interrupt prioirty to 3 out of 7. 

	#if DEBUG>0
		printf("DONE\r\n");
	#endif

	return;
}
