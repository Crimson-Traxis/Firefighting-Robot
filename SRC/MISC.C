//===============================================================================
// Misc Functions
//===============================================================================
//
////////////////////////////////////////////////////////////////////////
// Function Prototypes
void DelayNmSec(unsigned int N);								// Misc
void HardwareDelayNmSec(unsigned int N);
void BlinkLed(int x);
////////////////////////////////////////////////////////////////////////
// Functions
//
//---------------------------------------------------------------------
// DelayNmSec -- This is a generic 1ms delay routine to give a 1mS to 65.5 Seconds delay
// For N = 1 the delay is 1 mS, for N = 65535 the delay is 65,535 mS. 
// Note that FCY is used in the computation.  Please make the necessary
// Changes(PLLx4 or PLLx8 etc) to compute the right FCY as in the define
// statement above. This function will be used in the code for giving the 
// user up to 5 secs to enter service mode. 
//
// WARNING: THIS IS ONLY USED FOR DEVELOPMENT!!!! 
// This will keep the processor counting clock cycles until the function
// is completed.

void DelayNmSec(unsigned int N)
{
	unsigned int j;
	while(N--)
	 	for(j=0;j < MILLISEC;j++);
	return;
}


//Software delay (above) changes depending on background interrupt activities
//timer based solution does not

//NOTE this is still a blocking function - the proccessor does nothing but wait
// but the hardware version will be a more consistant delay even with 
// background interrupt tasks

//NOTE requires a timer to increment TIMER5_COUNT once per millisecond
// (currently done with timer 5)

void HardwareDelayNmSec(unsigned int N)
{
TIMER5_COUNT = 0;
while (TIMER5_COUNT < N)
	{
		;//do nothing
	}
return;
}


void BlinkLed(int x)
{
int j;
for(j=0;j < x;j++)
{
LATFbits.LATF6 = 1;
HardwareDelayNmSec(100);
LATFbits.LATF6 = 0;
HardwareDelayNmSec(100);
}
}
