
/******************************************************************************
 // *                  TIMERS PERIPHERAL LIBRARY HEADER FILE
 ******************************************************************************
 * FileName:        		timers.h
 * Dependencies:    	See include below
 * Processor:       		PIC18
 * Compiler:        		MCC18
 * Company:         		Microchip Technology, Inc.
 *
 * Software License Agreement
 * The software supplied herewith by Microchip Technology Incorporated
 * (the “Company”) for its PICmicro® Microcontroller is intended and
 * supplied to you, the Company’s customer, for use solely and
 * exclusively on Microchip PICmicro Microcontroller products. The
 * software is owned by the Company and/or its supplier, and is
 * protected under applicable copyright laws. All rights are reserved.
 * Any use in violation of the foregoing restrictions may subject the
 * user to criminal sanctions under applicable laws, as well as to
 * civil liability for the breach of the terms and conditions of this
 * license.
 *
 * THIS SOFTWARE IS PROVIDED IN AN “AS IS” CONDITION. NO WARRANTIES,
 * WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED
 * TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
 * PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. THE COMPANY SHALL NOT,
 * IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL OR
 * CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *****************************************************************************/
/* PIC18 timers peripheral library. */

/* used to hold 16-bit timer value */
union Timers
{
  unsigned int lt;
  char bt[2];
};


/* Interrupt bit mask to be 'anded' with the other configuration masks and
 /* passed as the 'config' parameter to the 'open' routines. */

//#ifndef USE_OR_MASKS
#define TIMER_INT_OFF  0b01111111  //Disable TIMER Interrupt
#define TIMER_INT_ON   0b11111111  //Enable TIMER Interrupt

/* ***** TIMER0 ***** */
/* TIMER0 configuration masks -- to be 'anded' together and passed to the
 * 'open' routine. */

#define T0_16BIT       0b10111111  //Timer0 is configured as an 16-bit timer/counter
#define T0_8BIT        0b11111111  //Timer0 is configured as an 8-bit timer/counter

#define T0_SOURCE_INT  0b11011111  //Internal instruction cycle clock (CLKO) acts as source of clock
#define T0_SOURCE_EXT  0b11111111  //Transition on TxCKI pin acts as source of clock

#define T0_EDGE_RISE   0b11101111  //Increment on low-to-high transition on TxCKI pin
#define T0_EDGE_FALL   0b11111111  //Increment on high-to-low transition on TxCKI pin

#define T0_PS_1_1      0b11111111  //1:1 Prescale value (NO Prescaler)
#define T0_PS_1_2      0b11110000  //1:2 Prescale value
#define T0_PS_1_4      0b11110001  //1:4 Prescale value
#define T0_PS_1_8      0b11110010  //1:8 Prescale value
#define T0_PS_1_16     0b11110011  //1:16 Prescale value
#define T0_PS_1_32     0b11110100  //1:32 Prescale value
#define T0_PS_1_64     0b11110101  //1:64 Prescale value
#define T0_PS_1_128    0b11110110  //1:128 Prescale value
#define T0_PS_1_256    0b11110111  //1:256 Prescale value




/* ***** TIMER2 ***** */
//#if defined (TMR_V2) || defined (TMR_V3) || defined (TMR_V4) ||\
//    defined (TMR_V5) || defined (TMR_V6) || defined (TMR_V7) || defined (TMR_V7_1)
/* TIMER2 configuration masks -- to be 'anded' together and passed to the
 * 'open' routine. */
//-----------------AND OR MASK----------------------

#define T2_POST_1_1    0b10000111  //Timer2 Postscaler 1:1
#define T2_POST_1_2    0b10001111  //Timer2 Postscaler 1:2
#define T2_POST_1_3    0b10010111  //Timer2 Postscaler 1:3
#define T2_POST_1_4    0b10011111  //Timer2 Postscaler 1:4
#define T2_POST_1_5    0b10100111  //Timer2 Postscaler 1:5
#define T2_POST_1_6    0b10101111  //Timer2 Postscaler 1:6
#define T2_POST_1_7    0b10110111  //Timer2 Postscaler 1:7
#define T2_POST_1_8    0b10111111  //Timer2 Postscaler 1:8
#define T2_POST_1_9    0b11000111  //Timer2 Postscaler 1:9
#define T2_POST_1_10   0b11001111  //Timer2 Postscaler 1:10
#define T2_POST_1_11   0b11010111  //Timer2 Postscaler 1:11
#define T2_POST_1_12   0b11011111  //Timer2 Postscaler 1:12
#define T2_POST_1_13   0b11100111  //Timer2 Postscaler 1:13
#define T2_POST_1_14   0b11101111  //Timer2 Postscaler 1:14
#define T2_POST_1_15   0b11110111  //Timer2 Postscaler 1:15
#define T2_POST_1_16   0b11111111  //Timer2 Postscaler 1:16
#define T2_PS_1_1      0b11111100  //Timer2 Prescale 1:1
#define T2_PS_1_4      0b11111101  //Timer2 Prescale 1:4
#define T2_PS_1_16     0b11111110  //Timer2 Prescale 1:16

#define T3_8BIT_RW      0b11111110 //Enables register read/write of Timer3 in two 8-bit operations
#define T3_16BIT_RW     0b11111111 //Enables register read/write of Timer3 in two 16-bit operations
#define T3_PS_1_1       0b11001111 //Timer3 1:1 prescale value
#define T3_PS_1_2       0b11011111 //Timer3 1:2 prescale value
#define T3_PS_1_4       0b11101111 //Timer3 1:4 prescale value
#define T3_PS_1_8       0b11111111 //Timer3 1:8 prescale value
#define T3_SYNC_EXT_ON  0b11111011 // Synchronize external clock input
#define T3_SYNC_EXT_OFF 0b11111111 // Do not synchronize external clock input
#define T3_SOURCE_INT   0b11111101 //Internal instruction cycle clock (CLKO) acts as source of clock
#define T3_SOURCE_EXT   0b11111111 //Transition on TxCKI pin acts as source of clock



void OpenTimer0 ( unsigned char config);
void CloseTimer0 (void);
unsigned int ReadTimer0 (void);
void WriteTimer0 ( unsigned int timer0);
void OpenTimer2 ( unsigned char config);
void CloseTimer2 (void);
void OpenTimer3 ( unsigned char config);
void CloseTimer3 (void);

