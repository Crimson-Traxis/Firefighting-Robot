
/********************************************************************/
/*              Header for DMA module library functions      */
/********************************************************************/

#ifndef __DMA_H
#define __DMA_H

/* List of SFRs for DMA */
/* This list contains the SFRs with default (POR) values to be used for configuring DMA */
/* The user can modify this based on the requirement */


#define DMA0CON_VALUE                0x0000
#define DMA1CON_VALUE                0x0000
#define DMA2CON_VALUE                0x0000
#define DMA3CON_VALUE		     0x0000
#define DMA4CON_VALUE                0x0000
#define DMA5CON_VALUE		     0x0000
#define DMA6CON_VALUE		     0x0000
#define DMA7CON_VALUE                0x0000


/* DMA0CON Configuration Bit Definitions */

#define DMA0_MODULE_ON               0xFFFF /* A/D Converter on */
#define DMA0_MODULE_OFF              0x7FFF /* A/D Converter off */


#define DMA0_SIZE_BYTE			0xFFFF /* DMA0 data size is byte */
#define DMA0_SIZE_WORD			0xBFFF /* DMA0 data size is word */

#define DMA0_TO_PERIPHERAL		0xFFFF	/*Read from DMA RAM address, write to peripheral*/ 
#define PERIPHERAL_TO_DMA0		0xDFFF	/* Read from peripheral address, write to DMA RAM*/

#define DMA0_INTERRUPT_HALF		0xFFFF	/* Initiate block transfer complete interrupt
							when half of the data has been moved */

#define DMA0_INTERRUPT_BLOCK		0xEFFF	/*Initiate block transfer complete interrupt
							when all of the data has been moved */

#define DMA0_WRITE_NULL			0xFFFF	/*Null data write to peripheral in addition to DMA RAM write*/
#define DMA0_NORMAL			0xF7FF	/*Normal operation*/

#define DMA0_PERIPHERAL_INDIRECT	0xFF2F	/*Peripheral indirect addressing mode*/
#define DMA0_REGISTER			0xFF1F	/*Register indirect without post increment*/
#define DMA0_REGISTER_POST_INCREMENT	0xFF0F	/*Register indirect with post-incrmenent mode*/

#define DMA0_ONE_SHOT_PING_PONG		0xFFFF	/* One-Shot, Ping-Pong modes enabled*/
#define DMA0_CONTINUOUS_PING_PONG	0xFFF2	/* Continuous Ping-Pong modes enabled*/
#define DMA0_ONE_SHOT			0xFFF1	/* One-shot Ping-Pong mode disabled*/
#define DMA0_CONTINUOUS			0xFFF0	/*COntinuous Ping-Pong modes disabled */




/* DMA1CON Configuration Bit Definitions */

#define DMA1_MODULE_ON               0xFFFF /* A/D Converter on */
#define DMA1_MODULE_OFF              0x7FFF /* A/D Converter off */


#define DMA1_SIZE_BYTE			0xFFFF /* DMA1 data size is byte */
#define DMA1_SIZE_WORD			0xBFFF /* DMA1 data size is word */

#define DMA1_TO_PERIPHERAL		0xFFFF	/*Read from DMA RAM address, write to peripheral*/ 
#define PERIPHERAL_TO_DMA1		0xDFFF	/* Read from peripheral address, write to DMA RAM*/

#define DMA1_INTERRUPT_HALF		0xFFFF	/* Initiate block transfer complete interrupt
							when half of the data has been moved */

#define DMA1_INTERRUPT_BLOCK		0xEFFF	/*Initiate block transfer complete interrupt
							when all of the data has been moved */

#define DMA1_WRITE_NULL			0xFFFF	/*Null data write to peripheral in addition to DMA RAM write*/
#define DMA1_NORMAL			0xF7FF	/*Normal operation*/

#define DMA1_PERIPHERAL_INDIRECT	0xFF2F	/*Peripheral indirect addressing mode*/
#define DMA1_REGISTER			0xFF1F	/*Register indirect without post increment*/
#define DMA1_REGISTER_POST_INCREMENT	0xFF0F	/*Register indirect with post-incrmenent mode*/

#define DMA1_ONE_SHOT_PING_PONG		0xFFFF	/* One-Shot, Ping-Pong modes enabled*/
#define DMA1_CONTINUOUS_PING_PONG	0xFFF2	/* Continuous Ping-Pong modes enabled*/
#define DMA1_ONE_SHOT			0xFFF1	/* One-shot Ping-Pong mode disabled*/
#define DMA1_CONTINUOUS			0xFFF0	/*COntinuous Ping-Pong modes disabled */



/* DMA2CON Configuration Bit Definitions */

#define DMA2_MODULE_ON               0xFFFF /* A/D Converter on */
#define DMA2_MODULE_OFF              0x7FFF /* A/D Converter off */


#define DMA2_SIZE_BYTE			0xFFFF /* DMA2 data size is byte */
#define DMA2_SIZE_WORD			0xBFFF /* DMA2 data size is word */

#define DMA2_TO_PERIPHERAL		0xFFFF	/*Read from DMA RAM address, write to peripheral*/ 
#define PERIPHERAL_TO_DMA2		0xDFFF	/* Read from peripheral address, write to DMA RAM*/

#define DMA2_INTERRUPT_HALF		0xFFFF	/* Initiate block transfer complete interrupt
							when half of the data has been moved */

#define DMA2_INTERRUPT_BLOCK		0xEFFF	/*Initiate block transfer complete interrupt
							when all of the data has been moved */

#define DMA2_WRITE_NULL			0xFFFF	/*Null data write to peripheral in addition to DMA RAM write*/
#define DMA2_NORMAL			0xF7FF	/*Normal operation*/

#define DMA2_PERIPHERAL_INDIRECT	0xFF2F	/*Peripheral indirect addressing mode*/
#define DMA2_REGISTER			0xFF1F	/*Register indirect without post increment*/
#define DMA2_REGISTER_POST_INCREMENT	0xFF0F	/*Register indirect with post-incrmenent mode*/

#define DMA2_ONE_SHOT_PING_PONG		0xFFFF	/* One-Shot, Ping-Pong modes enabled*/
#define DMA2_CONTINUOUS_PING_PONG	0xFFF2	/* Continuous Ping-Pong modes enabled*/
#define DMA2_ONE_SHOT			0xFFF1	/* One-shot Ping-Pong mode disabled*/
#define DMA2_CONTINUOUS			0xFFF0	/*COntinuous Ping-Pong modes disabled */



/* DMA3CON Configuration Bit Definitions */

#define DMA3_MODULE_ON               0xFFFF /* A/D Converter on */
#define DMA3_MODULE_OFF              0x7FFF /* A/D Converter off */


#define DMA3_SIZE_BYTE			0xFFFF /* DMA3 data size is byte */
#define DMA3_SIZE_WORD			0xBFFF /* DMA3 data size is word */

#define DMA3_TO_PERIPHERAL		0xFFFF	/*Read from DMA RAM address, write to peripheral*/ 
#define PERIPHERAL_TO_DMA3		0xDFFF	/* Read from peripheral address, write to DMA RAM*/

#define DMA3_INTERRUPT_HALF		0xFFFF	/* Initiate block transfer complete interrupt
							when half of the data has been moved */

#define DMA3_INTERRUPT_BLOCK		0xEFFF	/*Initiate block transfer complete interrupt
							when all of the data has been moved */

#define DMA3_WRITE_NULL			0xFFFF	/*Null data write to peripheral in addition to DMA RAM write*/
#define DMA3_NORMAL			0xF7FF	/*Normal operation*/

#define DMA3_PERIPHERAL_INDIRECT	0xFF2F	/*Peripheral indirect addressing mode*/
#define DMA3_REGISTER			0xFF1F	/*Register indirect without post increment*/
#define DMA3_REGISTER_POST_INCREMENT	0xFF0F	/*Register indirect with post-incrmenent mode*/

#define DMA3_ONE_SHOT_PING_PONG		0xFFFF	/* One-Shot, Ping-Pong modes enabled*/
#define DMA3_CONTINUOUS_PING_PONG	0xFFF2	/* Continuous Ping-Pong modes enabled*/
#define DMA3_ONE_SHOT			0xFFF1	/* One-shot Ping-Pong mode disabled*/
#define DMA3_CONTINUOUS			0xFFF0	/*COntinuous Ping-Pong modes disabled */


/* DMA4CON Configuration Bit Definitions */

#define DMA4_MODULE_ON               0xFFFF /* A/D Converter on */
#define DMA4_MODULE_OFF              0x7FFF /* A/D Converter off */


#define DMA4_SIZE_BYTE			0xFFFF /* DMA4 data size is byte */
#define DMA4_SIZE_WORD			0xBFFF /* DMA4 data size is word */

#define DMA4_TO_PERIPHERAL		0xFFFF	/*Read from DMA RAM address, write to peripheral*/ 
#define PERIPHERAL_TO_DMA4		0xDFFF	/* Read from peripheral address, write to DMA RAM*/

#define DMA4_INTERRUPT_HALF		0xFFFF	/* Initiate block transfer complete interrupt
							when half of the data has been moved */

#define DMA4_INTERRUPT_BLOCK		0xEFFF	/*Initiate block transfer complete interrupt
							when all of the data has been moved */

#define DMA4_WRITE_NULL			0xFFFF	/*Null data write to peripheral in addition to DMA RAM write*/
#define DMA4_NORMAL			0xF7FF	/*Normal operation*/

#define DMA4_PERIPHERAL_INDIRECT	0xFF2F	/*Peripheral indirect addressing mode*/
#define DMA4_REGISTER			0xFF1F	/*Register indirect without post increment*/
#define DMA4_REGISTER_POST_INCREMENT	0xFF0F	/*Register indirect with post-incrmenent mode*/

#define DMA4_ONE_SHOT_PING_PONG		0xFFFF	/* One-Shot, Ping-Pong modes enabled*/
#define DMA4_CONTINUOUS_PING_PONG	0xFFF2	/* Continuous Ping-Pong modes enabled*/
#define DMA4_ONE_SHOT			0xFFF1	/* One-shot Ping-Pong mode disabled*/
#define DMA4_CONTINUOUS			0xFFF0	/*COntinuous Ping-Pong modes disabled */


/* DMA5CON Configuration Bit Definitions */

#define DMA5_MODULE_ON               0xFFFF /* A/D Converter on */
#define DMA5_MODULE_OFF              0x7FFF /* A/D Converter off */


#define DMA5_SIZE_BYTE			0xFFFF /* DMA5 data size is byte */
#define DMA5_SIZE_WORD			0xBFFF /* DMA5 data size is word */

#define DMA5_TO_PERIPHERAL		0xFFFF	/*Read from DMA RAM address, write to peripheral*/ 
#define PERIPHERAL_TO_DMA5		0xDFFF	/* Read from peripheral address, write to DMA RAM*/

#define DMA5_INTERRUPT_HALF		0xFFFF	/* Initiate block transfer complete interrupt
							when half of the data has been moved */

#define DMA5_INTERRUPT_BLOCK		0xEFFF	/*Initiate block transfer complete interrupt
							when all of the data has been moved */

#define DMA5_WRITE_NULL			0xFFFF	/*Null data write to peripheral in addition to DMA RAM write*/
#define DMA5_NORMAL			0xF7FF	/*Normal operation*/

#define DMA5_PERIPHERAL_INDIRECT	0xFF2F	/*Peripheral indirect addressing mode*/
#define DMA5_REGISTER			0xFF1F	/*Register indirect without post increment*/
#define DMA5_REGISTER_POST_INCREMENT	0xFF0F	/*Register indirect with post-incrmenent mode*/

#define DMA5_ONE_SHOT_PING_PONG		0xFFFF	/* One-Shot, Ping-Pong modes enabled*/
#define DMA5_CONTINUOUS_PING_PONG	0xFFF2	/* Continuous Ping-Pong modes enabled*/
#define DMA5_ONE_SHOT			0xFFF1	/* One-shot Ping-Pong mode disabled*/
#define DMA5_CONTINUOUS			0xFFF0	/*COntinuous Ping-Pong modes disabled */


/* DMA6CON Configuration Bit Definitions */

#define DMA6_MODULE_ON               0xFFFF /* A/D Converter on */
#define DMA6_MODULE_OFF              0x7FFF /* A/D Converter off */


#define DMA6_SIZE_BYTE			0xFFFF /* DMA6 data size is byte */
#define DMA6_SIZE_WORD			0xBFFF /* DMA6 data size is word */

#define DMA6_TO_PERIPHERAL		0xFFFF	/*Read from DMA RAM address, write to peripheral*/ 
#define PERIPHERAL_TO_DMA6		0xDFFF	/* Read from peripheral address, write to DMA RAM*/

#define DMA6_INTERRUPT_HALF		0xFFFF	/* Initiate block transfer complete interrupt
							when half of the data has been moved */

#define DMA6_INTERRUPT_BLOCK		0xEFFF	/*Initiate block transfer complete interrupt
							when all of the data has been moved */

#define DMA6_WRITE_NULL			0xFFFF	/*Null data write to peripheral in addition to DMA RAM write*/
#define DMA6_NORMAL			0xF7FF	/*Normal operation*/

#define DMA6_PERIPHERAL_INDIRECT	0xFF2F	/*Peripheral indirect addressing mode*/
#define DMA6_REGISTER			0xFF1F	/*Register indirect without post increment*/
#define DMA6_REGISTER_POST_INCREMENT	0xFF0F	/*Register indirect with post-incrmenent mode*/

#define DMA6_ONE_SHOT_PING_PONG		0xFFFF	/* One-Shot, Ping-Pong modes enabled*/
#define DMA6_CONTINUOUS_PING_PONG	0xFFF2	/* Continuous Ping-Pong modes enabled*/
#define DMA6_ONE_SHOT			0xFFF1	/* One-shot Ping-Pong mode disabled*/
#define DMA6_CONTINUOUS			0xFFF0	/*COntinuous Ping-Pong modes disabled */


/* DMA7CON Configuration Bit Definitions */

#define DMA7_MODULE_ON               0xFFFF /* A/D Converter on */
#define DMA7_MODULE_OFF              0x7FFF /* A/D Converter off */


#define DMA7_SIZE_BYTE			0xFFFF /* DMA7 data size is byte */
#define DMA7_SIZE_WORD			0xBFFF /* DMA7 data size is word */

#define DMA7_TO_PERIPHERAL		0xFFFF	/*Read from DMA RAM address, write to peripheral*/ 
#define PERIPHERAL_TO_DMA7		0xDFFF	/* Read from peripheral address, write to DMA RAM*/

#define DMA7_INTERRUPT_HALF		0xFFFF	/* Initiate block transfer complete interrupt
							when half of the data has been moved */

#define DMA7_INTERRUPT_BLOCK		0xEFFF	/*Initiate block transfer complete interrupt
							when all of the data has been moved */

#define DMA7_WRITE_NULL			0xFFFF	/*Null data write to peripheral in addition to DMA RAM write*/
#define DMA7_NORMAL			0xF7FF	/*Normal operation*/

#define DMA7_PERIPHERAL_INDIRECT	0xFF2F	/*Peripheral indirect addressing mode*/
#define DMA7_REGISTER			0xFF1F	/*Register indirect without post increment*/
#define DMA7_REGISTER_POST_INCREMENT	0xFF0F	/*Register indirect with post-incrmenent mode*/

#define DMA7_ONE_SHOT_PING_PONG		0xFFFF	/* One-Shot, Ping-Pong modes enabled*/
#define DMA7_CONTINUOUS_PING_PONG	0xFFF2	/* Continuous Ping-Pong modes enabled*/
#define DMA7_ONE_SHOT			0xFFF1	/* One-shot Ping-Pong mode disabled*/
#define DMA7_CONTINUOUS			0xFFF0	/*COntinuous Ping-Pong modes disabled */


	/*DMA0REQ bit definitions*/

#define DMA0_MANUAL			0xFFFF	/*Force a single DMA transfer (Manual Mode)
#define DMA0_AUTOMATIC			0x7FFF	/* Automatic DMA transfer initiation by DMA request*/

	/*DMA1REQ bit definitions*/

#define DMA1_MANUAL			0xFFFF	/*Force a single DMA transfer (Manual Mode)
#define DMA1_AUTOMATIC			0x7FFF	/* Automatic DMA transfer initiation by DMA request*/

	/*DMA2REQ bit definitions*/

#define DMA2_MANUAL			0xFFFF	/*Force a single DMA transfer (Manual Mode)
#define DMA2_AUTOMATIC			0x7FFF	/* Automatic DMA transfer initiation by DMA request*/

	/*DMA3REQ bit definitions*/

#define DMA3_MANUAL			0xFFFF	/*Force a single DMA transfer (Manual Mode)
#define DMA3_AUTOMATIC			0x7FFF	/* Automatic DMA transfer initiation by DMA request*/

	/*DMA4REQ bit definitions*/

#define DMA4_MANUAL			0xFFFF	/*Force a single DMA transfer (Manual Mode)
#define DMA4_AUTOMATIC			0x7FFF	/* Automatic DMA transfer initiation by DMA request*/


	/*DMA5REQ bit definitions*/

#define DMA5_MANUAL			0xFFFF	/*Force a single DMA transfer (Manual Mode)
#define DMA5_AUTOMATIC			0x7FFF	/* Automatic DMA transfer initiation by DMA request*/

	/*DMA6REQ bit definitions*/

#define DMA6_MANUAL			0xFFFF	/*Force a single DMA transfer (Manual Mode)
#define DMA6_AUTOMATIC			0x7FFF	/* Automatic DMA transfer initiation by DMA request*/

	/*DMA7REQ bit definitions*/

#define DMA7_MANUAL			0xFFFF	/*Force a single DMA transfer (Manual Mode)
#define DMA7_AUTOMATIC			0x7FFF	/* Automatic DMA transfer initiation by DMA request*/


	/* DMA controller status register 0 */

#define CHAN7_PERI_WRITE_COLLISION	0xFFFF	/*channel 7 peripheral write collision detected*/
#define CHAN7_PERI_NO_WRITE_COLLISION	0x7FFF	/*channel 7 peripheral write collision not detected*/
#define CHAN6_PERI_WRITE_COLLISION	0xFFFF	/*channel 6 peripheral write collision detected*/
#define CHAN6_PERI_NO_WRITE_COLLISION	0xBFFF	/*channel 6 peripheral write collision not detected*/
#define CHAN5_PERI_WRITE_COLLISION	0xFFFF	/*channel 5 peripheral write collision detected*/
#define CHAN5_PERI_NO_WRITE_COLLISION	0xDFFF	/*channel 5 peripheral write collision not detected*/
#define CHAN4_PERI_WRITE_COLLISION	0xFFFF	/*channel 4 peripheral write collision detected*/
#define CHAN4_PERI_NO_WRITE_COLLISION	0xEFFF	/*channel 4 peripheral write collision not detected*/
#define CHAN3_PERI_WRITE_COLLISION	0xFFFF	/*channel 3 peripheral write collision detected*/
#define CHAN3_PERI_NO_WRITE_COLLISION	0xF7FF	/*channel 3 peripheral write collision not detected*/
#define CHAN2_PERI_WRITE_COLLISION	0xFFFF	/*channel 2 peripheral write collision detected*/
#define CHAN2_PERI_NO_WRITE_COLLISION	0xFBFF	/*channel 2 peripheral write collision not detected*/
#define CHAN1_PERI_WRITE_COLLISION	0xFFFF	/*channel 1 peripheral write collision detected*/
#define CHAN1_PERI_NO_WRITE_COLLISION	0xFDFF	/*channel 1 peripheral write collision not detected*/
#define CHAN0_PERI_WRITE_COLLISION	0xFFFF	/*channel 0 peripheral write collision detected*/
#define CHAN0_PERI_NO_WRITE_COLLISION	0xFEFF	/*channel 0 peripheral write collision not detected*/

#define CHAN7_DMARAM_WRITE_COLLISION	0xFFFF	/*channel 7 DMA RAM write collision detected*/
#define CHAN7_DMARAM_NO_WRITE_COLLISION	0xFF7F	/*channel 7 DMA RAM write collision detected*/
#define CHAN6_DMARAM_WRITE_COLLISION	0xFFFF	/*channel 6 DMA RAM write collision detected*/
#define CHAN6_DMARAM_NO_WRITE_COLLISION	0xFFBF	/*channel 6 DMA RAM write collision detected*/
#define CHAN5_DMARAM_WRITE_COLLISION	0xFFFF	/*channel 5 DMA RAM write collision detected*/
#define CHAN5_DMARAM_NO_WRITE_COLLISION	0xFFDF	/*channel 5 DMA RAM write collision detected*/
#define CHAN4_DMARAM_WRITE_COLLISION	0xFFFF	/*channel 4 DMA RAM write collision detected*/
#define CHAN4_DMARAM_NO_WRITE_COLLISION	0xFFEF	/*channel 4 DMA RAM write collision detected*/
#define CHAN3_DMARAM_WRITE_COLLISION	0xFFFF	/*channel 3 DMA RAM write collision detected*/
#define CHAN3_DMARAM_NO_WRITE_COLLISION	0xFFF7	/*channel 3 DMA RAM write collision detected*/
#define CHAN2_DMARAM_WRITE_COLLISION	0xFFFF	/*channel 2 DMA RAM write collision detected*/
#define CHAN2_DMARAM_NO_WRITE_COLLISION	0xFFFB	/*channel 2 DMA RAM write collision detected*/
#define CHAN1_DMARAM_WRITE_COLLISION	0xFFFF	/*channel 1 DMA RAM write collision detected*/
#define CHAN1_DMARAM_NO_WRITE_COLLISION	0xFFFD	/*channel 1 DMA RAM write collision detected*/
#define CHAN0_DMARAM_WRITE_COLLISION	0xFFFF	/*channel 0 DMA RAM write collision detected*/
#define CHAN0_DMARAM_NO_WRITE_COLLISION	0xFFFE	/*channel 0 DMA RAM write collision detected*/



	/*DMA controller status register 1 */


#define LAST_DMA_ACTIVE_CHANNEL7	0xF7FF	/* Last data transfer was by DMA channel 7*/
#define LAST_DMA_ACTIVE_CHANNEL6	0xF6FF	/* Last data transfer was by DMA channel 6*/
#define LAST_DMA_ACTIVE_CHANNEL5	0xF5FF	/* Last data transfer was by DMA channel 5*/
#define LAST_DMA_ACTIVE_CHANNEL4	0xF4FF	/* Last data transfer was by DMA channel 4*/
#define LAST_DMA_ACTIVE_CHANNEL3	0xF3FF	/* Last data transfer was by DMA channel 3*/
#define LAST_DMA_ACTIVE_CHANNEL2	0xF2FF	/* Last data transfer was by DMA channel 2*/
#define LAST_DMA_ACTIVE_CHANNEL1	0xF1FF	/* Last data transfer was by DMA channel 1*/
#define LAST_DMA_ACTIVE_CHANNEL0	0xF0FF	/* Last data transfer was by DMA channel 0*/

#define PING_PONG_DMA7STB		0xFFFF	/*Channel 7 STB register selected for Ping-Pong*/
#define PING_PONG_DMA7STA		0xFF7F	/*Channel 7 STA register selected for Ping-Pong*/
#define PING_PONG_DMA6STB		0xFFFF	/*Channel 6 STB register selected for Ping-Pong*/
#define PING_PONG_DMA6STA		0xFFBF	/*Channel 7 STA register selected for Ping-Pong*/
#define PING_PONG_DMA5STB		0xFFFF	/*Channel 5 STB register selected for Ping-Pong*/
#define PING_PONG_DMA5STA		0xFFDF	/*Channel 7 STA register selected for Ping-Pong*/
#define PING_PONG_DMA4STB		0xFFFF	/*Channel 4 STB register selected for Ping-Pong*/
#define PING_PONG_DMA4STA		0xFFEF	/*Channel 7 STA register selected for Ping-Pong*/
#define PING_PONG_DMA3STB		0xFFFF	/*Channel 3 STB register selected for Ping-Pong*/
#define PING_PONG_DMA3STA		0xFFF7	/*Channel 7 STA register selected for Ping-Pong*/
#define PING_PONG_DMA2STB		0xFFFF	/*Channel 2 STB register selected for Ping-Pong*/
#define PING_PONG_DMA2STA		0xFFFB	/*Channel 7 STA register selected for Ping-Pong*/
#define PING_PONG_DMA1STB		0xFFFF	/*Channel 1 STB register selected for Ping-Pong*/
#define PING_PONG_DMA1STA		0xFFFD	/*Channel 7 STA register selected for Ping-Pong*/
#define PING_PONG_DMA0STB		0xFFFF	/*Channel 0 STB register selected for Ping-Pong*/
#define PING_PONG_DMA0STA		0xFFFE	/*Channel 7 STA register selected for Ping-Pong*/




/* Setting the priority of DMA0 interrupt */
#define DMA0_INT_PRI_0                   0xFFF8
#define DMA0_INT_PRI_1                   0xFFF9
#define DMA0_INT_PRI_2                   0xFFFA
#define DMA0_INT_PRI_3                   0xFFFB
#define DMA0_INT_PRI_4                   0xFFFC
#define DMA0_INT_PRI_5                   0xFFFD
#define DMA0_INT_PRI_6                   0xFFFE
#define DMA0_INT_PRI_7                   0xFFFF


/* Setting the priority of DMA1 interrupt */
#define DMA1_INT_PRI_0                   0xFFF8
#define DMA1_INT_PRI_1                   0xFFF9
#define DMA1_INT_PRI_2                   0xFFFA
#define DMA1_INT_PRI_3                   0xFFFB
#define DMA1_INT_PRI_4                   0xFFFC
#define DMA1_INT_PRI_5                   0xFFFD
#define DMA1_INT_PRI_6                   0xFFFE
#define DMA1_INT_PRI_7                   0xFFFF


/* Setting the priority of DMA2 interrupt */
#define DMA2_INT_PRI_0                   0xFFF8
#define DMA2_INT_PRI_1                   0xFFF9
#define DMA2_INT_PRI_2                   0xFFFA
#define DMA2_INT_PRI_3                   0xFFFB
#define DMA2_INT_PRI_4                   0xFFFC
#define DMA2_INT_PRI_5                   0xFFFD
#define DMA2_INT_PRI_6                   0xFFFE
#define DMA2_INT_PRI_7                   0xFFFF


/* Setting the priority of DMA3 interrupt */
#define DMA3_INT_PRI_0                   0xFFF8
#define DMA3_INT_PRI_1                   0xFFF9
#define DMA3_INT_PRI_2                   0xFFFA
#define DMA3_INT_PRI_3                   0xFFFB
#define DMA3_INT_PRI_4                   0xFFFC
#define DMA3_INT_PRI_5                   0xFFFD
#define DMA3_INT_PRI_6                   0xFFFE
#define DMA3_INT_PRI_7                   0xFFFF



/* Setting the priority of DMA4 interrupt */
#define DMA4_INT_PRI_0                   0xFFF8
#define DMA4_INT_PRI_1                   0xFFF9
#define DMA4_INT_PRI_2                   0xFFFA
#define DMA4_INT_PRI_3                   0xFFFB
#define DMA4_INT_PRI_4                   0xFFFC
#define DMA4_INT_PRI_5                   0xFFFD
#define DMA4_INT_PRI_6                   0xFFFE
#define DMA4_INT_PRI_7                   0xFFFF



/* Setting the priority of DMA5 interrupt */
#define DMA5_INT_PRI_0                   0xFFF8
#define DMA5_INT_PRI_1                   0xFFF9
#define DMA5_INT_PRI_2                   0xFFFA
#define DMA5_INT_PRI_3                   0xFFFB
#define DMA5_INT_PRI_4                   0xFFFC
#define DMA5_INT_PRI_5                   0xFFFD
#define DMA5_INT_PRI_6                   0xFFFE
#define DMA5_INT_PRI_7                   0xFFFF




/* Setting the priority of DMA6 interrupt */
#define DMA6_INT_PRI_0                   0xFFF8
#define DMA6_INT_PRI_1                   0xFFF9
#define DMA6_INT_PRI_2                   0xFFFA
#define DMA6_INT_PRI_3                   0xFFFB
#define DMA6_INT_PRI_4                   0xFFFC
#define DMA6_INT_PRI_5                   0xFFFD
#define DMA6_INT_PRI_6                   0xFFFE
#define DMA6_INT_PRI_7                   0xFFFF

/* Setting the priority of DMA7 interrupt */
#define DMA7_INT_PRI_0                   0xFFF8
#define DMA7_INT_PRI_1                   0xFFF9
#define DMA7_INT_PRI_2                   0xFFFA
#define DMA7_INT_PRI_3                   0xFFFB
#define DMA7_INT_PRI_4                   0xFFFC
#define DMA7_INT_PRI_5                   0xFFFD
#define DMA7_INT_PRI_6                   0xFFFE
#define DMA7_INT_PRI_7                   0xFFFF




/* enable / disable interrupts for DMA0*/

#define DMA0_INT_ENABLE                  0xFFFF
#define DMA0_INT_DISABLE                 0xFFEF

/* Macros to  Enable/Disable interrupts and set Interrupt priority for DMA0 */

#define EnableIntDMA0                    asm("BSET IEC0,#4")
#define DisableIntDMA0                   asm("BCLR IEC0,#4")
#define SetPriorityIntDMA0(priority)     (IPC1bits.DMA0IP = priority)


/* enable / disable interrupts for DMA1*/

#define DMA1_INT_ENABLE                  0xFFFF
#define DMA1_INT_DISABLE                 0xBFFF

/* Macros to  Enable/Disable interrupts and set Interrupt priority for DMA1 */

#define EnableIntDMA1                    asm("BSET IEC0,#14")
#define DisableIntDMA1                   asm("BCLR IEC0,#14")
#define SetPriorityIntDMA1(priority)     (IPC3bits.DMA1IP = priority)




/* enable / disable interrupts for DMA2*/

#define DMA2_INT_ENABLE                  0xFFFF
#define DMA2_INT_DISABLE                 0xFEFF

/* Macros to  Enable/Disable interrupts and set Interrupt priority for DMA2 */

#define EnableIntDMA2                    asm("BSET IEC1,#8")
#define DisableIntDMA2                   asm("BCLR IEC1,#8")
#define SetPriorityIntDMA2(priority)     (IPC6bits.DMA2IP = priority)



/* enable / disable interrupts for DMA3*/

#define DMA3_INT_ENABLE                  0xFFFF
#define DMA3_INT_DISABLE                 0xFFEF

/* Macros to  Enable/Disable interrupts and set Interrupt priority for DMA3 */

#define EnableIntDMA3                    asm("BSET IEC2,#4")
#define DisableIntDMA3                   asm("BCLR IEC2,#4")
#define SetPriorityIntDMA3(priority)     (IPC9bits.DMA3IP = priority)



/* enable / disable interrupts for DMA4*/

#define DMA4_INT_ENABLE                  0xFFFF
#define DMA4_INT_DISABLE                 0x7FFF

/* Macros to  Enable/Disable interrupts and set Interrupt priority for DMA4 */

#define EnableIntDMA4                    asm("BSET IEC2,#14")
#define DisableIntDMA4                   asm("BCLR IEC2,#14")
#define SetPriorityIntDMA4(priority)     (IPC11bits.DMA4IP = priority)



/* enable / disable interrupts for DMA5*/

#define DMA5_INT_ENABLE                  0xFFFF
#define DMA5_INT_DISABLE                 0xDFFF

/* Macros to  Enable/Disable interrupts and set Interrupt priority for DMA5 */

#define EnableIntDMA5                    asm("BSET IEC3,#13")
#define DisableIntDMA5                   asm("BCLR IEC3,#13")
#define SetPriorityIntDMA5(priority)     (IPC15bits.DMA5IP = priority)


/* enable / disable interrupts for DMA6*/

#define DMA6_INT_ENABLE                  0xFFFF
#define DMA6_INT_DISABLE                 0xFFEF

/* Macros to  Enable/Disable interrupts and set Interrupt priority for DMA6 */

#define EnableIntDMA6                    asm("BSET IEC4,#4")
#define DisableIntDMA6                   asm("BCLR IEC4,#4")
#define SetPriorityIntDMA6(priority)     (IPC17bits.DMA6IP = priority)



/* enable / disable interrupts for DMA7*/

#define DMA7_INT_ENABLE                  0xFFFF
#define DMA7_INT_DISABLE                 0xFFDF

/* Macros to  Enable/Disable interrupts and set Interrupt priority for DMA7 */

#define EnableIntDMA7                    asm("BSET IEC4,#5")
#define DisableIntDMA7                   asm("BCLR IEC4,#5")
#define SetPriorityIntDMA7(priority)     (IPC17bits.DMA7IP = priority)




/* DMA Function Prototypes */



void CloseDMA0(void) __attribute__ ((section (".libperi")));	/*Close DMA0 channel */
void CloseDMA1(void) __attribute__ ((section (".libperi")));	/*Close DMA1 channel */
void CloseDMA2(void) __attribute__ ((section (".libperi")));	/*Close DMA2 channel */
void CloseDMA3(void) __attribute__ ((section (".libperi")));	/*Close DMA3 channel */
void CloseDMA4(void) __attribute__ ((section (".libperi")));	/*Close DMA4 channel */
void CloseDMA5(void) __attribute__ ((section (".libperi")));	/*Close DMA5 channel */
void CloseDMA6(void) __attribute__ ((section (".libperi")));	/*Close DMA6 channel */
void CloseDMA7(void) __attribute__ ((section (".libperi")));	/*Close DMA7 channel */

void ConfigIntDMA0(unsigned int config) __attribute__ ((section (".libperi")));	
				/* Set interrupt priority and enable/disable for DMA0 channel */

void ConfigIntDMA1(unsigned int config) __attribute__ ((section (".libperi")));	
				/* Set interrupt priority and enable/disable for DMA1 channel */

void ConfigIntDMA2(unsigned int config) __attribute__ ((section (".libperi")));	
				/* Set interrupt priority and enable/disable for DMA2 channel */

void ConfigIntDMA3(unsigned int config) __attribute__ ((section (".libperi")));	
				/* Set interrupt priority and enable/disable for DMA3 channel */

void ConfigIntDMA4(unsigned int config) __attribute__ ((section (".libperi")));	
				/* Set interrupt priority and enable/disable for DMA4 channel */

void ConfigIntDMA5(unsigned int config) __attribute__ ((section (".libperi")));	
				/* Set interrupt priority and enable/disable for DMA5 channel */

void ConfigIntDMA6(unsigned int config) __attribute__ ((section (".libperi")));	
				/* Set interrupt priority and enable/disable for DMA6 channel */

void ConfigIntDMA7(unsigned int config) __attribute__ ((section (".libperi")));	
				/* Set interrupt priority and enable/disable for DMA7 channel */


unsigned int DMARAMAddress(void) __attribute__ ((section (".libperi"))); 
				/* returns the recent DMA RAM address */

char LastDMAActive(void) __attribute__ ((section (".libperi"))); /* returns the last DMA active channel*/

void OpenDMA0(unsigned int config,unsigned int irq,unsigned int sta_address,
		unsigned int stb_address,unsigned int pad_adress,unsigned int count ) __attribute__ ((section (".libperi")));
			/* configures the DMA0 registers: DMA0CON, DMA0REQ, DMA0STA, DMA0STB, DMA0PAD, DMA0CNT*/


void OpenDMA1(unsigned int config,unsigned int irq,unsigned int sta_address,
		unsigned int stb_address,unsigned int pad_adress,unsigned int count ) __attribute__ ((section (".libperi")));
			/* configures the DMA1 registers: DMA1CON, DMA1REQ, DMA1STA, DMA1STB, DMA1PAD, DMA1CNT*/


void OpenDMA2(unsigned int config,unsigned int irq,unsigned int sta_address,
		unsigned int stb_address,unsigned int pad_adress,unsigned int count ) __attribute__ ((section (".libperi")));
			/* configures the DMA2 registers: DMA2CON, DMA2REQ, DMA2STA, DMA2STB, DMA2PAD, DMA2CNT*/
void OpenDMA3(unsigned int config,unsigned int irq,unsigned int sta_address,
		unsigned int stb_address,unsigned int pad_adress,unsigned int count ) __attribute__ ((section (".libperi")));
			/* configures the DMA3 registers: DMA3CON, DMA3REQ, DMA3STA, DMA3STB, DMA3PAD, DMA3CNT*/

void OpenDMA4(unsigned int config,unsigned int irq,unsigned int sta_address,
		unsigned int stb_address,unsigned int pad_adress,unsigned int count ) __attribute__ ((section (".libperi")));
			/* configures the DMA4 registers: DMA4CON, DMA4REQ, DMA4STA, DMA4STB, DMA4PAD, DMA4CNT*/

void OpenDMA5(unsigned int config,unsigned int irq,unsigned int sta_address,
		unsigned int stb_address,unsigned int pad_adress,unsigned int count ) __attribute__ ((section (".libperi")));
			/* configures the DMA5 registers: DMA5CON, DMA5REQ, DMA5STA, DMA5STB, DMA5PAD, DMA5CNT*/

void OpenDMA6(unsigned int config,unsigned int irq,unsigned int sta_address,
		unsigned int stb_address,unsigned int pad_adress,unsigned int count ) __attribute__ ((section (".libperi")));
			/* configures the DMA6 registers: DMA6CON, DMA6REQ, DMA6STA, DMA6STB, DMA6PAD, DMA6CNT*/

void OpenDMA7(unsigned int config,unsigned int irq,unsigned int sta_address,
		unsigned int stb_address,unsigned int pad_adress,unsigned int count ) __attribute__ ((section (".libperi")));
			/* configures the DMA7 registers: DMA7CON, DMA7REQ, DMA7STA, DMA7STB, DMA7PAD, DMA7CNT*/


char PingPongStatusDMA0(void) __attribute__ ((section (".libperi")));  /* returns the register selected for ping-pong*/
char PingPongStatusDMA1(void) __attribute__ ((section (".libperi")));  /* returns the register selected for ping-pong*/
char PingPongStatusDMA2(void) __attribute__ ((section (".libperi")));  /* returns the register selected for ping-pong*/
char PingPongStatusDMA3(void) __attribute__ ((section (".libperi")));  /* returns the register selected for ping-pong*/
char PingPongStatusDMA4(void) __attribute__ ((section (".libperi")));  /* returns the register selected for ping-pong*/
char PingPongStatusDMA5(void) __attribute__ ((section (".libperi")));  /* returns the register selected for ping-pong*/
char PingPongStatusDMA6(void) __attribute__ ((section (".libperi")));  /* returns the register selected for ping-pong*/
char PingPongStatusDMA7(void) __attribute__ ((section (".libperi")));  /* returns the register selected for ping-pong*/



char WriteCollisionDMA0(void) __attribute__ ((section (".libperi"))); 
						 /* returns the channel 0 DMA RAM write collision detect */
char WriteCollisionDMA1(void) __attribute__ ((section (".libperi")));  
						/* returns the channel 1 DMA RAM write collision detect */
								      
char WriteCollisionDMA2(void) __attribute__ ((section (".libperi")));  
						/* returns the channel 2 DMA RAM write collision detect */

char WriteCollisionDMA3(void) __attribute__ ((section (".libperi")));  
						/* returns the channel 3 DMA RAM write collision detect */

char WriteCollisionDMA4(void) __attribute__ ((section (".libperi")));  
						/* returns the channel 4 DMA RAM write collision detect */

char WriteCollisionDMA5(void) __attribute__ ((section (".libperi")));  
						/* returns the channel 5 DMA RAM write collision detect */

char WriteCollisionDMA6(void) __attribute__ ((section (".libperi")));  
						/* returns the channel 6 DMA RAM write collision detect */

char WriteCollisionDMA7(void) __attribute__ ((section (".libperi")));  
						/* returns the channel 7 DMA RAM write collision detect */


char WriteCollisionPeripheral0(void) __attribute__ ((section (".libperi")));
						/*  returns the channel0 peripheral write collision flag bit*/


char WriteCollisionPeripheral1(void) __attribute__ ((section (".libperi")));
						/*  returns the channel1 peripheral write collision flag bit*/

char WriteCollisionPeripheral2(void) __attribute__ ((section (".libperi")));
						/*  returns the channel2 peripheral write collision flag bit*/


char WriteCollisionPeripheral3(void) __attribute__ ((section (".libperi")));
						/*  returns the channel3 peripheral write collision flag bit*/


char WriteCollisionPeripheral4(void) __attribute__ ((section (".libperi")));
						/*  returns the channel4 peripheral write collision flag bit*/


char WriteCollisionPeripheral5(void) __attribute__ ((section (".libperi")));
						/*  returns the channel5 peripheral write collision flag bit*/


char WriteCollisionPeripheral6(void) __attribute__ ((section (".libperi")));
						/*  returns the channel6 peripheral write collision flag bit*/


char WriteCollisionPeripheral7(void) __attribute__ ((section (".libperi")));
						/*  returns the channel7 peripheral write collision flag bit*/





#endif

