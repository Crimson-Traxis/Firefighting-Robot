
// 8-Bit address and data read and write serial EEPROM functions
void I2CWriteByte(byte Device, word Address, byte Data );   // Write a byte to the serial EEPROM works !!!!
byte I2CReadByte(byte Device, byte Address ); // Write a byte to the serial EEPROM

// 16-Bit address and 8-Bit data read and write serial EEPROM functions
void I2CWriteWord(byte Device, word Address, byte Data);
unsigned int I2CReadWord(byte Device, word Address);


int MemoryCheck(void)
{
	bit Test = 0;
	unsigned char MyByte;
	char DataAddress = 0xD0, i=1;

	//Read Byte from Chip Address
	MyByte = 0xFF; //just proof that it's coming out of the EEPROM
	printf("Reading data at %x register %u\r\n", DataAddress, i);
	MyByte = I2CReadWord(DataAddress, i); //655 inst
	printf("Received Value: %u\r\n",MyByte);

	return 1;
}


// ******************************************************************************
// * I2CWriteWord - Writes a byte to large 24LCXXX serial EEPROM(s).  
// *****************************************************************************
void I2CWriteWord(byte Device, word Address, byte Data)
{
  
	// Ensure I2C module is idle
	IdleI2C(); 

	// Transmit a Start condition
	StartI2C();

	// Wait till Start sequence is completed 
	while(I2CCONbits.SEN)
	{
		//nothing
	}

	// Ensure I2C module is idle
	IdleI2C(); 

	// Write Slave device address and set master for transmission  (R/W bit should be 0)
	MasterWriteI2C(Device);

	// Wait till address is transmitted 
	while(I2CSTATbits.TBF)
	{
		//nothing
	}

	// Test for ACK condition received           
	while(I2CSTATbits.ACKSTAT)
	{
		//nothing
	}

	// Ensure I2C module is idle 
	IdleI2C(); 

	// Write low byte of word address for serial EEPROM  
	MasterWriteI2C((Address & 0xff) );

	// Wait till address is transmitted 
	while(I2CSTATbits.TBF)
	{
		//nothing
	}
	
	// Test for ACK condition received           
	while(I2CSTATbits.ACKSTAT)
	{
		//nothing
	}

	// Ensure I2C module is idle
	IdleI2C(); 

	// Write data byte to serial EEPROM  
	MasterWriteI2C(Data);

	// Wait till address is transmitted 
	while(I2CSTATbits.TBF)
	{
		//nothing
	}

	// Ensure I2C module is idle
	IdleI2C(); 

	// send STOP condition //EEPROM's internal write timer starts now
	StopI2C();  

	// Wait till Stop sequence is completed  
	while(I2CCONbits.PEN)
	{
		//nothing
	}

	// Ensure I2C module is idle
	IdleI2C(); 

	return;
}




// ******************************************************************************
// * I2CReadWord - Reads a 16-Bit word from large 24LCXXX serial EEPROM(s).  
// ******************************************************************************
unsigned int I2CReadWord(byte Device, word Address)
{
	word Data = 0;
	int x =0;
	// Ensure I2C module is idle
	IdleI2C(); 

	// Transmit a Start condition
	StartI2C();

	// Wait till Start sequence is completed 
	while(I2CCONbits.SEN);

	// Write Slave address and set master for transmission  (R/W bit should be 0)
	MasterWriteI2C(Device);

	// Wait till address is transmitted 
	while(I2CSTATbits.TBF);

    //Test for ACK condition received           
	while(I2CSTATbits.ACKSTAT);

	// Ensure I2C module is idle 
	IdleI2C();  

	// Write low byte of data word address for serial EEPROM  
	MasterWriteI2C((Address & 0xff) );

	// Wait till address is transmitted 
	while(I2CSTATbits.TBF);

	// Test for ACK condition received           
	while(I2CSTATbits.ACKSTAT);  ///////didn't get an ack after the second address byte

	// Ensure I2C module is idle
	IdleI2C(); 

	// Generate the I2C bus restart condition
	RestartI2C();   

	// Wait until re-start condition is over      
	while (I2CCONbits.RSEN);

	// Write Slave address and set master for reception  (R/W bit should be 1)
	MasterWriteI2C( Device+1 );

	// Wait till address is transmitted 
	while(I2CSTATbits.TBF)

	// Test for ACK condition received            
	while(I2CSTATbits.ACKSTAT);

	// Ensure I2C module is idle
	IdleI2C(); 

	// Read the data byte
	Data = MasterReadI2C();

	// Ensure I2C module is idle
	IdleI2C(); 

	// send NACK condition back to the I2C slave indicating master received the data byte
	NotAckI2C(); 
       
	// wait until NACK sequence is over
	while ( I2CCONbits.ACKEN );

	// Ensure I2C module is idle
	IdleI2C(); 

	// send STOP condition
	StopI2C();  

	// Wait till Stop sequence is completed  
	while(I2CCONbits.PEN);

	// Ensure I2C module is idle
	IdleI2C(); 

  	return ( Data );     // return with data

}


// ******************************************************************************
// *     Function Name:    I2CReadByte                                          *
// *     Return Value:     error condition status                               *
// *     Parameters:       EE memory device control, address and data           *
// *                       bytes.                                               *
// *     Description:      Write single data byte to I2C EE memory              *
// *                       device. This routine can be used for any I2C         *
// *                       EE memory device, which uses 2 bytes of              *
// *                       address data as in the 24LC32A/64A/256A.             *
// *                                                                            *  
// ******************************************************************************

byte I2CReadByte ( byte Device, byte Address )
{
	byte Data = 0;

	// Ensure I2C module is idle
	IdleI2C(); 

	// Transmit a Start condition
	StartI2C();

	// Wait till Start sequence is completed 
	while(I2CCONbits.SEN );

	// Write Slave address and set master for transmission  (R/W bit should be 0)
	MasterWriteI2C(Device);

	// Wait till address is transmitted 
	while(I2CSTATbits.TBF);

    // Test for ACK condition received           
	while(I2CSTATbits.ACKSTAT);

	// Ensure I2C module is idle 
  	//IdleI2C(); 

	// Write word address for serial EEPROM  
	MasterWriteI2C(Address);

	// Wait till address is transmitted 
	while(I2CSTATbits.TBF);

    // Test for ACK condition received           
	while(I2CSTATbits.ACKSTAT);

	// Ensure I2C module is idle
	//IdleI2C(); 

	// Generate the I2C bus restart condition
    RestartI2C();   

    // Wait until re-start condition is over      
    while (I2CCONbits.RSEN);

	// WWrite Slave address and set master for reception  (R/W bit should be 1)
	MasterWriteI2C( Device+1 );

	// Wait till address is transmitted 
	while(I2CSTATbits.TBF);

	// Ensure I2C module is idle
	//IdleI2C(); 

    // Test for ACK condition received           
	while(I2CSTATbits.ACKSTAT);

	// Ensure I2C module is idle
	//IdleI2C(); 

	// Read the data byte

    Data = MasterReadI2C();

	// Ensure I2C module is idle
	//IdleI2C(); 

	// send NACK condition back to the I2C slave indicating master received the data byte
    NotAckI2C(); 

    // wait until NACK sequence is over
    while (I2CCONbits.ACKEN); 

	// Ensure I2C module is idle
	//IdleI2C(); 

	// send STOP condition
    StopI2C();  

  	// Wait till Stop sequence is completed  
	while(I2CCONbits.PEN);

	// Ensure I2C module is idle
	IdleI2C(); 

  	return ( Data );     // return with data
}




// ******************************************************************************
// *     Function Name:    I2CWriteByte                                         *
// *     Return Value:     error condition status                               *
// *     Parameters:       EE memory device control, address and data           *
// *                       bytes.                                               *
// *     Description:      Write single data byte to I2C EE memory              *
// *                       device. This routine can be used for any I2C         *
// *                       EE memory device, which uses 2 bytes of              *
// *                       address data as in the 24LC32A/64A/256A.             *
// *                                                                            *  
// ******************************************************************************
void I2CWriteByte( byte Device, word Address, byte Data )
{
  
	// Ensure I2C module is idle
	IdleI2C(); 

	// Transmit a Start condition
	StartI2C();

	// Wait till Start sequence is completed 
	while(I2CCONbits.SEN );

	// Ensure I2C module is idle
	IdleI2C(); 

	// Write Slave address and set master for transmission  (R/W bit should be 0)
	MasterWriteI2C(Device);

	// Wait till address is transmitted 
	while(I2CSTATbits.TBF);
   
    // Test for ACK condition received           
	while(I2CSTATbits.ACKSTAT);

	// Ensure I2C module is idle
	IdleI2C(); 

	// Write word address for serial EEPROM  
	MasterWriteI2C(Address);

	// Wait till address is transmitted 
	while(I2CSTATbits.TBF);

    // Test for ACK condition received           
	while(I2CSTATbits.ACKSTAT);

	// Ensure I2C module is idle
	IdleI2C(); 

	// Write data byte to serial EEPROM  
	MasterWriteI2C(Data);

	// Wait till address is transmitted 
	while(I2CSTATbits.TBF);

	// Ensure I2C module is idle
	IdleI2C(); 

	// send STOP condition
    StopI2C();  

  	// Wait till Stop sequence is completed  
	while(I2CCONbits.PEN);

	// Ensure I2C module is idle
	IdleI2C(); 

}

