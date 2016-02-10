//===============================================================================
// I2C
//===============================================================================
//
////////////////////////////////////////////////////////////////////////
// Function Prototypes
void I2C_Master_Config(void);									//I2C


////////////////////////////////////////////////////////////////////////
// Globals / Constants 
int ReadError = 0;
int WriteError = 0;
unsigned int TESTREAD0 = 0;
unsigned int TESTREAD1 = 0;
word TESTREAD2 = 0;
word TESTREAD3 = 0;
word TESTREAD4 = 0;
word TESTREAD5 = 0;
word TESTREAD6 = 0;
word TESTREAD7 = 0;
#define THERMAL_ADDRESS 0xD0

////////////////////////////////////////////////////////////////////////
// Functions
//

void I2C_Master_Config(void)
{
	#if DEBUG>0
		printf("Loading I2C...");
	#endif

	unsigned int config1, config2;

	//config2 = 510; //slow as possible for debugging
	config2 = 272; //100kHz @ 30MIPS
	//config2 = 47; //400kHz @ 30MIPS
	//config2 = 20; //testing faster operation
					// the EEPROM can suposedly go to 1Mhz

	// Configure I2C for 7 bit address mode 
	config1 = (
	I2C_ON &
	I2C_IDLE_CON &
	I2C_CLK_HLD	&
	I2C_IPMI_DIS &
	I2C_7BIT_ADD &
	I2C_SLW_EN & //I2C_SLW_DIS & //slew rate control disabled
	I2C_SM_DIS &
	I2C_GCALL_DIS &
	I2C_STR_DIS	&
	I2C_NACK &
	I2C_ACK_EN &
	I2C_RCV_EN	&
	I2C_STOP_EN &
	I2C_RESTART_EN	&
	I2C_START_DIS);
	OpenI2C(config1,config2);

	
	#if DEBUG>0
		printf("DONE\r\n");

		char MemoryCheckResult = 0, LoopCount = 0;
		MemoryCheckResult = MemoryCheck();
		if(MemoryCheckResult != 0)
		{
			printf("Reading Thermal Array from I2C bus\r\n");
			for(LoopCount = 1; LoopCount < 10; LoopCount++)
			{
				TESTREAD0 = I2CReadWord(0xD0,LoopCount);
				printf("\tR%u-> %u\r\n",LoopCount,TESTREAD0);
			}
			printf("\r\n");
		}
		else
		{
			printf("\r\nERROR: Memory Check Failed\r\n");
			printf("Could not finish I2C test\r\n");
		}
		
	#endif


	//return;
                                                           
}
