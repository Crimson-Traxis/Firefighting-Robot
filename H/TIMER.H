/********************************************************************/
/*              Header for Timer module library functions           */
/********************************************************************/
#ifndef TIMER_H
#define TIMER_H

/* List of SFRs for Timers */
/* This list contains the SFRs with default (POR) values to be used for configuring Timers */
/* The user can modify this based on the requirement */
#define TMRx_VALUE          0x0000
#define PRx_VALUE           0xFFFF
#define TxCON_VALUE         0x0000

/* Timer1 Control Register (T1CON) Bit Defines */

#define T1_ON               0xffff      /* Timer1 ON */
#define T1_OFF              0x7fff      /* Timer1 OFF */

#define T1_IDLE_CON         0xdfff      /* operate during sleep */
#define T1_IDLE_STOP        0xffff      /* stop operation during sleep */

#define T1_GATE_ON          0xffff      /* Timer Gate time accumulation enabled */
#define T1_GATE_OFF         0xffbf      /* Timer Gate time accumulation disabled */

#define T1_PS_1_1           0xffcf      /* Prescaler 1:1 */
#define T1_PS_1_8           0xffdf      /*           1:8 */
#define T1_PS_1_64          0xffef      /*          1:64 */
#define T1_PS_1_256         0xffff      /*         1:256 */

#define T1_SYNC_EXT_ON      0xffff      /* Synch external clk input */
#define T1_SYNC_EXT_OFF     0xfffb      /* Do not synch external clk input */

#define T1_SOURCE_EXT       0xffff      /* External clock source */
#define T1_SOURCE_INT       0xfffd      /* Internal clock source */

/* defines for Timer Interrupts */

#define T1_INT_PRIOR_7      0xffff      /* 111 = Interrupt is priority 7 */
#define T1_INT_PRIOR_6      0xfffe      /* 110 = Interrupt is priority 6 */
#define T1_INT_PRIOR_5      0xfffd      /* 101 = Interrupt is priority 5 */
#define T1_INT_PRIOR_4      0xfffc      /* 100 = Interrupt is priority 4 */
#define T1_INT_PRIOR_3      0xfffb      /* 011 = Interrupt is priority 3 */
#define T1_INT_PRIOR_2      0xfffa      /* 010 = Interrupt is priority 2 */
#define T1_INT_PRIOR_1      0xfff9      /* 001 = Interrupt is priority 1 */
#define T1_INT_PRIOR_0      0xfff8      /* 000 = Interrupt is priority 0 */

#define T1_INT_ON           0xffff      /* Interrupt Enable */
#define T1_INT_OFF          0xfff7      /* Interrupt Disable */

/* Macros to  Enable/Disable interrupts and set Interrupt priority of Timers 1*/
#define EnableIntT1                    asm("BSET IEC0,#3")
#define DisableIntT1                   asm("BCLR IEC0,#3")
#define SetPriorityIntT1(priority)     (IPC0bits.T1IP = priority)

/* Timer1 Function Prototypes */

/* OpenTimer1 */
void OpenTimer1( unsigned int config, unsigned int period) __attribute__ ((section
(".libperi")));

/* CloseTimer1 */
void CloseTimer1(void) __attribute__ ((section (".libperi")));

/* ReadTimer1 */
unsigned int ReadTimer1(void) __attribute__ ((section (".libperi")));

/* WriteTimer1 */
void WriteTimer1( unsigned int timer) __attribute__ ((section (".libperi")));

/* Config Int Timer1 */
void ConfigIntTimer1(unsigned int config) __attribute__ ((section (".libperi")));

/* Timer2 Control Register (T2CON) Bit Defines */

#define T2_ON               0xffff      /* Timer2 ON */
#define T2_OFF              0x7fff      /* Timer2 OFF */

#define T2_IDLE_CON         0xdfff      /* operate during sleep */
#define T2_IDLE_STOP        0xffff      /* stop operation during sleep */

#define T2_GATE_ON          0xffff      /* Timer2 Gate time accumulation enabled  */
#define T2_GATE_OFF         0xffbf      /* Timer2 Gate time accumulation disabled */

#define T2_PS_1_1           0xffcf      /* Prescaler 1:1   */
#define T2_PS_1_8           0xffdf      /*           1:8   */
#define T2_PS_1_64          0xffef      /*           1:64  */
#define T2_PS_1_256         0xffff      /*           1:256 */

#define T2_32BIT_MODE_ON    0xffff      /* Timer 2 and Timer 3 form a 32 bit Timer */
#define T2_32BIT_MODE_OFF   0xfff7      

#define T2_SOURCE_EXT       0xffff      /* External clock source */
#define T2_SOURCE_INT       0xfffd      /* Internal clock source */

/* defines for Timer Interrupts */
#define T2_INT_PRIOR_7      0xffff      /* 111 = Interrupt is priority 7 */ 
#define T2_INT_PRIOR_6      0xfffe      /* 110 = Interrupt is priority 6 */
#define T2_INT_PRIOR_5      0xfffd      /* 101 = Interrupt is priority 5 */
#define T2_INT_PRIOR_4      0xfffc      /* 100 = Interrupt is priority 4 */
#define T2_INT_PRIOR_3      0xfffb      /* 011 = Interrupt is priority 3 */
#define T2_INT_PRIOR_2      0xfffa      /* 010 = Interrupt is priority 2 */
#define T2_INT_PRIOR_1      0xfff9      /* 001 = Interrupt is priority 1 */
#define T2_INT_PRIOR_0      0xfff8      /* 000 = Interrupt is priority 0 */

#define T2_INT_ON           0xffff      /* Interrupt Enable */  
#define T2_INT_OFF          0xfff7      /* Interrupt Disable */

/* Macros to  Enable/Disable interrupts and set Interrupt priority of Timers 2*/
//DBT 
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

#define EnableIntT2                    asm("BSET IEC0,#7")
#define DisableIntT2                   asm("BCLR IEC0,#7")

#else

#define EnableIntT2                    asm("BSET IEC0,#6")
#define DisableIntT2                   asm("BCLR IEC0,#6")

#endif

#define SetPriorityIntT2(priority)     (IPC1bits.T2IP = priority)

#endif

/* Timer2 Function Prototypes */

/* OpenTimer2 */
void OpenTimer2(unsigned int config, unsigned int period) __attribute__ ((section
(".libperi")));

/* CloseTimer2 */
void CloseTimer2(void) __attribute__ ((section (".libperi")));

/* ReadTimer2 */
unsigned int ReadTimer2(void) __attribute__ ((section (".libperi")));

/* WriteTimer2 */
void WriteTimer2( unsigned int timer) __attribute__ ((section (".libperi")));

/* ConfigIntTimer2 */
void ConfigIntTimer2(unsigned int ) __attribute__ ((section (".libperi")));


/* Timer3 Control Register (T3CON) Bit Defines */

#define T3_ON               0xffff      /* Timer3 ON */
#define T3_OFF              0x7fff      /* Timer3 OFF */

#define T3_IDLE_CON         0xdfff      /* operate during sleep */
#define T3_IDLE_STOP        0xffff      /* stop operation during sleep */

#define T3_GATE_ON          0xffff      /* Timer3 Gate  time accumulation enabled  */
#define T3_GATE_OFF         0xffbf      /* Timer3 Gate time accumulation disabled */

#define T3_PS_1_1           0xffcf      /* Prescaler 1:1   */
#define T3_PS_1_8           0xffdf      /*           1:8   */
#define T3_PS_1_64          0xffef      /*           1:64  */
#define T3_PS_1_256         0xffff      /*           1:256 */
#define T3_SOURCE_EXT       0xffff      /* External clock source */
#define T3_SOURCE_INT       0xfffd      /* Internal clock source */

/* defines for Timer Interrupts */
#define T3_INT_PRIOR_7      0xffff      /* 111 = Interrupt is priority 7 */ 
#define T3_INT_PRIOR_6      0xfffe      /* 110 = Interrupt is priority 6 */
#define T3_INT_PRIOR_5      0xfffd      /* 101 = Interrupt is priority 5 */
#define T3_INT_PRIOR_4      0xfffc      /* 100 = Interrupt is priority 4 */
#define T3_INT_PRIOR_3      0xfffb      /* 011 = Interrupt is priority 3 */
#define T3_INT_PRIOR_2      0xfffa      /* 010 = Interrupt is priority 2 */
#define T3_INT_PRIOR_1      0xfff9      /* 001 = Interrupt is priority 1 */
#define T3_INT_PRIOR_0      0xfff8      /* 000 = Interrupt is priority 0 */

#define T3_INT_ON           0xffff      /* Interrupt Enable */  
#define T3_INT_OFF          0xfff7      /* Interrupt Disable */

/* Macros to  Enable/Disable interrupts and set Interrupt priority of Timers 3*/

//DBT 
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
#define EnableIntT3                    asm("BSET IEC0,#8")
#define DisableIntT3                   asm("BCLR IEC0,#8")

#else

#define EnableIntT3                    asm("BSET IEC0,#7")
#define DisableIntT3                   asm("BCLR IEC0,#7")
#endif

#define SetPriorityIntT3(priority)     (IPC2bits.T3IP = priority)



/* Timer3 Function Prototypes */

/* OpenTimer3 */
void OpenTimer3(unsigned int config, unsigned int timer)  __attribute__ ((section
(".libperi")));

/* CloseTimer3 */
void CloseTimer3(void)  __attribute__ ((section (".libperi")));

/* ReadTimer3 */
unsigned int ReadTimer3(void)  __attribute__ ((section (".libperi")));

/* WriteTimer3 */
void WriteTimer3( unsigned int timer)  __attribute__ ((section (".libperi")));

/* ConfigIntTimer3  */
void  ConfigIntTimer3(unsigned int config)  __attribute__ ((section (".libperi")));


/* Timer 32 mode using Timer 2 and Timer3*/

/*Timer 32 bit mode Prototypes*/

/* OpenTimer23 */
void OpenTimer23(unsigned int config, unsigned long period)  __attribute__ ((section
(".libperi")));

/* CloseTimer23 */
void CloseTimer23(void)  __attribute__ ((section (".libperi")));

/* ReadTimer23 */
unsigned long ReadTimer23(void)  __attribute__ ((section (".libperi")));

/* WriteTimer23 */
void WriteTimer23(unsigned long timer)  __attribute__ ((section (".libperi")));

/* Config Int Timer 23*/
void ConfigIntTimer23(unsigned int config)  __attribute__ ((section (".libperi")));

/* These devices support Timers 4 and 5 */
#if defined(__dsPIC30F3010__) || defined(__dsPIC30F4012__) || defined(__dsPIC30F3011__)  || \
    defined(__dsPIC30F4011__) || defined(__dsPIC30F6010__) || defined(__dsPIC30F5011__) || \
    defined(__dsPIC30F6011__) || defined(__dsPIC30F6012__) || defined(__dsPIC30F5013__) || \
    defined(__dsPIC30F6013__) || defined(__dsPIC30F6014__) || defined(__dsPIC30F4013__) || \
    defined(__dsPIC30F5015__) || defined(__dsPIC30F6010A__) || defined(__dsPIC30F6011A__) || \
    defined(__dsPIC30F6012A__) || defined(__dsPIC30F6013A__) || defined(__dsPIC30F6014A__) || \
    defined(__dsPIC30F5016__) || defined(__dsPIC30F6015__) || defined(__dsPIC33FJ64GP206__) || defined(__dsPIC33FJ64GP306__) || defined(__dsPIC33FJ64GP310__) || defined(__dsPIC33FJ64GP706__) || \
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
    

/* Timer4 Control Register (T4CON) Bit Defines */
#define T4_ON               0xffff      /* Timer4 ON */
#define T4_OFF              0x7fff      /* Timer4 OFF */

#define T4_IDLE_CON         0xdfff      /* operate during sleep */
#define T4_IDLE_STOP        0xffff      /* stop operation during sleep */

#define T4_GATE_ON          0xffff      /* Timer Gate time accumulation enabled */
#define T4_GATE_OFF         0xffbf      /* Timer Gate time accumulation disabled */

#define T4_PS_1_1           0xffcf      /* Prescaler 1:1   */
#define T4_PS_1_8           0xffdf      /*           1:8   */
#define T4_PS_1_64          0xffef      /*           1:64  */
#define T4_PS_1_256         0xffff      /*           1:256 */

#define T4_SOURCE_EXT       0xffff      /* External clock source */
#define T4_SOURCE_INT       0xfffd      /* Internal clock source */

#define T4_32BIT_MODE_ON    0xffff /* Timer 4 and Timer 5 form a 32 bit Timer */
#define T4_32BIT_MODE_OFF   0xfff7 

/* defines for Timer Interrupts */
#define T4_INT_PRIOR_7      0xffff      /* 111 = Interrupt is priority 7 */ 
#define T4_INT_PRIOR_6      0xfffe      /* 110 = Interrupt is priority 6 */
#define T4_INT_PRIOR_5      0xfffd      /* 101 = Interrupt is priority 5 */
#define T4_INT_PRIOR_4      0xfffc      /* 100 = Interrupt is priority 4 */
#define T4_INT_PRIOR_3      0xfffb      /* 011 = Interrupt is priority 3 */
#define T4_INT_PRIOR_2      0xfffa      /* 010 = Interrupt is priority 2 */
#define T4_INT_PRIOR_1      0xfff9      /* 001 = Interrupt is priority 1 */
#define T4_INT_PRIOR_0      0xfff8      /* 000 = Interrupt is priority 0 */

#define T4_INT_ON           0xffff      /* Interrupt Enable */  
#define T4_INT_OFF          0xfff7      /* Interrupt Disable */

//DBT
/* Macros to  Enable/Disable interrupts and set Interrupt priority of Timer 4 */

#if defined(__dsPIC30F3010__) || defined(__dsPIC30F4012__) || defined(__dsPIC30F3011__)  || \
    defined(__dsPIC30F4011__) || defined(__dsPIC30F6010__) || defined(__dsPIC30F5011__) || \
    defined(__dsPIC30F6011__) || defined(__dsPIC30F6012__) || defined(__dsPIC30F5013__) || \
    defined(__dsPIC30F6013__) || defined(__dsPIC30F6014__) || defined(__dsPIC30F4013__) || \
    defined(__dsPIC30F5015__) || defined(__dsPIC30F6010A__) || defined(__dsPIC30F6011A__) || \
    defined(__dsPIC30F6012A__) || defined(__dsPIC30F6013A__) || defined(__dsPIC30F6014A__) || \
    defined(__dsPIC30F5016__) || defined(__dsPIC30F6015__) 

#define EnableIntT4                    asm("BSET IEC1,#5")
#define DisableIntT4                   asm("BCLR IEC1,#5")
#define SetPriorityIntT4(priority)     (IPC5bits.T4IP = priority)

#else

#define EnableIntT4                    asm("BSET IEC1,#11")
#define DisableIntT4                   asm("BCLR IEC1,#11")
#define SetPriorityIntT4(priority)     (IPC6bits.T4IP = priority)

#endif

/* Timer4 Function Declarations */

/* OpenTimer4
 * Configures Timer4
 */
void OpenTimer4(unsigned int config , unsigned int timer )  __attribute__ ((section
(".libperi")));

/* CloseTimer4
 * Disables Timer4
 */
void CloseTimer4(void)  __attribute__ ((section (".libperi")));

/* ReadTimer4
 * Reads Timer4
 */
unsigned int ReadTimer4(void)  __attribute__ ((section (".libperi")));

/* WriteTimer4
 * Writes Timer4
 */
void WriteTimer4(unsigned int timer )  __attribute__ ((section (".libperi")));

/* Config Int Timer 4*/
void ConfigIntTimer4(unsigned int config)  __attribute__ ((section (".libperi")));

/* Timer5 Config Bit Defines */

#define T5_ON               0xffff      /* Timer5 ON */
#define T5_OFF              0x7fff      /* Timer5 OFF */

#define T5_IDLE_CON         0xdfff      /* operate during sleep */
#define T5_IDLE_STOP        0xffff      /* stop operation during sleep */

#define T5_GATE_ON          0xffff      /* Timer Gate time accumulation enabled */
#define T5_GATE_OFF         0xffbf      /* Timer Gate time accumulation disabled */

#define T5_PS_1_1           0xffcf      /* Prescaler 1:1   */
#define T5_PS_1_8           0xffdf      /*           1:8   */
#define T5_PS_1_64          0xffef      /*           1:64  */
#define T5_PS_1_256         0xffff      /*           1:256 */

#define T5_SOURCE_EXT       0xffff      /* External clock source */
#define T5_SOURCE_INT       0xfffd      /* Internal clock source */

/* defines for Timer Interrupts */
#define T5_INT_PRIOR_7      0xffff      /* 111 = Interrupt is priority 7 */
#define T5_INT_PRIOR_6      0xfffe      /* 110 = Interrupt is priority 6 */
#define T5_INT_PRIOR_5      0xfffd      /* 101 = Interrupt is priority 5 */
#define T5_INT_PRIOR_4      0xfffc      /* 100 = Interrupt is priority 4 */
#define T5_INT_PRIOR_3      0xfffb      /* 011 = Interrupt is priority 3 */
#define T5_INT_PRIOR_2      0xfffa      /* 010 = Interrupt is priority 2 */
#define T5_INT_PRIOR_1      0xfff9      /* 001 = Interrupt is priority 1 */
#define T5_INT_PRIOR_0      0xfff8      /* 000 = Interrupt is priority 0 */

#define T5_INT_ON           0xffff      /* Interrupt Enable */
#define T5_INT_OFF          0xfff7      /* Interrupt Disable */


//DBT
/* Macros to  Enable/Disable interrupts and set Interrupt priority of Timer 5 */
#if defined(__dsPIC30F3010__) || defined(__dsPIC30F4012__) || defined(__dsPIC30F3011__)  || \
    defined(__dsPIC30F4011__) || defined(__dsPIC30F6010__) || defined(__dsPIC30F5011__) || \
    defined(__dsPIC30F6011__) || defined(__dsPIC30F6012__) || defined(__dsPIC30F5013__) || \
    defined(__dsPIC30F6013__) || defined(__dsPIC30F6014__) || defined(__dsPIC30F4013__) || \
    defined(__dsPIC30F5015__) || defined(__dsPIC30F6010A__) || defined(__dsPIC30F6011A__) || \
    defined(__dsPIC30F6012A__) || defined(__dsPIC30F6013A__) || defined(__dsPIC30F6014A__) || \
    defined(__dsPIC30F5016__) || defined(__dsPIC30F6015__) 

#define EnableIntT5                    asm("BSET IEC1,#6")
#define DisableIntT5                   asm("BCLR IEC1,#6")
#define SetPriorityIntT5(priority)     (IPC5bits.T5IP = priority)

#else

#define EnableIntT5                    asm("BSET IEC1,#12")
#define DisableIntT5                   asm("BCLR IEC1,#12")
#define SetPriorityIntT5(priority)     (IPC7bits.T5IP = priority)

#endif

/* Timer5 Function Declarations */

/* OpenTimer5
 * Configures Timer5
 */
void OpenTimer5(unsigned int config, unsigned int timer)  __attribute__ ((section
(".libperi")));

/* CloseTimer5
 * Disables Timer5
 */
void CloseTimer5(void)  __attribute__ ((section (".libperi")));

/* ReadTimer5
 * Reads Timer5
 */
unsigned int ReadTimer5(void)  __attribute__ ((section (".libperi")));

/* WriteTimer5
 * Writes Timer5
 */
void WriteTimer5(unsigned int timer)  __attribute__ ((section (".libperi")));

/* Config Int Timer 5*/
void ConfigIntTimer5(unsigned int config)  __attribute__ ((section (".libperi")));


/* Timer 45 mode using Timer 4 and Timer 5 */

/* OpenTimer45 */
void OpenTimer45(unsigned int config , unsigned long timer)  __attribute__ ((section
(".libperi")));

/* CloseTimer45 */
void CloseTimer45(void)  __attribute__ ((section (".libperi")));

/* ReadTimer45 */
unsigned long ReadTimer45(void)  __attribute__ ((section (".libperi")));

/* WriteTimer45 */
void WriteTimer45(unsigned long timer)  __attribute__ ((section (".libperi")));

/* Config Int Timer 45*/
void ConfigIntTimer45(unsigned int config)  __attribute__ ((section (".libperi")));
#endif

//For 33F and 24H Devices 

//DBT

/* These devices support Timers 6 ,7 , 8 and 9 */
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

/* Timer6 Control Register (T6CON) Bit Defines */
#define T6_ON               0xffff      /* Timer6 ON */
#define T6_OFF              0x7fff      /* Timer6 OFF */

#define T6_IDLE_CON         0xdfff      /* operate during sleep */
#define T6_IDLE_STOP        0xffff      /* stop operation during sleep */

#define T6_GATE_ON          0xffff      /* Timer Gate time accumulation enabled */
#define T6_GATE_OFF         0xffbf      /* Timer Gate time accumulation disabled */

#define T6_PS_1_1           0xffcf      /* Prescaler 1:1   */
#define T6_PS_1_8           0xffdf      /*           1:8   */
#define T6_PS_1_64          0xffef      /*           1:64  */
#define T6_PS_1_256         0xffff      /*           1:256 */

#define T6_SOURCE_EXT       0xffff      /* External clock source */
#define T6_SOURCE_INT       0xfffd      /* Internal clock source */

#define T6_32BIT_MODE_ON    0xffff /* Timer 6 and Timer 7 form a 32 bit Timer */
#define T6_32BIT_MODE_OFF   0xfff7 

/* defines for Timer Interrupts */
#define T6_INT_PRIOR_7      0xffff      /* 111 = Interrupt is priority 7 */ 
#define T6_INT_PRIOR_6      0xfffe      /* 110 = Interrupt is priority 6 */
#define T6_INT_PRIOR_5      0xfffd      /* 101 = Interrupt is priority 5 */
#define T6_INT_PRIOR_4      0xfffc      /* 100 = Interrupt is priority 4 */
#define T6_INT_PRIOR_3      0xfffb      /* 011 = Interrupt is priority 3 */
#define T6_INT_PRIOR_2      0xfffa      /* 010 = Interrupt is priority 2 */
#define T6_INT_PRIOR_1      0xfff9      /* 001 = Interrupt is priority 1 */
#define T6_INT_PRIOR_0      0xfff8      /* 000 = Interrupt is priority 0 */

#define T6_INT_ON           0xffff      /* Interrupt Enable */  
#define T6_INT_OFF          0xfff7      /* Interrupt Disable */

/* Macros to  Enable/Disable interrupts and set Interrupt priority of Timer 4 */
#define EnableIntT6                    asm("BSET IEC2,#15")
#define DisableIntT6                   asm("BCLR IEC2,#15")
#define SetPriorityIntT6(priority)     (IPC11bits.T6IP = priority)

/* Timer6 Function Declarations */

/* OpenTimer6
 * Configures Timer6
 */
void OpenTimer6(unsigned int config , unsigned int timer )  __attribute__ ((section
(".libperi")));

/* CloseTimer6
 * Disables Timer6
 */
void CloseTimer6(void)  __attribute__ ((section (".libperi")));

/* ReadTimer6
 * Reads Timer6
 */
unsigned int ReadTimer6(void)  __attribute__ ((section (".libperi")));

/* WriteTimer6
 * Writes Timer6
 */
void WriteTimer6(unsigned int timer )  __attribute__ ((section (".libperi")));

/* Config Int Timer 6*/
void ConfigIntTimer6(unsigned int config)  __attribute__ ((section (".libperi")));

/* Timer7 Config Bit Defines */

#define T7_ON               0xffff      /* Timer7 ON */
#define T7_OFF              0x7fff      /* Timer7 OFF */

#define T7_IDLE_CON         0xdfff      /* operate during sleep */
#define T7_IDLE_STOP        0xffff      /* stop operation during sleep */

#define T7_GATE_ON          0xffff      /* Timer Gate time accumulation enabled */
#define T7_GATE_OFF         0xffbf      /* Timer Gate time accumulation disabled */

#define T7_PS_1_1           0xffcf      /* Prescaler 1:1   */
#define T7_PS_1_8           0xffdf      /*           1:8   */
#define T7_PS_1_64          0xffef      /*           1:64  */
#define T7_PS_1_256         0xffff      /*           1:256 */

#define T7_SOURCE_EXT       0xffff      /* External clock source */
#define T7_SOURCE_INT       0xfffd      /* Internal clock source */

/* defines for Timer Interrupts */
#define T7_INT_PRIOR_7      0xffff      /* 111 = Interrupt is priority 7 */
#define T7_INT_PRIOR_6      0xfffe      /* 110 = Interrupt is priority 6 */
#define T7_INT_PRIOR_5      0xfffd      /* 101 = Interrupt is priority 5 */
#define T7_INT_PRIOR_4      0xfffc      /* 100 = Interrupt is priority 4 */
#define T7_INT_PRIOR_3      0xfffb      /* 011 = Interrupt is priority 3 */
#define T7_INT_PRIOR_2      0xfffa      /* 010 = Interrupt is priority 2 */
#define T7_INT_PRIOR_1      0xfff9      /* 001 = Interrupt is priority 1 */
#define T7_INT_PRIOR_0      0xfff8      /* 000 = Interrupt is priority 0 */

#define T7_INT_ON           0xffff      /* Interrupt Enable */
#define T7_INT_OFF          0xfff7      /* Interrupt Disable */

/* Macros to  Enable/Disable interrupts and set Interrupt priority of Timer 7 */
#define EnableIntT7                    asm("BSET IEC3,#1")
#define DisableIntT7                   asm("BCLR IEC3,#1")
#define SetPriorityIntT7(priority)     (IPC12bits.T7IP = priority)


/* Timer7 Function Declarations */

/* OpenTimer7
 * Configures Timer7
 */
void OpenTimer7(unsigned int config, unsigned int timer)  __attribute__ ((section
(".libperi")));

/* CloseTimer7
 * Disables Timer7
 */
void CloseTimer7(void)  __attribute__ ((section (".libperi")));

/* ReadTimer7
 * Reads Timer7
 */
unsigned int ReadTimer7(void)  __attribute__ ((section (".libperi")));

/* WriteTimer7
 * Writes Timer7
 */
void WriteTimer7(unsigned int timer)  __attribute__ ((section (".libperi")));

/* Config Int Timer 7*/
void ConfigIntTimer7(unsigned int config)  __attribute__ ((section (".libperi")));


/* Timer 67 mode using Timer 6 and Timer 7 */

/* OpenTimer67 */
void OpenTimer67(unsigned int config , unsigned long timer)  __attribute__ ((section
(".libperi")));

/* CloseTimer67 */
void CloseTimer67(void)  __attribute__ ((section (".libperi")));

/* ReadTimer67 */
unsigned long ReadTimer67(void)  __attribute__ ((section (".libperi")));

/* WriteTimer67 */
void WriteTimer67(unsigned long timer)  __attribute__ ((section (".libperi")));

/* Config Int Timer 67*/
void ConfigIntTimer67(unsigned int config)  __attribute__ ((section (".libperi")));
 

/* Timer8 Control Register (T8CON) Bit Defines */

#define T8_ON               0xffff      /* Timer8 ON */
#define T8_OFF              0x7fff      /* Timer8 OFF */

#define T8_IDLE_CON         0xdfff      /* operate during sleep */
#define T8_IDLE_STOP        0xffff      /* stop operation during sleep */

#define T8_GATE_ON          0xffff      /* Timer8 Gate time accumulation enabled  */
#define T8_GATE_OFF         0xffbf      /* Timer8 Gate time accumulation disabled */

#define T8_PS_1_1           0xffcf      /* Prescaler 1:1   */
#define T8_PS_1_8           0xffdf      /*           1:8   */
#define T8_PS_1_64          0xffef      /*           1:64  */
#define T8_PS_1_256         0xffff      /*           1:256 */

#define T8_32BIT_MODE_ON    0xffff      /* Timer 8 and Timer 9 form a 32 bit Timer */
#define T8_32BIT_MODE_OFF   0xfff7      

#define T8_SOURCE_EXT       0xffff      /* External clock source */
#define T8_SOURCE_INT       0xfffd      /* Internal clock source */

/* defines for Timer Interrupts */
#define T8_INT_PRIOR_7      0xffff      /* 111 = Interrupt is priority 7 */ 
#define T8_INT_PRIOR_6      0xfffe      /* 110 = Interrupt is priority 6 */
#define T8_INT_PRIOR_5      0xfffd      /* 101 = Interrupt is priority 5 */
#define T8_INT_PRIOR_4      0xfffc      /* 100 = Interrupt is priority 4 */
#define T8_INT_PRIOR_3      0xfffb      /* 011 = Interrupt is priority 3 */
#define T8_INT_PRIOR_2      0xfffa      /* 010 = Interrupt is priority 2 */
#define T8_INT_PRIOR_1      0xfff9      /* 001 = Interrupt is priority 1 */
#define T8_INT_PRIOR_0      0xfff8      /* 000 = Interrupt is priority 0 */

#define T8_INT_ON           0xffff      /* Interrupt Enable */  
#define T8_INT_OFF          0xfff7      /* Interrupt Disable */

/* Macros to  Enable/Disable interrupts and set Interrupt priority of Timers 2*/
#define EnableIntT8                    asm("BSET IEC3,#3")
#define DisableIntT8                   asm("BCLR IEC3,#3")
#define SetPriorityIntT8(priority)     (IPC12bits.T8IP = priority)



/* Timer8 Function Prototypes */

/* OpenTimer8 */
void OpenTimer2(unsigned int config, unsigned int period) __attribute__ ((section
(".libperi")));

/* CloseTimer8 */
void CloseTimer8(void) __attribute__ ((section (".libperi")));

/* ReadTimer8 */
unsigned int ReadTimer8(void) __attribute__ ((section (".libperi")));

/* WriteTimer8 */
void WriteTimer8( unsigned int timer) __attribute__ ((section (".libperi")));

/* ConfigIntTimer8 */
void ConfigIntTimer8(unsigned int ) __attribute__ ((section (".libperi")));


/* Timer9 Control Register (T3CON) Bit Defines */

#define T9_ON               0xffff      /* Timer9 ON */
#define T9_OFF              0x7fff      /* Timer9 OFF */

#define T9_IDLE_CON         0xdfff      /* operate during sleep */
#define T9_IDLE_STOP        0xffff      /* stop operation during sleep */

#define T9_GATE_ON          0xffff      /* Timer9 Gate  time accumulation enabled  */
#define T9_GATE_OFF         0xffbf      /* Timer Gate time accumulation disabled */

#define T9_PS_1_1           0xffcf      /* Prescaler 1:1   */
#define T9_PS_1_8           0xffdf      /*           1:8   */
#define T9_PS_1_64          0xffef      /*           1:64  */
#define T9_PS_1_256         0xffff      /*           1:256 */
#define T9_SOURCE_EXT       0xffff      /* External clock source */
#define T9_SOURCE_INT       0xfffd      /* Internal clock source */

/* defines for Timer Interrupts */
#define T9_INT_PRIOR_7      0xffff      /* 111 = Interrupt is priority 7 */ 
#define T9_INT_PRIOR_6      0xfffe      /* 110 = Interrupt is priority 6 */
#define T9_INT_PRIOR_5      0xfffd      /* 101 = Interrupt is priority 5 */
#define T9_INT_PRIOR_4      0xfffc      /* 100 = Interrupt is priority 4 */
#define T9_INT_PRIOR_3      0xfffb      /* 011 = Interrupt is priority 3 */
#define T9_INT_PRIOR_2      0xfffa      /* 010 = Interrupt is priority 2 */
#define T9_INT_PRIOR_1      0xfff9      /* 001 = Interrupt is priority 1 */
#define T9_INT_PRIOR_0      0xfff8      /* 000 = Interrupt is priority 0 */

#define T9_INT_ON           0xffff      /* Interrupt Enable */  
#define T9_INT_OFF          0xfff7      /* Interrupt Disable */

/* Macros to  Enable/Disable interrupts and set Interrupt priority of Timers 3*/
#define EnableIntT9                    asm("BSET IEC3,#4")
#define DisableIntT9                   asm("BCLR IEC3,#4")
#define SetPriorityIntT9(priority)     (IPC13bits.T9IP = priority)

/* Timer9 Function Prototypes */

/* OpenTimer9 */
void OpenTimer9(unsigned int config, unsigned int timer)  __attribute__ ((section
(".libperi")));

/* CloseTimer9 */
void CloseTimer9(void)  __attribute__ ((section (".libperi")));

/* ReadTimer9 */
unsigned int ReadTimer9(void)  __attribute__ ((section (".libperi")));

/* WriteTimer9 */
void WriteTimer9( unsigned int timer)  __attribute__ ((section (".libperi")));

/* ConfigIntTimer9  */
void  ConfigIntTimer9(unsigned int config)  __attribute__ ((section (".libperi")));


/* Timer 89 mode using Timer 8 and Timer9*/

/*Timer 89 bit mode Prototypes*/

/* OpenTimer89 */
void OpenTimer89(unsigned int config, unsigned long period)  __attribute__ ((section
(".libperi")));

/* CloseTimer89 */
void CloseTimer89(void)  __attribute__ ((section (".libperi")));

/* ReadTimer89 */
unsigned long ReadTimer89(void)  __attribute__ ((section (".libperi")));

/* WriteTimer89 */
void WriteTimer89(unsigned long timer)  __attribute__ ((section (".libperi")));

/* Config Int Timer 89*/
void ConfigIntTimer89(unsigned int config)  __attribute__ ((section (".libperi")));



#endif
