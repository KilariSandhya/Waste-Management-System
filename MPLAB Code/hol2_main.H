/*********************************************************************
*
*                   
*
*********************************************************************
* FileName:        hol2_main.H
* Dependencies:    See INCLUDES section below
* Processor:       
* Compiler:        MCC18 
* Company:         Microchip Technology, Inc.
*
* Software License Agreement
*
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
*
*
* Author               Date        Comment
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Microchip		  02-May-06	
********************************************************************/
#ifndef  hol2_main_H_
#define  hol2_main_H_

/** P R O T O T Y P E S ***************************************************************************/
//void Measure_Voltage(void);                  // Voltage measurement and display routine
void init_ADC(void);          // Initializes ADC module.
char get_ADC(void);              // Performs ADC
void initEUSART (void);			// Initializes UART

//extern void LCDInit(void);          // Refer LCD.C
//extern void LCDSupportFn1(void);
//extern void LCDSupportFn2(void);
//extern void bin_2_bcd(unsigned int);   // Refer Math.C
#endif

