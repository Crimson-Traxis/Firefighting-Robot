/********************************************************************/
/*              Header for SPI module library functions             */
/********************************************************************/
#ifndef __SPI_H
#define __SPI_H

/* List of SFRs for SPI */
/* This list contains the SFRs with default (POR) values to be used for configuring SPI */
/* The user can modify this based on the requirement */

#define SPI1STAT_VALUE         0x0000
#define SPI2STAT_VALUE         0x0000
#define SPI1BUF_VALUE          0x0000
#define SPI2BUF_VALUE          0x0000



 
#if defined(__dsPIC33FJ64GP206__) || defined(__dsPIC33FJ64GP306__) || defined(__dsPIC33FJ64GP310__) || defined(__dsPIC33FJ64GP706__) || \
	defined(__dsPIC33FJ64GP708__) || defined(__dsPIC33FJ64GP710__) || defined(__dsPIC33FJ128GP206__) || defined(__dsPIC33FJ128GP306__) || \
	defined(__dsPIC33FJ128GP310__) || defined(__dsPIC33FJ128GP706__) || defined(__dsPIC33FJ128GP708__) || defined(__dsPIC33FJ128GP710__) || \
	defined(__dsPIC33FJ256GP506__) || defined(__dsPIC33FJ256GP510__) || defined(__dsPIC33FJ256GP710__) || defined(__dsPIC33FJ64MC506__) || \
	defined(__dsPIC33FJ64MC508__) || defined(__dsPIC33FJ64MC510__) || defined(__dsPIC33FJ64MC706__) || defined(__dsPIC33FJ64MC710__) || \
	defined(__dsPIC33FJ128MC506__) || defined(__dsPIC33FJ128MC510__) || defined(__dsPIC33FJ128MC706__) || defined(__dsPIC33FJ128MC708__) || \
	defined(__dsPIC33FJ128MC710__) || defined(__dsPIC33FJ256MC510__) || defined(__dsPIC33FJ256MC710__) ||defined(__PIC24HJ64GP206__) || \
    defined(__PIC24HJ64GP210__) || defined(__PIC24HJ64GP506__) || defined(__PIC24HJ64GP510__) || defined(__PIC24HJ128GP206__) || \
   	defined(__PIC24HJ128GP210__) || defined(__PIC24HJ128GP506__) || defined(__PIC24HJ128GP510__) || defined(__PIC24HJ128GP306__) || \
	defined(__PIC24HJ128GP310__) || defined(__PIC24HJ256GP206__) || defined(__PIC24HJ256GP210__) || \
	defined(__PIC24HJ256GP610__) 

	#define SPI1CON1_VALUE          0x0000
	#define SPI2CON1_VALUE          0x0000
	#define SPI1CON2_VALUE          0x0000
	#define SPI2CON2_VALUE          0x0000




#else

	#define SPI1CON_VALUE          0x0000
	#define SPI2CON_VALUE          0x0000


#endif


/* SPIxCON REGISTER for 33f and 24H devices */



#if defined(__dsPIC33FJ64GP206__) || defined(__dsPIC33FJ64GP306__) || defined(__dsPIC33FJ64GP310__) || defined(__dsPIC33FJ64GP706__) || \
	defined(__dsPIC33FJ64GP708__) || defined(__dsPIC33FJ64GP710__) || defined(__dsPIC33FJ128GP206__) || defined(__dsPIC33FJ128GP306__) || \
	defined(__dsPIC33FJ128GP310__) || defined(__dsPIC33FJ128GP706__) || defined(__dsPIC33FJ128GP708__) || defined(__dsPIC33FJ128GP710__) || \
	defined(__dsPIC33FJ256GP506__) || defined(__dsPIC33FJ256GP510__) || defined(__dsPIC33FJ256GP710__) || defined(__dsPIC33FJ64MC506__) || \
	defined(__dsPIC33FJ64MC508__) || defined(__dsPIC33FJ64MC510__) || defined(__dsPIC33FJ64MC706__) || defined(__dsPIC33FJ64MC710__) || \
	defined(__dsPIC33FJ128MC506__) || defined(__dsPIC33FJ128MC510__) || defined(__dsPIC33FJ128MC706__) || defined(__dsPIC33FJ128MC708__) || \
	defined(__dsPIC33FJ128MC710__) || defined(__dsPIC33FJ256MC510__) || defined(__dsPIC33FJ256MC710__) ||defined(__PIC24HJ64GP206__) || \
    defined(__PIC24HJ64GP210__) || defined(__PIC24HJ64GP506__) || defined(__PIC24HJ64GP510__) || defined(__PIC24HJ128GP206__) || \
   	defined(__PIC24HJ128GP210__) || defined(__PIC24HJ128GP506__) || defined(__PIC24HJ128GP510__) || defined(__PIC24HJ128GP306__) || \
	defined(__PIC24HJ128GP310__) || defined(__PIC24HJ256GP206__) || defined(__PIC24HJ256GP210__) || \
	defined(__PIC24HJ256GP610__)

	/*SPIXCON1 REGISTER bits differing from 30F devices*/


	#define DISABLE_SCK_PIN		0xffff	/* Internal SPI clock is diabled, pin functions as I/O */
	#define ENABLE_SCK_PIN		0xefff	/*Internal SPI clock is enabled */


	/*SPIXCON2 REGISTER */


	#define  FRAME_ENABLE_ON        0xffff  /* Frame SPI support enable        */
	#define  FRAME_ENABLE_OFF       0x7fff  /* Frame SPI support Disable       */

	#define  FRAME_SYNC_INPUT       0xffff  /* Frame sync pulse Input (slave)  */
	#define  FRAME_SYNC_OUTPUT      0xbfff  /* Frame sync pulse Output (master)*/

	#define FRAME_POL_ACTIVE_HIGH	0xffff	/* Frame sync pulse is active-high*/
	#define FRAME_POL_ACTIVE_LOW	0xdfff	/* Frame sync pulse is active-low */

	#define FRAME_SYNC_EDGE_COINCIDE 0xffff	/* Frame sync pulse coincides with first bit clock */
	#define FRAME_SYNC_EDGE_PRECEDE  0xfffd	/* Frame sync pulse precedes first bit clock */

	#define FIFO_BUFFER_ENABLE	0xffff	/* FIFO buffer enabled */
	#define FIFO_BUFFER_DISABLE	0xfffe	/* FIFO buffer enabled */




#else

/* SPIxCON REGISTER bits in 30F devices differing from 33F and 24H devices */

	#define  FRAME_ENABLE_ON        0xffff  /* Frame SPI support enable        */
	#define  FRAME_ENABLE_OFF       0xbfff  /* Frame SPI support Disable       */

	#define  FRAME_SYNC_INPUT       0xffff  /* Frame sync pulse Input (slave)  */
	#define  FRAME_SYNC_OUTPUT      0xdfff  /* Frame sync pulse Output (master)*/



#endif



#define  DISABLE_SDO_PIN        0xffff  /* SDO pin is not used by module   */
#define  ENABLE_SDO_PIN         0xf7ff  /* SDO pin is  used by module      */

#define  SPI_MODE16_ON          0xffff  /* Communication is word wide      */
#define  SPI_MODE16_OFF         0xfbff  /* Communication is byte wide      */

#define  SPI_SMP_ON             0xffff  /* Input data sampled at end of data output time */
#define  SPI_SMP_OFF            0xfdff  /* Input data sampled at middle of data output time */

#define  SPI_CKE_ON             0xffff  /* Transmit happens from active clock 
                                           state to idle clock state*/
#define  SPI_CKE_OFF            0xfeff  /* Transmit happens on transition from
                                           idle clock state to active clock state */

#define  SLAVE_ENABLE_ON        0xffff  /* Slave Select enbale               */
#define  SLAVE_ENABLE_OFF       0xff7f  /* Slave Select not used by module   */

#define  CLK_POL_ACTIVE_LOW     0xffff  /* Idle state for clock is high, active is low */
#define  CLK_POL_ACTIVE_HIGH    0xffbf  /* Idle state for clock is low, active is high */

#define  MASTER_ENABLE_ON       0xffff  /* Master Mode              */
#define  MASTER_ENABLE_OFF      0xffdf  /* Slave Mode               */

#define  SEC_PRESCAL_1_1        0xffff  /* Secondary Prescale 1:1   */
#define  SEC_PRESCAL_2_1        0xfffb  /* Secondary Prescale 2:1   */
#define  SEC_PRESCAL_3_1        0xfff7  /* Secondary Prescale 3:1   */
#define  SEC_PRESCAL_4_1        0xfff3  /* Secondary Prescale 4:1   */
#define  SEC_PRESCAL_5_1        0xffef  /* Secondary Prescale 5:1   */
#define  SEC_PRESCAL_6_1        0xffeb  /* Secondary Prescale 6:1   */
#define  SEC_PRESCAL_7_1        0xffe7  /* Secondary Prescale 7:1   */
#define  SEC_PRESCAL_8_1        0xffe3  /* Secondary Prescale 8:1   */

#define  PRI_PRESCAL_1_1        0xffff  /* Primary Prescale 1:1     */
#define  PRI_PRESCAL_4_1        0xfffe  /* Primary Prescale 4:1     */
#define  PRI_PRESCAL_16_1       0xfffd  /* Primary Prescale 16:1    */
#define  PRI_PRESCAL_64_1       0xfffc  /* Primary Prescale 64:1    */



/* SPIxSTAT REGISTER */

#define  SPI_ENABLE             0xffff  /* Enable module */
#define  SPI_DISABLE            0x7fff  /* Disable module */

#define  SPI_IDLE_CON           0xdfff  /* Continue module operation in idle mode */
#define  SPI_IDLE_STOP          0xffff  /* Discontinue module operation in idle mode */ 

#define  SPI_RX_OVFLOW_CLR     0xffbf   /* Clear receive overflow bit.*/

#if defined(__dsPIC33FJ64GP206__) || defined(__dsPIC33FJ64GP306__) || defined(__dsPIC33FJ64GP310__) || defined(__dsPIC33FJ64GP706__) || \
	defined(__dsPIC33FJ64GP708__) || defined(__dsPIC33FJ64GP710__) || defined(__dsPIC33FJ128GP206__) || defined(__dsPIC33FJ128GP306__) || \
	defined(__dsPIC33FJ128GP310__) || defined(__dsPIC33FJ128GP706__) || defined(__dsPIC33FJ128GP708__) || defined(__dsPIC33FJ128GP710__) || \
	defined(__dsPIC33FJ256GP506__) || defined(__dsPIC33FJ256GP510__) || defined(__dsPIC33FJ256GP710__) || defined(__dsPIC33FJ64MC506__) || \
	defined(__dsPIC33FJ64MC508__) || defined(__dsPIC33FJ64MC510__) || defined(__dsPIC33FJ64MC706__) || defined(__dsPIC33FJ64MC710__) || \
	defined(__dsPIC33FJ128MC506__) || defined(__dsPIC33FJ128MC510__) || defined(__dsPIC33FJ128MC706__) || defined(__dsPIC33FJ128MC708__) || \
	defined(__dsPIC33FJ128MC710__) || defined(__dsPIC33FJ256MC510__) || defined(__dsPIC33FJ256MC710__) ||defined(__PIC24HJ64GP206__) || \
    defined(__PIC24HJ64GP210__) || defined(__PIC24HJ64GP506__) || defined(__PIC24HJ64GP510__) || defined(__PIC24HJ128GP206__) || \
   	defined(__PIC24HJ128GP210__) || defined(__PIC24HJ128GP506__) || defined(__PIC24HJ128GP510__) || defined(__PIC24HJ128GP306__) || \
	defined(__PIC24HJ128GP310__) || defined(__PIC24HJ256GP206__) || defined(__PIC24HJ256GP210__) || \
	defined(__PIC24HJ256GP610__) 

	#define FIFO_BUF_LEN_1		0xfff8	/* FIFO buffer length 1 words */
	#define FIFO_BUF_LEN_2		0xfff9	/* FIFO buffer length 2 words */
	#define FIFO_BUF_LEN_3		0xfffa	/* FIFO buffer length 3 words */
	#define FIFO_BUF_LEN_4		0xfffb	/* FIFO buffer length 4 words */
	#define FIFO_BUF_LEN_5		0xfffc	/* FIFO buffer length 5 words */
	#define FIFO_BUF_LEN_6		0xfffd	/* FIFO buffer length 6 words */
	#define FIFO_BUF_LEN_7		0xfffe	/* FIFO buffer length 7 words */
	#define FIFO_BUF_LEN_8		0xffff	/* FIFO buffer length 8 words */

#endif

 
/* SPI Interrupt defines */

#define  SPI_INT_EN             0xffff  /* SPI Interrupt Enable     */
#define  SPI_INT_DIS            0xfff7  /* SPI Interrupt Disable    */

#define  SPI_INT_PRI_0          0xfff8  /* SPI Interrupt Prior Level_0 */
#define  SPI_INT_PRI_1          0xfff9  /* SPI Interrupt Prior Level_1 */
#define  SPI_INT_PRI_2          0xfffa  /* SPI Interrupt Prior Level_2 */
#define  SPI_INT_PRI_3          0xfffb  /* SPI Interrupt Prior Level_3 */
#define  SPI_INT_PRI_4          0xfffc  /* SPI Interrupt Prior Level_4 */
#define  SPI_INT_PRI_5          0xfffd  /* SPI Interrupt Prior Level_5 */
#define  SPI_INT_PRI_6          0xfffe  /* SPI Interrupt Prior Level_6 */
#define  SPI_INT_PRI_7          0xffff  /* SPI Interrupt Prior Level_7 */



#if defined(__dsPIC33FJ64GP206__) || defined(__dsPIC33FJ64GP306__) || defined(__dsPIC33FJ64GP310__) || defined(__dsPIC33FJ64GP706__) || \
	defined(__dsPIC33FJ64GP708__) || defined(__dsPIC33FJ64GP710__) || defined(__dsPIC33FJ128GP206__) || defined(__dsPIC33FJ128GP306__) || \
	defined(__dsPIC33FJ128GP310__) || defined(__dsPIC33FJ128GP706__) || defined(__dsPIC33FJ128GP708__) || defined(__dsPIC33FJ128GP710__) || \
	defined(__dsPIC33FJ256GP506__) || defined(__dsPIC33FJ256GP510__) || defined(__dsPIC33FJ256GP710__) || defined(__dsPIC33FJ64MC506__) || \
	defined(__dsPIC33FJ64MC508__) || defined(__dsPIC33FJ64MC510__) || defined(__dsPIC33FJ64MC706__) || defined(__dsPIC33FJ64MC710__) || \
	defined(__dsPIC33FJ128MC506__) || defined(__dsPIC33FJ128MC510__) || defined(__dsPIC33FJ128MC706__) || defined(__dsPIC33FJ128MC708__) || \
	defined(__dsPIC33FJ128MC710__) || defined(__dsPIC33FJ256MC510__) || defined(__dsPIC33FJ256MC710__) ||defined(__PIC24HJ64GP206__) || \
    defined(__PIC24HJ64GP210__) || defined(__PIC24HJ64GP506__) || defined(__PIC24HJ64GP510__) || defined(__PIC24HJ128GP206__) || \
   	defined(__PIC24HJ128GP210__) || defined(__PIC24HJ128GP506__) || defined(__PIC24HJ128GP510__) || defined(__PIC24HJ128GP306__) || \
	defined(__PIC24HJ128GP310__) || defined(__PIC24HJ256GP206__) || defined(__PIC24HJ256GP210__) || \
	defined(__PIC24HJ256GP610__) 


/* Macros to  Enable/Disable interrupts and set Interrupt priority of SPI1 in 33F*/
	#define EnableIntSPI1                    asm("BSET IEC0,#10")
	#define DisableIntSPI1                   asm("BCLR IEC0,#10")
	#define SetPriorityIntSPI1(priority)     (IPC2bits.SPI1IP = priority)

	#define EnableIntSPI2                    asm("BSET IEC2,#10")
	#define DisableIntSPI2                   asm("BCLR IEC2,#10")
	#define SetPriorityIntSPI2(priority)     (IPC8bits.SPI2IP = priority)


/* CloseSPI. Disables SPI module */
	void  CloseSPI1() __attribute__ ((section (".libperi")));

/* ConfigINtSPI1. Configure Interrupt enable and priorities */
	void ConfigIntSPI1(unsigned int config)  __attribute__ ((section(".libperi")));


/* DataRdySPI */
 
	char DataRdySPI1() __attribute__ ((section (".libperi"))); 

/* getcSPI. Read byte from SPIBUF register */
	#define  getcSPI1    ReadSPI1


/* getsSPI.Write string to SPIBUF */
	unsigned int getsSPI1(unsigned int length, unsigned int *rdptr, unsigned int spi_data_wait) 
__attribute__ ((section (".libperi")));


/* OpenSPI */
	void OpenSPI1(unsigned int config1,unsigned int config2,unsigned int config3 ) __attribute__ ((section (".libperi")));

/* putcSPI.Write byte/word to SPIBUF register */
	#define  putcSPI1    WriteSPI1


/* putsSPI Read string from SPIBUF */
	void putsSPI1(unsigned int length, unsigned int *wrptr)__attribute__ ((section (".libperi")));


/* ReadSPI.Read byte/word from SPIBUF register */
	unsigned int ReadSPI1() __attribute__ ((section (".libperi")));


/* WriteSPI. Write byte/word to SPIBUF register */
	void WriteSPI1(unsigned int data_out) __attribute__ ((section (".libperi")));



	void OpenSPI1(unsigned int config1,unsigned int config2,unsigned int config3) __attribute__ ((section (".libperi")));;



/* CloseSPI2.Disables SPI module */
	void  CloseSPI2()  __attribute__ ((section (".libperi")));

/* ConfigINtSPI2. Configures Interrupt enable and priorities */
	void ConfigIntSPI2(unsigned int config)  __attribute__ ((section(".libperi")));

/* OpenSPI */
	void OpenSPI2(unsigned int config1,unsigned int config2, unsigned int config3 )__attribute__ ((section(".libperi")));

/* DataRdySPI. Test if SPIBUF register is full */
	char DataRdySPI2()  __attribute__ ((section (".libperi"))); 

/* getcSPI.Read byte from SPIBUF register */
	#define  getcSPI2    ReadSPI2

/* getsSPI.Write string to SPIBUF */
	unsigned int getsSPI2(unsigned int length, unsigned int *rdptr, unsigned int spi_data_wait) 
 __attribute__ ((section(".libperi")));

/* putcSPI.Write byte/word to SPIBUF register */

	#define  putcSPI2    WriteSPI2

/* putsSPI. Read string from SPIBUF */
	void putsSPI2(unsigned int length, unsigned int *wrptr)__attribute__ ((section(".libperi")));


/* ReadSPI.Read byte/word from SPIBUF register */
	unsigned int ReadSPI2() __attribute__ ((section (".libperi")));


/* WriteSPI. Write byte/word to SPIBUF register */
	void WriteSPI2( unsigned int data_out) __attribute__ ((section(".libperi")));



#else


/* Macros to  Enable/Disable interrupts and set Interrupt priority of SPI1 in 30F*/
	#define EnableIntSPI1                    asm("BSET IEC0,#8")
	#define DisableIntSPI1                   asm("BCLR IEC0,#8")
	#define SetPriorityIntSPI1(priority)     (IPC2bits.SPI1IP = priority)

/* FUNCTION PROTOTYPES */


/* CloseSPI. Disables SPI module */
	void  CloseSPI1() __attribute__ ((section (".libperi")));

/* ConfigINtSPI1. Configure Interrupt enable and priorities */
	void ConfigIntSPI1(unsigned int config)  __attribute__ ((section(".libperi")));


/* DataRdySPI */
 
	char DataRdySPI1() __attribute__ ((section (".libperi"))); 

/* getcSPI. Read byte from SPIBUF register */
	#define  getcSPI1    ReadSPI1


/* getsSPI.Write string to SPIBUF */
	unsigned int getsSPI1(unsigned int length, unsigned int *rdptr, unsigned int spi_data_wait) 
__attribute__ ((section (".libperi")));


/* OpenSPI */
	void OpenSPI1(unsigned int config1,unsigned int config2 ) __attribute__ ((section (".libperi")));

/* putcSPI.Write byte/word to SPIBUF register */
	#define  putcSPI1    WriteSPI1


/* putsSPI Read string from SPIBUF */
	void putsSPI1(unsigned int length, unsigned int *wrptr)__attribute__ ((section (".libperi")));


/* ReadSPI.Read byte/word from SPIBUF register */
	unsigned int ReadSPI1() __attribute__ ((section (".libperi")));


/* WriteSPI. Write byte/word to SPIBUF register */
	void WriteSPI1(unsigned int data_out) __attribute__ ((section (".libperi")));


/* The following devices support SPI2 */

	#if defined(__dsPIC30F6010__) || defined(__dsPIC30F5011__) || defined(__dsPIC30F6011__) || \
	    defined(__dsPIC30F6012__) || defined(__dsPIC30F5013__) || defined(__dsPIC30F6013__) || \
	    defined(__dsPIC30F6014__) || defined(__dsPIC30F5015__) || defined(__dsPIC30F6010A__) || \
	    defined(__dsPIC30F6011A__) || defined(__dsPIC30F6012A__) || defined(__dsPIC30F6013A__) || \
	    defined(__dsPIC30F6014A__) || defined(__dsPIC30F5016__) || defined(__dsPIC30F6015__)


/* Macros to  Enable/Disable interrupts and set Interrupt priority of SPI2 */
		#define EnableIntSPI2                    asm("BSET IEC1,#10")
		#define DisableIntSPI2                   asm("BCLR IEC1,#10")
		#define SetPriorityIntSPI2(priority)     (IPC6bits.SPI2IP = priority)

/* CloseSPI2.Disables SPI module */
		void  CloseSPI2()  __attribute__ ((section (".libperi")));

/* ConfigINtSPI2. Configures Interrupt enable and priorities */
		void ConfigIntSPI2(unsigned int config)  __attribute__ ((section(".libperi")));

/* OpenSPI */
		void OpenSPI2(unsigned int config1,unsigned int config2 )  __attribute__ ((section
(".libperi")));

/* DataRdySPI. Test if SPIBUF register is full */
		char DataRdySPI2()  __attribute__ ((section (".libperi"))); 

/* getcSPI.Read byte from SPIBUF register */
		#define  getcSPI2    ReadSPI2

/* getsSPI.Write string to SPIBUF */
		unsigned int getsSPI2(unsigned int length, unsigned int *rdptr, unsigned int spi_data_wait) 
 __attribute__ ((section(".libperi")));

/* putcSPI.Write byte/word to SPIBUF register */
		#define  putcSPI2    WriteSPI2

/* putsSPI. Read string from SPIBUF */
		void putsSPI2(unsigned int length, unsigned int *wrptr)__attribute__ ((section(".libperi")));


/* ReadSPI.Read byte/word from SPIBUF register */
		unsigned int ReadSPI2() __attribute__ ((section (".libperi")));


/* WriteSPI. Write byte/word to SPIBUF register */
		void WriteSPI2( unsigned int data_out) __attribute__ ((section(".libperi")));


#endif
#endif
#endif  /* __SPI_H */
