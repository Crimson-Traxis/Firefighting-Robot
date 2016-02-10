//===============================================================================
// Quadrature Encoder Interface Functions
//===============================================================================
//
////////////////////////////////////////////////////////////////////////
// Function Prototypes
void QEI_Config(void);											//QEI
void QEI_Software_Config(void);									//

////////////////////////////////////////////////////////////////////////
// Globals / Constants 
unsigned int QEIS_PREVB = 0, QEIS_COUNTER = 1000, QEIS_COUNTER_MAX = 1000;
unsigned int QEIH_COUNTER = 1000, QEIH_COUNTER_MAX = 1000;


////////////////////////////////////////////////////////////////////////
// Interrupt: QEI
// ----
void __attribute__((__interrupt__)) _QEIInterrupt(void)
{
//	STOP();
	IFS2bits.QEIIF = 0;		//Clear Interrupt Flag
}

////////////////////////////////////////////////////////////////////////
// Functions
//
//----------------------------------------------------------------------
// QEIConfig: This function configures the Quadrature Encoder Interface 
// for one of the wheels. 
void QEI_Config(void)
{
	#if DEBUG>0
		printf("Loading QEI Hardware Config...");
	#endif

	//Clear registry values
	QEICON = 0x0000;
	DFLTCON = 0x0000;

	TRISB |= 0x0030;
	ADPCFG |= 0x0030;

	//Configure registers
	QEICON = 0x0780;
	DFLTCON = 0x0100;

	//Clear position count register
	POSCNT = 1000;
	
	//Set Max count register to max value
	MAXCNT = 0xFFFF;
	
	IFS2bits.QEIIF = 0;		//Clear Interrupt flag
	IEC2bits.QEIIE = 1;		//Enable interrupts

	#if DEBUG>0
		printf("DONE\r\n");
	#endif
	
	return;
}
//----------------------------------------------------------------------
// QEI_Software_Config: This function configures the two capture pings 
// to create another QEI interface via software. 
void QEI_Software_Config(void)
{
	#if DEBUG>0
		printf("Loading QEI Software Config...");
	#endif

	//Modify TRISC to enable the pins as inputs
	TRISC |= 0x6000;

	//Set Register value to enable interrupt
	CNEN1 = 0x0003;
	CNPU1 = 0x0000; //No pullup 	
	
	IFS0bits.CNIF = 0; //Clear INT flag
	IEC0bits.CNIE = 1; //Enable Interrupts
	IPC3bits.CNIP = 7; //High Interrupt.

	#if DEBUG>0
		printf("DONE\r\n");
	#endif

	return;
}
