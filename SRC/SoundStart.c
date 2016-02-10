/**********************************************************************
* © 2005 Microchip Technology Inc.
*
* FileName:        main_FFTExample.c
* Dependencies:    Header (.h) files if applicable, see below
* Processor:       dsPIC30Fxxxx
* Compiler:        MPLAB® C30 v1.33.00 or higher
* IDE:             MPLAB® IDE v7.20.01 or later
* Dev. Board Used: dsPICDEM 1.1 Development Board
* Hardware Dependencies: None
*
* SOFTWARE LICENSE AGREEMENT:
* Microchip Technology Inc. (“Microchip”) licenses this software to you
* solely for use with Microchip dsPIC® digital signal controller
* products. The software is owned by Microchip and is protected under
* applicable copyright laws.  All rights reserved.
*
* SOFTWARE IS PROVIDED “AS IS.”  MICROCHIP EXPRESSLY DISCLAIMS ANY
* WARRANTY OF ANY KIND, WHETHER EXPRESS OR IMPLIED, INCLUDING BUT NOT
* LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
* PARTICULAR PURPOSE, OR NON-INFRINGEMENT. IN NO EVENT SHALL MICROCHIP
* BE LIABLE FOR ANY INCIDENTAL, SPECIAL, INDIRECT OR CONSEQUENTIAL
* DAMAGES, LOST PROFITS OR LOST DATA, HARM TO YOUR EQUIPMENT, COST OF
* PROCUREMENT OF SUBSTITUTE GOODS, TECHNOLOGY OR SERVICES, ANY CLAIMS
* BY THIRD PARTIES (INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF),
* ANY CLAIMS FOR INDEMNITY OR CONTRIBUTION, OR OTHER SIMILAR COSTS.
*
* REVISION HISTORY:
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Author            Date      Comments on this revision
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* HV               09/30/05  First release of source file
*
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*
* ADDITIONAL NOTES:
*
*
**********************************************************************/

int SoundStart(void);

fractional signal[FFT_BLOCK_LENGTH] 				/* Typically, the input signal to an FFT  */
__attribute__ ((section (".xdata, data, xmemory"),	/* routine is a fractional array containing samples */
 aligned (FFT_BLOCK_LENGTH*2)));      				/* of an input signal. For this example, */
													/* we will provide the input signal in an */
													/* array declared in Program memory. */

fractcomplex sigCmpx[FFT_BLOCK_LENGTH] 				/* Typically, the input signal to an FFT  */
__attribute__ ((section (".ydata, data, ymemory"), 	/* routine is a complex array containing samples */
aligned (FFT_BLOCK_LENGTH *2 *2)));      				/* of an input signal. For this example, */
														/* we will provide the input signal in an */
														/* array declared in Y-data space. */

fractcomplex twiddleFactors[FFT_BLOCK_LENGTH/2] 	/* Declare Twiddle Factor array in X-space*/
__attribute__ ((section (".xbss, bss, xmemory"), aligned (FFT_BLOCK_LENGTH*2)));

int signalFull = 0, SS_go = 0;							/* Set when signal array full and ready to be processed.*/

/************** END OF GLOBAL DEFINITIONS ***********/

//===============================================================================
// A/D Functions
//===============================================================================
//
//---------------------------------------------------------------------
// InitADSoundStart -- This subroutine will initialize the A/D for sound start 
void InitADSoundStart(void)
{
	ADCON1 = 0x0000;		// Clear ADC control registers
	ADCON2 = 0x0000;		//	
	ADCON3 = 0x0000;		//
	
	TRISB |= 0xFFCF;		// Sets all RB pins to digital inputs, excluding
							// pins RB4, RB5 for the QEI. Which are set
							// in the QEI Configuration.

		
	ADPCFG = 0x7FFF;		// Sets RB15 to analog 
							
							
	ADCON1 = 0x03E7;		//
	ADCON2 = 0x041E;		//  
	ADCON3 = 0x182F;		// 
							
	ADCHS = 0x000F;			// Connect AN15 to CH0 input use Vref- as negative input
	ADCSSL = 0x8000;		// Enable input scan of AN15 only
							
	IFS0bits.ADIF = 0;		// Clear Interrupt Flag.
	IEC0bits.ADIE = 1;		// Enable Interrupts
	ADCON1bits.ADON = 1;	// turn ADC ON

	return;
}


////////////////////////////////////////////////////
// Sound Start
// No intputs
// Returns 0 to break while loop
int SoundStart(void)
{
//	printf("Start SS\r\n");
	int	peakFrequencyBin = 0;				/* Declare post-FFT variables to compute the */
	unsigned long peakFrequency = 0;		/* frequency of the largest spectral component */
	int i;
	fractional peakFrequencyLevel = 0;
	fractional *p_real;
	fractcomplex *p_cmpx;

	TwidFactorInit (LOG2_BLOCK_LENGTH, &twiddleFactors[0], 0);	/* Generate TwiddleFactor Coefficients */
																/* We need to do this only once at start-up */

	InitADSoundStart();

	while ((SS_go == 0) && PORTBbits.RB14 == 0)	/* Place a breakpoint here and observe the watch window variables */
	{
//		printf("Loop\r\n");
		while (signalFull == 0);					/* Wait until signal array is full and ready to be processed */
    
		signalFull = 0;								/* reset siganlFull to be set next time siganl is ready to be processed */	
	
		p_real = &signal[0] ;						/* Set up pointers to convert real array */
		p_cmpx = &sigCmpx[0] ; 						/* to a complex array. The input array initially has all */
												/* the real input samples followed by a series of zeros */

		for ( i = 0; i < FFT_BLOCK_LENGTH; i++ ) 	/* Convert the Real input sample array */
		{											/* to a Complex input sample array  */
			(*p_cmpx).real = *p_real++ ;
			(*p_cmpx++).imag = 0x0000;				/* We will simpy zero out the imaginary part of each data sample */
		}

		/* Perform FFT operation */
		FFTComplexIP (LOG2_BLOCK_LENGTH, &sigCmpx[0], &twiddleFactors[0], COEFFS_IN_DATA);

		/* Store output samples in bit-reversed order of their addresses */
		BitReverseComplex (LOG2_BLOCK_LENGTH, &sigCmpx[0]);

		/* Compute the square magnitude of the complex FFT output array so we have a Real output vetor */
		SquareMagnitudeCplx(FFT_BLOCK_LENGTH, &sigCmpx[0], &sigCmpx[0].real);


		/* Find the frequency Bin ( = index into the SigCmpx[] array) that has the largest energy*/
		/* i.e., the largest spectral component */
		peakFrequencyLevel = VectorMax(FFT_BLOCK_LENGTH/2, &sigCmpx[0].real, &peakFrequencyBin);

		if ( peakFrequencyBin > 21 && peakFrequencyBin < 24 && peakFrequencyLevel > 0x0020)
		{
			SS_go = 1;
		}

		//////
		//printf("pFB %i pFRv %f\r\n", peakFrequencyBin, Fract2Float(sigCmpx[peakFrequencyBin].real));
		/* Compute the frequency (in Hz) of the largest spectral component */
		peakFrequency = peakFrequencyBin*(SAMPLING_RATE/FFT_BLOCK_LENGTH);
	}

	ADC_Config(); 	// Configure and enable A/D Converter 
	SS_go = 1;	// Added to take effect of button press or sound start being found. 
//	printf("End SS\r\n");
//	while(1)
//	{
//		LATFbits.LATF6 = 1; // Turn on Status LED
//	}
	return 0;
}
 
