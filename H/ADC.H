/********************************************************************/
/*              Header for 12 bit ADC module library functions      */
/********************************************************************/

#ifndef __ADC_H
#define __ADC_H

/* List of SFRs for ADC */
/* This list contains the SFRs with default (POR) values to be used for configuring ADC */
/* The user can modify this based on the requirement */


#define AD1CON1_VALUE                0x0000
#define AD1CON2_VALUE                0x0000
#define AD1CON3_VALUE                0x0000
#define AD1CON4_VALUE		     0x0000
#define AD1CHS123_VALUE              0x0000
#define AD1CH0_VALUE		     0x0000
#define AD1CHSS_VALUE		     0x0000
#define AD1CSSL_VALUE                0x0000
#define AD1PCFGH_VALUE               0x0000
#define AD1PCFGL_VALUE               0x0000

#if defined(__dsPIC33FJ64GP706__) || defined(__dsPIC33FJ64GP708__) ||defined(__dsPIC33FJ64GP710__) ||\
defined(__dsPIC33FJ128GP706__) ||defined(__dsPIC33FJ128GP708__) ||defined(__dsPIC33FJ128GP710__) ||\
defined(__dsPIC33FJ256GP710__) ||defined(__dsPIC33FJ128GP706PS__) ||defined(__dsPIC33FJ128GP708PS__) ||\
defined(__dsPIC33FJ256GP710PS__) ||defined(__dsPIC33FJ64MC706__) ||defined(__dsPIC33FJ64MC710__) ||\
defined(__dsPIC33FJ128MC706__) ||defined(__dsPIC33FJ128MC708__) ||defined(__dsPIC33FJ128MC710__) ||\
defined(__dsPIC33FJ256MC710__) ||defined(__dsPIC33FJ128MC706PS__) ||defined(__dsPIC33FJ128MC708PS__) ||\
defined(__dsPIC33FJ256MC710PS__) ||defined(__PIC24HJ256GP610__)



	#define AD2CON1_VALUE                0x0000
	#define AD2CON2_VALUE                0x0000
	#define AD2CON3_VALUE                0x0000
	#define AD2CON4_VALUE		     0x0000
	#define AD2CHS123_VALUE              0x0000
	#define AD2CH0_VALUE		     0x0000
	#define AD2CHSS_VALUE		     0x0000
	#define AD2CSSL_VALUE                0x0000
	#define AD2PCFGH_VALUE               0x0000
	#define AD2PCFGL_VALUE               0x0000
#endif

/* AD1CON1 Configuration Bit Definitions */

#define ADC_MODULE_ON               0xFFFF /* A/D Converter on */
#define ADC_MODULE_OFF              0x7FFF /* A/D Converter off */

#define ADC_IDLE_CONTINUE           0xDFFF /* A/D Operate in Idle mode */
#define ADC_IDLE_STOP               0xFFFF /* A/D Stop in Idle mode */

#define ADC_ADDMABM_ORDER	    0XFFFF	/*DMA buffers are written in the order of conversion */
#define ADC_ADDMABM_SCATTR	    0xEFFF	/* DMA buffers are written in Scatter/Gather mode */

#define ADC_AD12B_12BIT		    0xFFFF	/* 12 bit, 1-channel ADC operation */
#define ADC_AD12B_10BIT		    0xFBFF	/* 10 bit, 4-channel ADC operation */

#define ADC_FORMAT_SIGN_FRACT       0xFFFF /* A/D data format signed fractional */
#define ADC_FORMAT_FRACT            0xFEFF /* A/D data format fractional */
#define ADC_FORMAT_SIGN_INT         0xFDFF /* A/D data format signed integer */
#define ADC_FORMAT_INTG             0xFCFF /* A/D data format integer */

/* SSRC<2:0> bit defines */

#define ADC_CLK_AUTO                0xFFFF	/* Internal counter ends sampling and starts conversion (Auto convert) */
#define ADC_CLK_MPWM                0xFF7F	/* MPWM interval ends sampling and starts conversion */
#define ADC_CLK_TMR                 0xFF5F	/* GP Timer compare ends sampling and starts conversion */
#define ADC_CLK_INT0                0xFF3F	/* Active transition on INTx ends sampling and starts conversion */
#define ADC_CLK_MANUAL              0xFF1F	/* Clearing sample (SAMP) bit ends sampling and starts conversion */


#define ADC_SIMULTANEOUS	    0xFFFF	/* Simultaneously sampling of CH0, CH1, CH2 and CH3 bsed upon CHPS and AD12B bits*/
#define ADC_MULTIPLE		    0XFFF7	/* Samples multiple channels individually in sequence */

#define ADC_AUTO_SAMPLING_ON        0xFFFF	/* Sampling begins immediately after last conversion */
#define ADC_AUTO_SAMPLING_OFF       0xFFFB	/* Sampling begins when SAMP bit is set */



#define ADC_SAMP_ON                 0xFFFF	/* sample / hold amplifiers are sampling */
#define ADC_SAMP_OFF                0xFFFD	/* sample / hold amplifiers are holding */


/* defines for the ADCON2 register */


#define ADC_VREF_AVDD_AVSS          0x0FFF	/* A/D Voltage reference configuration Vref+ is AVdd and Vref- is AVss */
#define ADC_VREF_EXT_AVSS           0x2FFF	/* A/D Voltage reference configuration Vref+ external and Vref- is AVss */
#define ADC_VREF_AVDD_EXT           0x4FFF	/* A/D Voltage reference configuration Vref+ AVdd and Vref- external */
#define ADC_VREF_EXT_EXT            0x6FFF	/* A/D Voltage reference configuration both Vref+ and Vref- are external */

#define ADC_SCAN_ON                 0xEFFF	/* A/D Scan Input Selections for CH0 during SAMPLE A */
#define ADC_SCAN_OFF                0xEBFF	/* A/D Do notScan Input Selections for CH0+ during SAMPLE A */


#define ADC_SELECT_CHAN_0123	    0xEFFF	/* Converts CH0, CH1, CH2 and CH3 */
#define ADC_SELECT_CHAN_01	    0xEDFF	/* Converts CH0 and CH1 */
#define ADC_SELECT_CHAN_0	    0xECFF	/* Converts CH0 */

#define ADC_BUF_FILL_0x8_0xF	    0xEFFF	/*ADC is currently filling buffer 0x8-0xF*/
#define ADC_BUF_FILL_0x0_0x7        0xEF7F	/*ADC is currently filling buffer 0x0-0x7 */




#define ADC_DMA_ADD_INC_1       0xEFC3	/* DMA address increment after conversion of each sample */
#define ADC_DMA_ADD_INC_2       0xEFC7	/* DMA address increment after conversion of 2 samples */
#define ADC_DMA_ADD_INC_3       0xEFCB	/* DMA address increment after conversion of 3 samples */
#define ADC_DMA_ADD_INC_4       0xEFCF	/* DMA address increment after conversion of 4 samples */
#define ADC_DMA_ADD_INC_5       0xEFD3	/* DMA address increment after conversion of 5 samples */
#define ADC_DMA_ADD_INC_6       0xEFD7	/* DMA address increment after conversion of 6 samples */
#define ADC_DMA_ADD_INC_7       0xEFDB	/* DMA address increment after conversion of 7 samples */
#define ADC_DMA_ADD_INC_8       0xEFDF	/* DMA address increment after conversion of 8 samples */
#define ADC_DMA_ADD_INC_9       0xEFE3	/* DMA address increment after conversion of 9 samples */
#define ADC_DMA_ADD_INC_10      0xEFE7	/* DMA address increment after conversion of 10 samples */
#define ADC_DMA_ADD_INC_11      0xEFEB	/* DMA address increment after conversion of 11 samples */
#define ADC_DMA_ADD_INC_12      0xEFEF	/* DMA address increment after conversion of 12 samples */
#define ADC_DMA_ADD_INC_13      0xEFF3	/* DMA address increment after conversion of 13 samples */
#define ADC_DMA_ADD_INC_14      0xEFF7	/* DMA address increment after conversion of 14 samples */
#define ADC_DMA_ADD_INC_15      0xEFFB	/* DMA address increment after conversion of 15 samples */
#define ADC_DMA_ADD_INC_16      0xEFFF	/* DMA address increment after conversion of 16 samples */


/* BUFM bit defines */

#define ADC_ALT_BUF_ON              0xEFFF /* Buffer configured as 2 8-word buffers */
#define ADC_ALT_BUF_OFF             0xEFFD /* Buffer configured as 1 16-word buffer */

/* A/D Uses channel input selects for SAMPLE A on first sample and SAMPLE B on next sample */
#define ADC_ALT_INPUT_ON            0xEFFF /* alternate between MUXA and MUXB */

/* A/D Always uses channel input selects for SAMPLE A */
#define ADC_ALT_INPUT_OFF           0xEFFE /* use MUXA only */



/* defines for ADCON3 register */
#define ADC_SAMPLE_TIME_0           0xE0FF /* A/D Auto Sample Time 0 Tad */
#define ADC_SAMPLE_TIME_1           0xE1FF /* A/D Auto Sample Time 1 Tad */
#define ADC_SAMPLE_TIME_2           0xE2FF /* A/D Auto Sample Time 2 Tad */
#define ADC_SAMPLE_TIME_3           0xE3FF /* A/D Auto Sample Time 3 Tad */
#define ADC_SAMPLE_TIME_4           0xE4FF /* A/D Auto Sample Time 4 Tad */
#define ADC_SAMPLE_TIME_5           0xE5FF /* A/D Auto Sample Time 5 Tad */
#define ADC_SAMPLE_TIME_6           0xE6FF /* A/D Auto Sample Time 6 Tad */
#define ADC_SAMPLE_TIME_7           0xE7FF /* A/D Auto Sample Time 7 Tad */
#define ADC_SAMPLE_TIME_8           0xE8FF /* A/D Auto Sample Time 8 Tad */
#define ADC_SAMPLE_TIME_9           0xE9FF /* A/D Auto Sample Time 9 Tad */
#define ADC_SAMPLE_TIME_10          0xEAFF /* A/D Auto Sample Time 10 Tad */
#define ADC_SAMPLE_TIME_11          0xEBFF /* A/D Auto Sample Time 11 Tad */
#define ADC_SAMPLE_TIME_12          0xECFF /* A/D Auto Sample Time 12 Tad */
#define ADC_SAMPLE_TIME_13          0xEDFF /* A/D Auto Sample Time 13 Tad */
#define ADC_SAMPLE_TIME_14          0xEEFF /* A/D Auto Sample Time 14 Tad */
#define ADC_SAMPLE_TIME_15          0xEFFF /* A/D Auto Sample Time 15 Tad */
#define ADC_SAMPLE_TIME_16          0xF0FF /* A/D Auto Sample Time 16 Tad */
#define ADC_SAMPLE_TIME_17          0xF1FF /* A/D Auto Sample Time 17 Tad */
#define ADC_SAMPLE_TIME_18          0xF2FF /* A/D Auto Sample Time 18 Tad */
#define ADC_SAMPLE_TIME_19          0xF3FF /* A/D Auto Sample Time 19 Tad */
#define ADC_SAMPLE_TIME_20          0xF4FF /* A/D Auto Sample Time 20 Tad */
#define ADC_SAMPLE_TIME_21          0xF5FF /* A/D Auto Sample Time 21 Tad */
#define ADC_SAMPLE_TIME_22          0xF6FF /* A/D Auto Sample Time 22 Tad */
#define ADC_SAMPLE_TIME_23          0xF7FF /* A/D Auto Sample Time 23 Tad */
#define ADC_SAMPLE_TIME_24          0xF8FF /* A/D Auto Sample Time 24 Tad */
#define ADC_SAMPLE_TIME_25          0xF9FF /* A/D Auto Sample Time 25 Tad */
#define ADC_SAMPLE_TIME_26          0xFAFF /* A/D Auto Sample Time 26 Tad */
#define ADC_SAMPLE_TIME_27          0xFBFF /* A/D Auto Sample Time 27 Tad */
#define ADC_SAMPLE_TIME_28          0xFCFF /* A/D Auto Sample Time 28 Tad */
#define ADC_SAMPLE_TIME_29          0xFDFF /* A/D Auto Sample Time 29 Tad */
#define ADC_SAMPLE_TIME_30          0xFEFF /* A/D Auto Sample Time 30 Tad */
#define ADC_SAMPLE_TIME_31          0xFFFF /* A/D Auto Sample Time 31 Tad */

/* A/D Conversion Clock Source internal RC Clock */
#define ADC_CONV_CLK_INTERNAL_RC    0xFFFF
/* A/D Conversion Clock Source Clock derived from system clock */
#define ADC_CONV_CLK_SYSTEM         0xFF7F

/* A/D conversion clock select bit ADCS<5:0>*/
#define ADC_CONV_CLK_32Tcy          0xFFFF  /* A/D Conversion Clock Select bits */
#define ADC_CONV_CLK_63Tcy2         0xFFFE  /* A/D Conversion Clock Select bits */
#define ADC_CONV_CLK_31Tcy          0xFFFD  /* A/D Conversion Clock Select bits */
#define ADC_CONV_CLK_61Tcy2         0xFFFC  /* A/D Conversion Clock Select bits */
#define ADC_CONV_CLK_30Tcy          0xFFFB
#define ADC_CONV_CLK_59Tcy2         0xFFFA
#define ADC_CONV_CLK_29Tcy          0xFFF9
#define ADC_CONV_CLK_57Tcy2         0xFFF8
#define ADC_CONV_CLK_28Tcy          0xFFF7
#define ADC_CONV_CLK_55Tcy2         0xFFF6
#define ADC_CONV_CLK_27Tcy          0xFFF5
#define ADC_CONV_CLK_53Tcy2         0xFFF4
#define ADC_CONV_CLK_26Tcy          0xFFF3
#define ADC_CONV_CLK_51Tcy2         0xFFF2
#define ADC_CONV_CLK_25Tcy          0xFFF1
#define ADC_CONV_CLK_49Tcy2         0xFFF0
#define ADC_CONV_CLK_24Tcy          0xFFEF
#define ADC_CONV_CLK_47Tcy2         0xFFEE
#define ADC_CONV_CLK_23Tcy          0xFFED
#define ADC_CONV_CLK_45Tcy2         0xFFEC
#define ADC_CONV_CLK_22Tcy          0xFFEB
#define ADC_CONV_CLK_43Tcy2         0xFFEA
#define ADC_CONV_CLK_21Tcy          0xFFE9
#define ADC_CONV_CLK_41Tcy2         0xFFE8
#define ADC_CONV_CLK_20Tcy          0xFFE7
#define ADC_CONV_CLK_39Tcy2         0xFFE6
#define ADC_CONV_CLK_19Tcy          0xFFE5
#define ADC_CONV_CLK_37Tcy2         0xFFE4
#define ADC_CONV_CLK_18Tcy          0xFFE3
#define ADC_CONV_CLK_35Tcy2         0xFFE2
#define ADC_CONV_CLK_17Tcy          0xFFE1
#define ADC_CONV_CLK_33Tcy2         0xFFE0
#define ADC_CONV_CLK_16Tcy          0xFFDF
#define ADC_CONV_CLK_31Tcy2         0xFFDE
#define ADC_CONV_CLK_15Tcy          0xFFDD
#define ADC_CONV_CLK_29Tcy2         0xFFDC
#define ADC_CONV_CLK_14Tcy          0xFFDB
#define ADC_CONV_CLK_27Tcy2         0xFFDA
#define ADC_CONV_CLK_13Tcy          0xFFD9
#define ADC_CONV_CLK_25Tcy2         0xFFD8
#define ADC_CONV_CLK_12Tcy          0xFFD7
#define ADC_CONV_CLK_23Tcy2         0xFFD6
#define ADC_CONV_CLK_11Tcy          0xFFD5
#define ADC_CONV_CLK_21Tcy2         0xFFD4
#define ADC_CONV_CLK_10Tcy          0xFFD3
#define ADC_CONV_CLK_19Tcy2         0xFFD2
#define ADC_CONV_CLK_9Tcy           0xFFD1
#define ADC_CONV_CLK_17Tcy2         0xFFD0
#define ADC_CONV_CLK_8Tcy           0xFFCF
#define ADC_CONV_CLK_15Tcy2         0xFFCE
#define ADC_CONV_CLK_7Tcy           0xFFCD
#define ADC_CONV_CLK_13Tcy2         0xFFCC
#define ADC_CONV_CLK_6Tcy           0xFFCB
#define ADC_CONV_CLK_11Tcy2         0xFFCA
#define ADC_CONV_CLK_5Tcy           0xFFC9
#define ADC_CONV_CLK_9Tcy2          0xFFC8
#define ADC_CONV_CLK_4Tcy           0xFFC7
#define ADC_CONV_CLK_7Tcy2          0xFFC6
#define ADC_CONV_CLK_3Tcy           0xFFC5
#define ADC_CONV_CLK_5Tcy2          0xFFC4
#define ADC_CONV_CLK_2Tcy           0xFFC3
#define ADC_CONV_CLK_3Tcy2          0xFFC2
#define ADC_CONV_CLK_Tcy            0xFFC1  /* A/D Conversion Clock Select bits */
#define ADC_CONV_CLK_Tcy2           0xFFC0  /* A/D Conversion Clock Select bits */


/* ADxCON4 register */

#define ADC_DMA_BUF_LOC_128	    0xFFFF	/* Allocates words of buffer to each analog input */
#define ADC_DMA_BUF_LOC_64	    0xFFFE	/* Allocates words of buffer to each analog input */
#define ADC_DMA_BUF_LOC_32	    0xFFFD	/* Allocates words of buffer to each analog input */
#define ADC_DMA_BUF_LOC_16	    0xFFFC	/* Allocates words of buffer to each analog input */
#define ADC_DMA_BUF_LOC_8	    0xFFFB	/* Allocates words of buffer to each analog input */
#define ADC_DMA_BUF_LOC_4	    0xFFFA	/* Allocates words of buffer to each analog input */
#define ADC_DMA_BUF_LOC_2	    0xFFF9	/* Allocates words of buffer to each analog input */
#define ADC_DMA_BUF_LOC_1	    0xFFF8	/* Allocates words of buffer to each analog input */





/* ADCx Input CHANNEL 1,2,3 select register (ADxCHS123) configuration defines */


#define ADC_CH123_NEG_SAMPLEB_9_10_11	0xFFFF	/* A/D CH1 neg i/p is AN9 , CH2 neg i/p is AN10, CH3 neg i/p is AN11*/
#define ADC_CH123_NEG_SAMPLEB_6_7_8	0xFDFF	/* A/D CH1 neg i/p is AN6 , CH2 neg i/p is AN7, CH3 neg i/p is AN8*/
#define ADC_CH123_NEG_SAMPLEB_VREFN	0xF9FF	/* A/D CH1 , CH2 and CH3 neg i/p is Vref-*/

#define ADC_CH123_POS_SAMPLEB_3_4_5	0xFFFF	/* A/D CH1 pos i/p is AN3, CH2 pos i/p is AN4, CH3 pos i/p is AN5*/
#define ADC_CH123_POS_SAMPLEB_0_1_2	0xFEFF	/* A/D CH1 pos i/p is AN0, CH2 pos i/p is AN1, CH3 pos i/p is AN2*/


#define ADC_CH123_NEG_SAMPLEA_9_10_11	0xFFFF	/* A/D CH1 neg i/p is AN9 , CH2 neg i/p is AN10, CH3 neg i/p is AN11*/
#define ADC_CH123_NEG_SAMPLEA_6_7_8	0xFFFD	/* A/D CH1 neg i/p is AN6 , CH2 neg i/p is AN7, CH3 neg i/p is AN8*/
#define ADC_CH123_NEG_SAMPLEA_VREFN	0xFFF9	/* A/D CH1 , CH2 and CH3 neg i/p is Vref-*/

#define ADC_CH123_POS_SAMPLEA_3_4_5	0xFFFF	/* A/D CH1 pos i/p is AN3, CH2 pos i/p is AN4, CH3 pos i/p is AN5*/
#define ADC_CH123_POS_SAMPLEA_0_1_2	0xFFFE	/* A/D CH1 pos i/p is AN0, CH2 pos i/p is AN1, CH3 pos i/p is AN2*/



/* ADCx Input channel 0 select register */

#define ADC_CH0_NEG_SAMPLEB_AN1		0xFFFF	/* CH0 negative input is AN1 */
#define ADC_CH0_NEG_SAMPLEB_VREFN	0x7FFF	/* CH0 negative input is VREF- */

#define ADC_CH0_POS_SAMPLEB_AN31	0xFFFF	/* A/D CH0 pos i/p sel for SAMPLE B is AN31 */
#define ADC_CH0_POS_SAMPLEB_AN30	0xFEFF	/* A/D CH0 pos i/p sel for SAMPLE B is AN30 */
#define ADC_CH0_POS_SAMPLEB_AN29	0xFDFF	/* A/D CH0 pos i/p sel for SAMPLE B is AN29 */
#define ADC_CH0_POS_SAMPLEB_AN28	0xFCFF	/* A/D CH0 pos i/p sel for SAMPLE B is AN28 */
#define ADC_CH0_POS_SAMPLEB_AN27	0xFBFF	/* A/D CH0 pos i/p sel for SAMPLE B is AN27 */
#define ADC_CH0_POS_SAMPLEB_AN26	0xFAFF	/* A/D CH0 pos i/p sel for SAMPLE B is AN26 */
#define ADC_CH0_POS_SAMPLEB_AN25	0xF9FF	/* A/D CH0 pos i/p sel for SAMPLE B is AN25 */
#define ADC_CH0_POS_SAMPLEB_AN24	0xF8FF	/* A/D CH0 pos i/p sel for SAMPLE B is AN24 */
#define ADC_CH0_POS_SAMPLEB_AN23	0xF7FF	/* A/D CH0 pos i/p sel for SAMPLE B is AN23 */
#define ADC_CH0_POS_SAMPLEB_AN22	0xF6FF	/* A/D CH0 pos i/p sel for SAMPLE B is AN22 */
#define ADC_CH0_POS_SAMPLEB_AN21	0xF5FF	/* A/D CH0 pos i/p sel for SAMPLE B is AN21 */
#define ADC_CH0_POS_SAMPLEB_AN20	0xF4FF	/* A/D CH0 pos i/p sel for SAMPLE B is AN20 */
#define ADC_CH0_POS_SAMPLEB_AN19	0xF3FF	/* A/D CH0 pos i/p sel for SAMPLE B is AN19 */
#define ADC_CH0_POS_SAMPLEB_AN18	0xF2FF	/* A/D CH0 pos i/p sel for SAMPLE B is AN18 */
#define ADC_CH0_POS_SAMPLEB_AN17	0xF1FF	/* A/D CH0 pos i/p sel for SAMPLE B is AN17 */
#define ADC_CH0_POS_SAMPLEB_AN16	0xF0FF	/* A/D CH0 pos i/p sel for SAMPLE B is AN16 */
#define ADC_CH0_POS_SAMPLEB_AN15	0xEFFF	/* A/D CH0 pos i/p sel for SAMPLE B is AN15 */
#define ADC_CH0_POS_SAMPLEB_AN14	0xEEFF	/* A/D CH0 pos i/p sel for SAMPLE B is AN14 */
#define ADC_CH0_POS_SAMPLEB_AN13	0xEDFF	/* A/D CH0 pos i/p sel for SAMPLE B is AN13 */
#define ADC_CH0_POS_SAMPLEB_AN12	0xECFF	/* A/D CH0 pos i/p sel for SAMPLE B is AN12 */
#define ADC_CH0_POS_SAMPLEB_AN11	0xEBFF	/* A/D CH0 pos i/p sel for SAMPLE B is AN11 */
#define ADC_CH0_POS_SAMPLEB_AN10	0xEAFF	/* A/D CH0 pos i/p sel for SAMPLE B is AN10 */
#define ADC_CH0_POS_SAMPLEB_AN9		0xE9FF	/* A/D CH0 pos i/p sel for SAMPLE B is AN9 */
#define ADC_CH0_POS_SAMPLEB_AN8		0xE8FF	/* A/D CH0 pos i/p sel for SAMPLE B is AN8 */
#define ADC_CH0_POS_SAMPLEB_AN7		0xE7FF	/* A/D CH0 pos i/p sel for SAMPLE B is AN7 */
#define ADC_CH0_POS_SAMPLEB_AN6		0xE6FF	/* A/D CH0 pos i/p sel for SAMPLE B is AN6 */
#define ADC_CH0_POS_SAMPLEB_AN5		0xE5FF	/* A/D CH0 pos i/p sel for SAMPLE B is AN5 */
#define ADC_CH0_POS_SAMPLEB_AN4		0xE4FF	/* A/D CH0 pos i/p sel for SAMPLE B is AN4 */
#define ADC_CH0_POS_SAMPLEB_AN3		0xE3FF	/* A/D CH0 pos i/p sel for SAMPLE B is AN3 */
#define ADC_CH0_POS_SAMPLEB_AN2		0xE2FF	/* A/D CH0 pos i/p sel for SAMPLE B is AN2 */
#define ADC_CH0_POS_SAMPLEB_AN1		0xE1FF	/* A/D CH0 pos i/p sel for SAMPLE B is AN1 */
#define ADC_CH0_POS_SAMPLEB_AN0		0xE0FF	/* A/D CH0 pos i/p sel for SAMPLE B is AN0 */

#define ADC_CH0_NEG_SAMPLEA_AN1		0xFFFF	/*A/D CH0 neg I/P sel for SAMPLE A is AN1 */
#define ADC_CH0_NEG_SAMPLEA_VREFN	0xFF7F	/*A/D CH0 neg I/P sel for SAMPLE A is Vrefn */



#define ADC_CH0_POS_SAMPLEA_AN31    0xFFFF  /* A/D Chan 0 pos i/p sel for SAMPLE A is AN31 */
#define ADC_CH0_POS_SAMPLEA_AN30    0xFFFE  /* A/D Chan 0 pos i/p sel for SAMPLE A is AN30 */
#define ADC_CH0_POS_SAMPLEA_AN29    0xFFFD  /* A/D Chan 0 pos i/p sel for SAMPLE A is AN29 */
#define ADC_CH0_POS_SAMPLEA_AN28    0xFFFC  /* A/D Chan 0 pos i/p sel for SAMPLE A is AN28 */
#define ADC_CH0_POS_SAMPLEA_AN27    0xFFFB  /* A/D Chan 0 pos i/p sel for SAMPLE A is AN27 */
#define ADC_CH0_POS_SAMPLEA_AN26    0xFFFA  /* A/D Chan 0 pos i/p sel for SAMPLE A is AN26 */
#define ADC_CH0_POS_SAMPLEA_AN25    0xFFF9  /* A/D Chan 0 pos i/p sel for SAMPLE A is AN25 */   
#define ADC_CH0_POS_SAMPLEA_AN24    0xFFF8  /* A/D Chan 0 pos i/p sel for SAMPLE A is AN24 */   
#define ADC_CH0_POS_SAMPLEA_AN23    0xFFF7  /* A/D Chan 0 pos i/p sel for SAMPLE A is AN23 */ 
#define ADC_CH0_POS_SAMPLEA_AN22    0xFFF6  /* A/D Chan 0 pos i/p sel for SAMPLE A is AN22 */   
#define ADC_CH0_POS_SAMPLEA_AN21    0xFFF5  /* A/D Chan 0 pos i/p sel for SAMPLE A is AN21 */   
#define ADC_CH0_POS_SAMPLEA_AN20    0xFFF4  /* A/D Chan 0 pos i/p sel for SAMPLE A is AN20 */   
#define ADC_CH0_POS_SAMPLEA_AN19    0xFFF3  /* A/D Chan 0 pos i/p sel for SAMPLE A is AN19 */   
#define ADC_CH0_POS_SAMPLEA_AN18    0xFFF2  /* A/D Chan 0 pos i/p sel for SAMPLE A is AN18 */   
#define ADC_CH0_POS_SAMPLEA_AN17    0xFFF1  /* A/D Chan 0 pos i/p sel for SAMPLE A is AN17 */   
#define ADC_CH0_POS_SAMPLEA_AN16    0xFFF0  /* A/D Chan 0 pos i/p sel for SAMPLE A is AN16 */   
#define ADC_CH0_POS_SAMPLEA_AN15    0xFFEF  /* A/D Chan 0 pos i/p sel for SAMPLE A is AN15 */
#define ADC_CH0_POS_SAMPLEA_AN14    0xFFEE  /* A/D Chan 0 pos i/p sel for SAMPLE A is AN14 */
#define ADC_CH0_POS_SAMPLEA_AN13    0xFFED  /* A/D Chan 0 pos i/p sel for SAMPLE A is AN13 */
#define ADC_CH0_POS_SAMPLEA_AN12    0xFFEC  /* A/D Chan 0 pos i/p sel for SAMPLE A is AN12 */
#define ADC_CH0_POS_SAMPLEA_AN11    0xFFEB  /* A/D Chan 0 pos i/p sel for SAMPLE A is AN11 */
#define ADC_CH0_POS_SAMPLEA_AN10    0xFFEA  /* A/D Chan 0 pos i/p sel for SAMPLE A is AN10 */
#define ADC_CH0_POS_SAMPLEA_AN9     0xFFE9  /* A/D Chan 0 pos i/p sel for SAMPLE A is AN9 */   
#define ADC_CH0_POS_SAMPLEA_AN8     0xFFE8  /* A/D Chan 0 pos i/p sel for SAMPLE A is AN8 */   
#define ADC_CH0_POS_SAMPLEA_AN7     0xFFE7  /* A/D Chan 0 pos i/p sel for SAMPLE A is AN7 */ 
#define ADC_CH0_POS_SAMPLEA_AN6     0xFFE6  /* A/D Chan 0 pos i/p sel for SAMPLE A is AN6 */   
#define ADC_CH0_POS_SAMPLEA_AN5     0xFFE5  /* A/D Chan 0 pos i/p sel for SAMPLE A is AN5 */   
#define ADC_CH0_POS_SAMPLEA_AN4     0xFFE4  /* A/D Chan 0 pos i/p sel for SAMPLE A is AN4 */   
#define ADC_CH0_POS_SAMPLEA_AN3     0xFFE3  /* A/D Chan 0 pos i/p sel for SAMPLE A is AN3 */   
#define ADC_CH0_POS_SAMPLEA_AN2     0xFFE2  /* A/D Chan 0 pos i/p sel for SAMPLE A is AN2 */   
#define ADC_CH0_POS_SAMPLEA_AN1     0xFFE1  /* A/D Chan 0 pos i/p sel for SAMPLE A is AN1 */   
#define ADC_CH0_POS_SAMPLEA_AN0     0xFFE0  /* A/D Chan 0 pos i/p sel for SAMPLE A is AN0 */   




/* ADC read buffer starting point defines */
#define ADC_RESULT_FIRST                0x0000  /* A/D read results from 00h address */
#define ADC_RESULT_SECOND               0x0008  /* A/D read results from the 08h address */

/*defines for ADxCSSL register */

#define SKIP_SCAN_AN0                   0xFFFE /*Skip AN0 for Input Scan */
#define SKIP_SCAN_AN1                   0xFFFD /*Skip AN1 for Input Scan */    
#define SKIP_SCAN_AN2                   0xFFFB /*Skip AN2 for Input Scan */
#define SKIP_SCAN_AN3                   0xFFF7 /*Skip AN3 for Input Scan */
#define SKIP_SCAN_AN4                   0xFFEF /*Skip AN4 for Input Scan */
#define SKIP_SCAN_AN5                   0xFFDF /*Skip AN5 for Input Scan */    
#define SKIP_SCAN_AN6                   0xFFBF /*Skip AN6 for Input Scan */
#define SKIP_SCAN_AN7                   0xFF7F /*Skip AN7 for Input Scan */
#define SKIP_SCAN_AN8                   0xFEFF /*Skip AN8 for Input Scan */
#define SKIP_SCAN_AN9                   0xFDFF /*Skip AN9 for Input Scan */    
#define SKIP_SCAN_AN10                  0xFBFF /*Skip AN10 for Input Scan */
#define SKIP_SCAN_AN11                  0xF7FF /*Skip AN11 for Input Scan */
#define SKIP_SCAN_AN12                  0xEFFF /*Skip AN12 for Input Scan */
#define SKIP_SCAN_AN13                  0xDFFF /*Skip AN13 for Input Scan */   
#define SKIP_SCAN_AN14                  0xBFFF /*Skip AN14 for Input Scan */
#define SKIP_SCAN_AN15                  0x7FFF /*Skip AN15 for Input Scan */
 
/*defines for ADxCSSH register */

#define SKIP_SCAN_AN16                   0xFFFE /*Skip AN16 for Input Scan */
#define SKIP_SCAN_AN17                   0xFFFD /*Skip AN17 for Input Scan */    
#define SKIP_SCAN_AN18                   0xFFFB /*Skip AN18 for Input Scan */
#define SKIP_SCAN_AN19                   0xFFF7 /*Skip AN19 for Input Scan */
#define SKIP_SCAN_AN20                  0xFFEF /*Skip AN20 for Input Scan */
#define SKIP_SCAN_AN21                   0xFFDF /*Skip AN21 for Input Scan */    
#define SKIP_SCAN_AN22                   0xFFBF /*Skip AN22 for Input Scan */
#define SKIP_SCAN_AN23                   0xFF7F /*Skip AN23 for Input Scan */
#define SKIP_SCAN_AN24                   0xFEFF /*Skip AN24 for Input Scan */
#define SKIP_SCAN_AN25                   0xFDFF /*Skip AN25 for Input Scan */    
#define SKIP_SCAN_AN26                  0xFBFF /*Skip AN26 for Input Scan */
#define SKIP_SCAN_AN27                  0xF7FF /*Skip AN27 for Input Scan */
#define SKIP_SCAN_AN28                  0xEFFF /*Skip AN28 for Input Scan */
#define SKIP_SCAN_AN29                  0xDFFF /*Skip AN29 for Input Scan */   
#define SKIP_SCAN_AN30                  0xBFFF /*Skip AN30 for Input Scan */
#define SKIP_SCAN_AN31                  0x7FFF /*Skip AN31 for Input Scan */





#define SCAN_NONE_0_15                       0x0000 /*Skip AN0-AN15 for Input Scan */

#define SCAN_ALL_0_15                        0xFFFF /*Enable AN0-AN15 for Input Scan */

#define SCAN_NONE_16_31                       0x0000 /*Skip AN16-AN31 for Input Scan */

#define SCAN_ALL_16_31                        0xFFFF /*Enable AN16-AN31 for Input Scan */


/*defines for ADxPCFGH register */

#define ENABLE_AN16_ANA                 0xFFFE /*Enable AN16 in analog mode */
#define ENABLE_AN17_ANA                 0xFFFD /*Enable AN17 in analog mode */
#define ENABLE_AN18_ANA                 0xFFFB /*Enable AN18 in analog mode */
#define ENABLE_AN19_ANA                 0xFFF7 /*Enable AN19 in analog mode */
#define ENABLE_AN20_ANA                 0xFFEF /*Enable AN20 in analog mode */
#define ENABLE_AN21_ANA                 0xFFDF /*Enable AN21 in analog mode */
#define ENABLE_AN22_ANA                 0xFFBF /*Enable AN22 in analog mode */
#define ENABLE_AN23_ANA                 0xFF7F /*Enable AN23 in analog mode */
#define ENABLE_AN24_ANA                 0xFEFF /*Enable AN24 in analog mode */
#define ENABLE_AN25_ANA                 0xFDFF /*Enable AN25 in analog mode */
#define ENABLE_AN26_ANA                 0xFBFF /*Enable AN26 in analog mode */
#define ENABLE_AN27_ANA                 0xF7FF /*Enable AN27 in analog mode */
#define ENABLE_AN28_ANA                 0xEFFF /*Enable AN28 in analog mode */
#define ENABLE_AN29_ANA                 0xDFFF /*Enable AN29 in analog mode */
#define ENABLE_AN30_ANA                 0xBFFF /*Enable AN30 in analog mode */
#define ENABLE_AN31_ANA                 0x7FFF /*Enable AN31 in analog mode */



/*defines for ADxPCFGL register */

#define ENABLE_AN0_ANA                  0xFFFE /*Enable AN0 in analog mode */
#define ENABLE_AN1_ANA                  0xFFFD /*Enable AN1 in analog mode */
#define ENABLE_AN2_ANA                  0xFFFB /*Enable AN2 in analog mode */
#define ENABLE_AN3_ANA                  0xFFF7 /*Enable AN3 in analog mode */
#define ENABLE_AN4_ANA                  0xFFEF /*Enable AN4 in analog mode */
#define ENABLE_AN5_ANA                  0xFFDF /*Enable AN5 in analog mode */
#define ENABLE_AN6_ANA                  0xFFBF /*Enable AN6 in analog mode */
#define ENABLE_AN7_ANA                  0xFF7F /*Enable AN7 in analog mode */
#define ENABLE_AN8_ANA                  0xFEFF /*Enable AN8 in analog mode */
#define ENABLE_AN9_ANA                  0xFDFF /*Enable AN9 in analog mode */
#define ENABLE_AN10_ANA                 0xFBFF /*Enable AN10 in analog mode */
#define ENABLE_AN11_ANA                 0xF7FF /*Enable AN11 in analog mode */
#define ENABLE_AN12_ANA                 0xEFFF /*Enable AN12 in analog mode */
#define ENABLE_AN13_ANA                 0xDFFF /*Enable AN13 in analog mode */
#define ENABLE_AN14_ANA                 0xBFFF /*Enable AN14 in analog mode */
#define ENABLE_AN15_ANA                 0x7FFF /*Enable AN15 in analog mode */



#define ENABLE_ALL_ANA_0_15             0x0000 /*Enable AN0-AN15 in analog mode */
#define ENABLE_ALL_DIG_0_15             0xFFFF /*Enable AN0-AN15 in Digital mode */

#define ENABLE_ALL_ANA_16_31            0x0000 /*Enable AN16-AN31 in analog mode */

#define ENABLE_ALL_DIG_16_31            0xFFFF /*Enable AN16-AN31 in Digital mode */


/* Setting the priority of adc interrupt */
#define ADC_INT_PRI_0                   0xFFF8
#define ADC_INT_PRI_1                   0xFFF9
#define ADC_INT_PRI_2                   0xFFFA
#define ADC_INT_PRI_3                   0xFFFB
#define ADC_INT_PRI_4                   0xFFFC
#define ADC_INT_PRI_5                   0xFFFD
#define ADC_INT_PRI_6                   0xFFFE
#define ADC_INT_PRI_7                   0xFFFF

/* enable / disable interrupts */

#define ADC_INT_ENABLE                  0xFFFF
#define ADC_INT_DISABLE                 0xFFF7

/* Macros to  Enable/Disable interrupts and set Interrupt priority */

#define EnableIntADC1                    asm("BSET IEC0,#13")
#define DisableIntADC1                   asm("BCLR IEC0,#13")
#define SetPriorityIntADC1(priority)     (IPC3bits.AD1IP = priority)

#define EnableIntADC2                    asm("BSET IEC1,#5")
#define DisableIntADC2                   asm("BCLR IEC1,#5")
#define SetPriorityIntADC2(priority)     (IPC5bits.AD2IP = priority)


/* A/D Converter Function Prototypes */

#define StopSampADC1	ConvertADC1

void OpenADC1(unsigned int config1, unsigned int config2, unsigned int
               config3,unsigned int config4, unsigned int configport_l,
		 unsigned int configport_h, unsigned int configscan_h,
		unsigned int configscan_l) __attribute__ ((section (".libperi"))); /* config ADC */

void ConvertADC1(void) __attribute__ ((section (".libperi")));                      /* Start an A/D conversion */

void SetChanADC1(unsigned int channel123, unsigned int channel0)__attribute__ ((section (".libperi")));              /* Set A/D to specified channel */

unsigned int ReadADC1(unsigned char bufIndex)__attribute__ ((section (".libperi")));        /* Read A/D result */

void CloseADC1(void) __attribute__ ((section (".libperi")));                        /* Turn off A/D */

char BusyADC1(void) __attribute__ ((section (".libperi")));                         /* Check status of A/D conversion */

void ConfigIntADC1(unsigned int config)__attribute__ ((section (".libperi")));


#if defined(__dsPIC33FJ64GP706__) || defined(__dsPIC33FJ64GP708__) ||defined(__dsPIC33FJ64GP710__) ||\
defined(__dsPIC33FJ128GP706__) ||defined(__dsPIC33FJ128GP708__) ||defined(__dsPIC33FJ128GP710__) ||\
defined(__dsPIC33FJ256GP710__) ||defined(__dsPIC33FJ128GP706PS__) ||defined(__dsPIC33FJ128GP708PS__) ||\
defined(__dsPIC33FJ256GP710PS__) ||defined(__dsPIC33FJ64MC706__) ||defined(__dsPIC33FJ64MC710__) ||\
defined(__dsPIC33FJ128MC706__) ||defined(__dsPIC33FJ128MC708__) ||defined(__dsPIC33FJ128MC710__) ||\
defined(__dsPIC33FJ256MC710__) ||defined(__dsPIC33FJ128MC706PS__) ||defined(__dsPIC33FJ128MC708PS__) ||\
defined(__dsPIC33FJ256MC710PS__) ||defined(__PIC24HJ256GP610__)


#define StopSampADC2	ConvertADC2

void OpenADC2(unsigned int config1, unsigned int config2, unsigned int
               config3,unsigned int config4, unsigned int configport_l,
		 unsigned int configport_h, unsigned int configscan_h,
		unsigned int configscan_l)__attribute__ ((section (".libperi"))); /* config ADC */

void ConvertADC2(void) __attribute__ ((section (".libperi")));                      /* Start an A/D conversion */

void SetChanADC2(unsigned int channel123,unsigned int channel0)__attribute__ ((section (".libperi")));              /* Set A/D to specified channel */

unsigned int ReadADC2(unsigned char bufIndex)__attribute__ ((section (".libperi")));        /* Read A/D result */

void CloseADC2(void) __attribute__ ((section (".libperi")));                        /* Turn off A/D */

char BusyADC2(void) __attribute__ ((section (".libperi")));                         /* Check status of A/D conversion */

void ConfigIntADC2(unsigned int config)__attribute__ ((section (".libperi")));


#endif

#endif

