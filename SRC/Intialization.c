//===============================================================================
// Intialization
//===============================================================================
//
////////////////////////////////////////////////////////////////////////
// Function Prototypes
void Initialize(void);							//Init ports and settings

////////////////////////////////////////////////////////////////////////
// Functions
void Initialize(void)
{
	///////////////////////////////////////////
	// I/O Port Configurations
	
	//Port B
	PORTB = 0;
	//TRISB = 0;
	TRISB = 0x4000;
	
	//Port C
	PORTC = 0;
	TRISC = 0;

	//Port D
	PORTD = 0;
  
// 0000 0101 0000 0000
	TRISD = 0x0500;

	//Port E
	PORTE = 0;
	TRISE = 0;

	//Port F
	PORTF = 0;
	TRISF = 0;
	LATFbits.LATF6 = 0; // Turn on Status LED

	//Port G
	PORTG = 0;
	TRISG = 0;

	///////////////////////////////////////////
	//Configure UART
	UART_Config();

	///////////////////////////////////////////
	// A/D Converter
	ADC_Config(); 	// Configure and enable A/D Converter 

	///////////////////////////////////////////
	// QEI Configuration
	QEI_Config();			//Hardware
	QEI_Software_Config();	//Software

	///////////////////////////////////////////
	//PID Control Configuration
//	PID_Config();

	///////////////////////////////////////////
	// Pulse Width Modulation 
	PWM_Config();
	
	///////////////////////////////////////////
	//Timer Configuration
//	TMR1_Config(0x8030, 5758);	//Start TIMER 1 with a prescale of 256
	TMR2_Config(0x8020, 46);	//
	TMR3_Config(0x8020, 921);
//	TMR4_Config(0x0030, 5758);
	TMR5_Config(0x8020, 461);	//

	///////////////////////////////////////////
	// Interrupt Capture 
	IC1_Config();
	
	///////////////////////////////////////////
	//Configure I2C
	I2C_Master_Config(); 
	
	// Check for the I2C
	int MemoryCheckResult = 0;
	/////////////////////////////
	DelayNmSec(500);
	
	MemoryCheckResult = MemoryCheck();
	if (MemoryCheckResult == 0)
	{
		while(1)
		{
			LATFbits.LATF6 = 0;
			DelayNmSec(500);
			LATFbits.LATF6 = 1;
			DelayNmSec(500);
		}		
	}	
	
	I2CWriteWord(THERMAL_ADDRESS,0,19); //Center Thermal Array

	return;
}
