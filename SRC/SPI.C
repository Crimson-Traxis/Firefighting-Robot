//===============================================================================
// SPI Communication
//===============================================================================
//
////////////////////////////////////////////////////////////////////////
// Function Prototypes
void SPI_Config(void);											//SPI
void SPI_Test(void);

////////////////////////////////////////////////////////////////////////
// Globals / Constants 


////////////////////////////////////////////////////////////////////////
// Interrupt: SPI2 
void __attribute__((__interrupt__)) _SPI2Interrupt(void)
{
	SPI2STATbits.SPIROV = 0; // Clear SPI2 receive overflow flag if set

	IFS1bits.SPI2IF = 0;	 // Clear SPI2 Interrupt Flag.
	return;
}

////////////////////////////////////////////////////////////////////////
// Functions
//-------------------------------------------------------------------------------
//SPI_Config -- This function configures the SPI registers. 
void SPI_Config(void)
{
	#if DEBUG>0
		printf("Loading SPI...");
	#endif
	
	//Clear register
	SPI2STAT = 0x0000;
	SPI2CON = 0x0000;
	TRISG |= 0x0080;

	//Configure SPI2 Control Register
	//SPI2CON |= %0100 0101 0111 1000 <--w/ Frame support
	//SPI2CON |= 0x4578;
	//SPI2CON |= 0x0738;
	SPI2CON |= 0x0720;
	SPI2STATbits.SPIEN = 1;		//Enable SPI

	#if DEBUG>0
		printf("DONE\r\n");
	#endif

	return;
}



void SPI_Test(void)
{
	int Result = 0, x=0;
	LATGbits.LATG9 = 0;
	int SPICONValue, SPISTATValue;
//	ConfigIntSPI2(SPI_INT_EN & SPI_INT_PRI_6);
/*	SPICONValue = FRAME_ENABLE_OFF & FRAME_SYNC_OUTPUT & ENABLE_SDO_PIN & SPI_MODE16_ON &
					SPI_SMP_ON & SPI_CKE_ON & SLAVE_ENABLE_OFF &
					CLK_POL_ACTIVE_HIGH & MASTER_ENABLE_ON & SEC_PRESCAL_8_1 &
					PRI_PRESCAL_64_1;
	SPISTATValue = SPI_ENABLE & SPI_IDLE_CON & SPI_RX_OVFLOW_CLR;
	OpenSPI2(SPICONValue,SPISTATValue );
*/


/*		DelayNmSec(10);
		LATGbits.LATG9 = 0;
		WriteSPI2(0x8300);
		while(SPI2STATbits.SPITBF);
		while(!DataRdySPI2());
		Result = SPI2BUF;
		LATGbits.LATG9 = 1; 
		printf("%x\r\n",Result);	
		DelayNmSec(10);
		LATGbits.LATG9 = 1;
		int i; 
*/
/*	while(1)
	{	
		DelayNmSec(25);
		LATGbits.LATG9 = 0;
		i=0;
		while(i<10)
		{
			i++;
		}
		WriteSPI2(0x8300);
		while(SPI2STATbits.SPITBF);
		while(!DataRdySPI2());
		i=0;
		while(i<10)
		{
			i++;
		}
		LATGbits.LATG9 = 1; 
		Result = ReadSPI2();
		printf("%x\r\n",Result);
	}
*/

	return;
}
