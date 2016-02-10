//===============================================================================
// PID Control
//===============================================================================
//
////////////////////////////////////////////////////////////////////////
// Function Prototypes
void PID_Config(void);											//PID setup
void PIDInit(tPID *PIDStruct);									//
void PIDCoeffCalc(fractional *PIDGainCoeff, tPID *PIDStruct);	//
//extern void PID(tPID *PIDStruct);

////////////////////////////////////////////////////////////////////////
// Globals / Constants 

/*
Variable Declaration required for each PID controller in your application
*/
/* Declare PID Data Structures named, positionPID, diffPID */
tPID diffPID;
/* The positionPID, diffPID data structures contain pointers to derived coefficients in X-space */
/* and pointer to controler state (history) samples in Y-space. So declare variables for the */
/* derived coefficients and the controller history samples */
fractional position_abcCoefficient[3] __attribute__ ((section (".xbss, bss, xmemory")));
fractional position_controlHistory[3] __attribute__ ((section (".ybss, bss, ymemory")));
fractional diff_abcCoefficient[3] __attribute__ ((section (".xbss, bss, xmemory")));
fractional diff_controlHistory[3] __attribute__ ((section (".ybss, bss, ymemory")));
/* The abcCoefficients referenced by the positionPID and speedPID data structures */
/* are derived from the gain coefficients, Kp, Ki and Kd */
/* So, declare Kp, Ki and Kd in an array */
fractional diff_kCoeffs[] = {0,0,0};


////////////////////////////////////////////////////////////////////////
// Functions
//

void PID_Config(void)
{
	#if DEBUG>0
		printf("Loading PID Control...");
	#endif

/* Step 1: Initialize the PID data structure, diffPID */
        diffPID.abcCoefficients = &position_abcCoefficient[0];    /*Set up pointer to derived coefficients */
        diffPID.controlHistory = &position_controlHistory[0];     /*Set up pointer to controller history samples */
        PIDInit(&diffPID);                               /*Clear the controler history and the controller output */
	diff_kCoeffs[0] = Q15(0.8);//0.94		//P
	diff_kCoeffs[1] = Q15(0.015);//0.011);		//I
	diff_kCoeffs[2] = Q15(0);//-0.80);	//D
        PIDCoeffCalc(&diff_kCoeffs[0], &diffPID);             /*Derive the a,b, & c coefficients from the Kp, Ki & Kd */
		diffPID.measuredOutput = Q15(0);	


	#if DEBUG>0
		printf("DONE\r\n");
	#endif

	return;
}
