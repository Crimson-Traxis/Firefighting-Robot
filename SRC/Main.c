//======================================================================
//======================================================================
//==    T R I N I T Y    F I R E     F I G H T I N G    R O B O T     ==
//==						   2 0 0 7						  	      ==
//==														 		  ==
//==	Project Members: Kevin Smith, Denny Esterline, 				  ==	
//==					 Kayla Kibbey, and Vaughn Lietzke			  ==															
//==																  ==
//==	Project Advisor: Dr. Russell Clark							  ==
//======================================================================
//======================================================================
//
// File: Main.c
//
// Purpose: This file is the main source file for the project. This file
// contians the main function and also all interrupt routines. 
//
////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////
// Debuging Mode
#define DEBUG 0  //Enables Debug operation. Debug information will be printed
				 //out on the UART. ONLY TO BE USED FOR TESTING!

#define SOUNDSTART_ENABLE 1 // 1 -- Soundstart enabled
							// 0 -- Soundstart disabled
#define true 1
#define false 0
char START_ENABLED = 0;

int SONAR_DEAD_TIME;
int FF_OFFSET = 8;

////////////////////////////////////////////////////////////////////////
// INCLUDES

/* Header Files from Microchip */
#include <p30f6015.h> 	// Header file for the 6015 chip
#include <dsp.h>		// Header file for DSP operations (PID)
#include <i2c.h>		// Header file for I2C communications
#include <incap.h>		// Header file for Input Capture Operations
#include <spi.h>		// Header file for SPI
#include "fft.h"		// Header file for FFT information
#include <stdlib.h>		//


/* System Constants */
#include "SystemConfiguration.c"	// This file contains system constants 
									// such as baud rates, structures, etc.


/* Custom Functions */
#include "UART.c"			// NOTE: Do NOT place any variable in these files
#include "TIMERS.c"
#include "IC.c"
#include "ADC.c"			// that is called from another file. For example
							// do not use a SPI variable in a Timer function call.
							// This will create a complie error since the SPI variable
#include "MISC.c"			// has not been defined. Please create a different file
#include "PWM.c"			// and place include it in the Other Functions section of code.
#include "QEI.c"			//
#include "PID.c"			//
#include "I2C.c"			//
#include "SPI.c"			//

/* Other Function Files */
#include "Intialization.c"
#include "SoundStart.c"
#include "twiddleFactors.c"
#include "i2cFunctions.c"		// File containg i2c functions
#include "ServoControl.c"

#include "FlameDetection.c"
#include "LEDControl.c"
#include "MotorControl.c"	// Motor Control for the robot

/* Debugging Header File */
#if DEBUG>0					// Files are only included if DEBUG is on
	#include <stdio.h>		//
	#include <uart.h>		//
	#include "Debug.c"		//
#endif



////////////////////////////////////////////////////////////////////////
// FUNCTTIONS / INTERRUPTS
// -----------------------


//----------------------------------------------------------------------
// Interrupt: ADC
void __attribute__((__interrupt__)) _ADCInterrupt(void)
{
	if (SS_go == 0 && SOUNDSTART_ENABLE == 1 && DEBUG == 0)
	{
		int signalStartAddress = 8 * ADC_count++ ;
	
		if (ADCON2bits.BUFS == 1)
		{
			signal[signalStartAddress++] = ADCBUF0 ;
			signal[signalStartAddress++] = ADCBUF1 ;
			signal[signalStartAddress++] = ADCBUF2 ;
			signal[signalStartAddress++] = ADCBUF3 ;
			signal[signalStartAddress++] = ADCBUF4 ;
			signal[signalStartAddress++] = ADCBUF5 ;
			signal[signalStartAddress++] = ADCBUF6 ;
			signal[signalStartAddress] = ADCBUF7 ;
		}
		else
		{
			signal[signalStartAddress++] = ADCBUF8 ;
			signal[signalStartAddress++] = ADCBUF9 ;
			signal[signalStartAddress++] = ADCBUFA ;
			signal[signalStartAddress++] = ADCBUFB ;	
			signal[signalStartAddress++] = ADCBUFC ;
			signal[signalStartAddress++] = ADCBUFD ;
			signal[signalStartAddress++] = ADCBUFE ;
			signal[signalStartAddress] = ADCBUFF ;
		}
	
		if (ADC_count > FFT_BLOCK_LENGTH/8 - 1)
		{
			ADC_count = 0;
			signalFull = 1;
		}
	}
	else
	{
		// Sensor Mapping
		// Pin   Sensor      Channel/Buffer
		// IR1	  SR_body   	AN3/BUF3
		// IR2	  LR_body   	AN2/BUF2
		// IR3    LR_rear   	AN1/BUF1
		// IR4    SR_Turret 	AN0/BUF0
		// IR5    LR_Turret 	AN8/BUF4
		// IR6    n/a       	AN9/BUF5
		if(ADC_count < 8)
		{
			IR_SR_TURRET += ADCBUF0;	// Sum up values for average. 
			IR_LR_REAR += ADCBUF1;
			IR_LR_FRONT += ADCBUF2;
			IR_SR_FRONT += ADCBUF3;
			IR_LR_TURRET += ADCBUF4;
			ADC_count++;
		}
		else
		{
			AVG_IR_SR_TURRET = IR_SR_TURRET >> 2;	//Shift right 4 bits to divide by 8
			AVG_IR_LR_REAR = IR_LR_REAR >> 2;
			AVG_IR_LR_FRONT = IR_LR_FRONT >> 2;
			AVG_IR_SR_FRONT = IR_SR_FRONT >> 2;
			AVG_IR_LR_TURRET =  IR_LR_TURRET >> 2;
			
			#if DEBUG>0			//Used in debug mode. 
			DEBUG_ADRead = 1;	//
			#endif				//
				
			IR_SR_TURRET = ADCBUF0*0;	// Read buffers to start new converstion. 
			IR_LR_REAR = ADCBUF1*0;		// Also zero's out values for new average
			IR_LR_FRONT = ADCBUF2*0;	// This means out 8 interrupts will be 
			IR_SR_FRONT = ADCBUF3*0;	// data gathering and the 9th is average and 
			IR_LR_TURRET = ADCBUF4*0;	// clear. 
			ADC_count = 0;
		
		}
		WHITE_LINE_READING = ADCBUF5;
		
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		//printf("%u|%u|%u|%u|%u|%u\r\n",IR_SR_TURRET,IR_LR_TURRET,IR_SR_FRONT,IR_LR_FRONT,IR_LR_REAR,WHITE_LINE_READING);
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		WhiteLineCheck();
	}
	
	
	IFS0bits.ADIF = 0;
	return;
}

// Interrupt: ADC Ends
//----------------------------------------------------------------------

//----------------------------------------------------------------------
// Interrupt: Input Capture
// IC1------------
void __attribute__((__interrupt__)) _IC1Interrupt(void)
{

	//interrupt occurs on every edge of the signal pulse
	//signal is on pin D8
	
	if (PORTDbits.RD8 == 0) //falling edge, timer has valid data
	{
		switch (Current_Sonar)
		{	
			case 0: //actualy it's 2, it was incremented in the timer interrupt
				SONAR_REAR = TMR3;
	//			SONAR_DEAD_TIME = 23031 - SONAR_TURRET; //50 ms - sensor reading time
				PR3 = 9213;
				//PR3 = SONAR_PULSE;
			break;
			case 1: //actualy it's 0
				SONAR_TURRET = TMR3;

	//			SONAR_DEAD_TIME -= SONAR_REAR; 
				PR3 = 9213;
				//PR3 = SONAR_PULSE;
			break;
			case 2: //actualy it's 1
				SONAR_FRONT = TMR3;	
				PR3 = 9213;
				//PR3 = SONAR_DEAD_TIME - SONAR_FRONT;
			break;
		};
		TMR3 = 0;
		
	}
	else //rising edge - start timer
	{
		TMR3 = 0;
		PR3 = TMR3_MAX; //long time - basicaly a timeout value
	}
		
	IFS0bits.IC1IF = 0; // Clear Interrupt
}

// IC3------------
void __attribute__((__interrupt__)) _IC3Interrupt(void)
{
	UVCount++;
	IFS1bits.IC3IF = 0; // Clear Interrupt	
}
// Interrupt: Input Capture Ends
//----------------------------------------------------------------------



void __attribute__((__interrupt__)) _CNInterrupt(void)
{
//----------------------------------------------------------------------
// Interrupt: Change Notification
	//The following checks if the wheel is going 
	//forward or backward and updates accordingly. 
	//      ____ 
	//_____|    |_______A
	//     1    3
	//         ____
	//________|    |____B
	//        2    4
	//
	// Example: A is set (1) and B is no (0) increase the count
	//          A is low (3) and B is set (4) increase the count
	
	if(PORTCbits.RC13 ^ QEIS_PREVB)  //<---- NEED TO CHANGE NAME
	{
		QEIS_COUNTER++;
	}
	else
	{
		QEIS_COUNTER--;
	}

	QEIS_PREVB = PORTCbits.RC14; 

	IFS0bits.CNIF = 0; //Clear Interrupt flag
	return;
// Interrupt: Change Notification Ends
//----------------------------------------------------------------------
	
}

//----------------------------------------------------------------------
// Interrupt: Timers

void __attribute__((__interrupt__)) _T1Interrupt(void)
{
//
// TIMER 1-----------------------------------------------------
//
	IFS0bits.T1IF = 0;
}



void __attribute__((__interrupt__)) _T2Interrupt(void)
{
//
// TIMER 2-----------------------------------------------------
//	
	switch(ACTIVE_SERVO)
	{
		case 0:
			SERVO_DEAD_TIME = SERVO_50Hz;
			ACTIVE_SERVO++;
			SERVO_DEAD_TIME -= SERVO_TURRET_POS;
			PR2 = SERVO_TURRET_POS;
			LATDbits.LATD3 = 1;
		break;
		case 1: 
			ACTIVE_SERVO++;
			SERVO_DEAD_TIME -= SERVO_CO2_POS;
			PR2 = SERVO_CO2_POS;
			LATDbits.LATD3 = 0;
			LATDbits.LATD1 = 1;
		break;
		case 2:
			ACTIVE_SERVO++;
			SERVO_DEAD_TIME -= LED_TURRET_MODE;
			PR2 = LED_TURRET_MODE;	
			LATDbits.LATD1 = 0;
			LATDbits.LATD2 = 1;
		break;
		case 3:
			if(LED_TURRET_OFF != 1)
			{
				LATDbits.LATD2 = 0;
			}
			PR2 = SERVO_DEAD_TIME;
			ACTIVE_SERVO = 0;
		break;
	};
		
	TMR2 = 0;			//Reset Timer
	IFS0bits.T2IF = 0;	//Clear Interrupt Flag
}


void __attribute__((__interrupt__)) _T3Interrupt(void)
{
//
// TIMER 3-----------------------------------------------------
//
	if ((LATD & 0x00E0) == 0)//bits 7,6,5 - the trigger pins all low - raise one to start a sonar
	{
		switch (Current_Sonar)
		{
			case 0:
				Current_Sonar = 1;
				LATDbits.LATD5 = 1;
			break;
			case 1:
				Current_Sonar = 2;
				LATDbits.LATD6 = 1;
			break;
			case 2:
				Current_Sonar = 0;
				LATDbits.LATD7 = 1;
			break;
		};
		TMR3 = 0;
		PR3 = SONAR_PULSE; //short trigger pulse ~20 usec 
	}
	else
	{
		LATD &= 0xFF1F; //all trigger pins low - wait for the IC interrupt to get sonar data
		TMR3 = 0;
		PR3 = TMR3_MAX;//long time before the next _timer3_ interrupt - Input Capture interrupt will use the timer 
								//when the sonar module toggles the pin
	}	

	
	IFS0bits.T3IF = 0; // Clear Interrupt
}


void __attribute__((__interrupt__)) _T4Interrupt(void)
{
//
// TIMER 4-----------------------------------------------------
//
	IFS1bits.T4IF = 0; // Clear INT flag.
}



void __attribute__((__interrupt__)) _T5Interrupt(void)
{
//
// TIMER 5-----------------------------------------------------
//	
	     //timer 5 should be ticking at 1 ms
	  	 //quick and simple - don't care about rollover
	TIMER5_COUNT++;			
	IFS1bits.T5IF = 0;
}
// Interrupt: Timers End
//----------------------------------------------------------------------



////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////
// MAIN
// ----

int main()
{
int TempAngleGrab; //because the pod takes time to move, 
					//grab the current angle, start moving the pod
					//then call the body turn function
					//(pod moves while body is turning

int WhiteLine = 1;
int Old, done=0;
int RoomNum = 0;

//-------------------------------------------------------------------
// DO NOT EDIT BELOW THIS LINE!
//-------------------------------------------------------------------
	Initialize();	// Function sets port direction bits and calls 
					// setup routines for all of the chip's systems
	
	#if DEBUG>0
		DEBUG_START();
	#endif
//-------------------------------------------------------------------
// DO NOT EDIT ABOVE THIS LINE!
//-------------------------------------------------------------------
if(SOUNDSTART_ENABLE == 1)
	{
		char x = 1;
		LED_Turret(0);	// Turn off LED turret. 
		while(x == 1)
		{
			x = SoundStart();
		}
		START_ENABLED = 1;
	}

	LED_Turret(2);	// Turn on LED turret showing we are running. 
	LATFbits.LATF6 = 1; // Turn on Status LED

//HardwareDelayNmSec(500);
	while(1)
	{
 		Forward_Dist(5800);					// Forward over the stairs and to the first room. (about 60 inches)
		SERVO_ADJUST_TURRET(-70); 			// Look to the left
		HardwareDelayNmSec(100); 					// wait for turret to move
		if (UVCheck())
		{	
			HOTROOM = 1;					// Set room number
			//TempAngleGrab = SERVO_TURRET_ANGLE;
			SERVO_ADJUST_TURRET(0); 		// turn the turret first, it turns while the body is turning
			Turn(-90);			// 
			Forward_Dist(1200);				// Drive into the room (about 6 inches) 
			HardwareDelayNmSec(100);
			Turn(30);
			Forward_Dist(500);				// Drive into the room.
			LocateAndExtinguish();			
		}
		else //not in room 1, move on to two
		{
			SERVO_ADJUST_TURRET(0); 		// straight		
			//Forward_Dist(1700);				// Forward to Room 2. 
			Turn(30);
			Forward_Dist(600);
			HardwareDelayNmSec(100);
			Turn(-30);
			Forward_Dist(1180);


			SERVO_ADJUST_TURRET(90); 		// Look to the right
			HardwareDelayNmSec(100);				// wait for turret to move
			if(UVCheck())
			{
				HOTROOM = 2;				// Set room number
				TempAngleGrab = SERVO_TURRET_ANGLE;
				SERVO_ADJUST_TURRET(0);		// straight
				Turn(TempAngleGrab);	// Adjust body to turret position
				Forward_Dist(1200);			// Drive into the room. 
				HardwareDelayNmSec(100);
				Turn(30);
				Forward_Dist(500);				// Drive into the room.
				LocateAndExtinguish();
			}
			else//not in room 2, move on to three
			{
				SERVO_ADJUST_TURRET(0);
				Reverse_Dist(3400); ///3900);			// Reverse to center of the room.
				HardwareDelayNmSec(1000);
				Turn(90);					// Turn to the right
				Reverse_Dist(1900);			// Back up to room 3.
				//Stop in front of room 3
				SERVO_ADJUST_TURRET(90); 	// Look to the right
				HardwareDelayNmSec(100);				// wait for turret to move
				if(UVCheck())
				{//Flame Found!
					HOTROOM = 3;					// Set room number
					TempAngleGrab = SERVO_TURRET_ANGLE;
					SERVO_ADJUST_TURRET(0);
					Turn(TempAngleGrab);		// Adjust body to turret position		
					Forward_Dist(1000);				// Drive into the room. 
					HardwareDelayNmSec(100);
					Turn(30);
					Forward_Dist(300);				// Drive into the room.
					LocateAndExtinguish();
				}
				else //not in room three - must be in four 
				{
					SERVO_ADJUST_TURRET(0);
					//Forward_Dist(4400);			// Drive to room 4

					Forward_Dist(1550);
					HardwareDelayNmSec(100);
					Turn(45);
					Forward_Dist(848);
					HardwareDelayNmSec(100);
					Turn(-45);
					Forward_Dist(2200);

					//don't bother checking for UV - it's the only room left
					HOTROOM = 4;					// Set room number
					HardwareDelayNmSec(1000);
					Turn(90);		// Turn to the right
					Forward_Dist(1200);				// Drive into the room. 
					HardwareDelayNmSec(100);
					Turn(30);
					Forward_Dist(500);				// Drive into the room.
					LocateAndExtinguish();	 
				
				} 	
			}  
		}	
	ReturnFromLocateAndExtinguish();
	HardwareDelayNmSec(0xFFFF);	
	}	

}

	

