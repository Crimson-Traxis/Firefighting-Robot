//===============================================================================
// Universal Asynchronous Receiver Transmitter Functions
//===============================================================================
//

////////////////////////////////////////////////////////////////////////
// Function Prototypes
void UART_Config(void); 										
char UART_CHARNUM2INT(char Input);


////////////////////////////////////////////////////////////////////////
// Globals / Constants 
char UART_INPUT;


///////////////////////////////////////////////////////////////////////
// Interrupt: UART 1
// Note: Only complied if DEBUG is set. 
#if DEBUG>0
void __attribute__((__interrupt__)) _U1RXInterrupt(void)
{
	UART_INPUT = ReadUART1();		//Read current value
	printf("%c",UART_INPUT);		//Print value entered on the screen

	IFS0bits.U1RXIF = 0;			//Clear Interrupt bit
	return; 
}
#endif


/////////////////////////////////////////////////////////////////////////
// Functions
//-------------------------------------------------------------------------------
//UARTconfig -- This function configures UART 1. The UART is used for debugging
//via a telnet or other terminal window.
void UART_Config(void)
{
	U1MODE = 0;	
    U1MODEbits.STSEL = 0;           // 1-stop bit
    U1MODEbits.PDSEL = 0;           // No Parity, 8-data bits
    U1BRG = 15;
	U1MODEbits.UARTEN = 1;			//Enable UART
	U1STAbits.UTXEN = 1;			//Enable UART Transfer

	U1MODEbits.ALTIO = 0;			//Primary UART pins
	U1STAbits.URXISEL = 0;
	IEC0bits.U1RXIE = 0;			//Disable Interrupts
	return;
}

