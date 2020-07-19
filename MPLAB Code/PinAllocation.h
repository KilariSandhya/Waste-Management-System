// ---------------------------------------------------------------------------
// *                        www.apsis-solutions.com
// *               Copyright (c) Apsis Solutions, Bangalore
// *--------------------------------------------------------------------------
// *    Project         : Generic
// *    Module          : ADC 
// *    Description     : Used to Configure the ADC and Read ADC
// *    Author          : Pankaj Sharma
// *    Workfile        : PinAllocation.h
// *    Revision        : 1.0
// *    Last changed on : Date: 2012-04-17
// *                     
// *    Last changed by : Pankaj Sharma
// *
// *--------------------------------------------------------------------------

#include<p18f46k22.h>


// Pin allocation.h
#define DEBUGMODE		1
#define RELEASEMODE	 	0
#define MODE			RELEASEMODE
#define DBGPRINTF if(MODE) printf

#define GPSMODE			RELEASEMODE
#define GPSDBGPRINTF	if(GPSMODE) printf

#define FAIL	0
#define PASS	1

#define SET_ANALOG   1
#define SET_DIGITAL  0

#define SET_INPUT   1
#define SET_OUTPUT  0

#define SET_TRUE 	1
#define SET_FALSE 	0

#define OUTPUT_HIGH  1
#define OUTPUT_LOW   0

#define ON 1
#define OFF 0

#define SELECT_GPS_ON_UART	1
#define SELECT_RFID_ON_UART	2
#define SELECT_PC_ON_UART		3



//  Configuration of LCD pins: 4 data pins, RS pin and Enable pin

#define RS_lcd          LATDbits.LATD0   	// For Selection of data or Command Mode.  				
#define Enable_lcd		LATDbits.LATD1   	// For Enabling the LCD.
#define lcd_d4_lsb		LATDbits.LATD2  	// pin 11 of LCD
#define lcd_d5			LATDbits.LATD3  	// pin 12 of LCD
#define lcd_d6			LATDbits.LATD4   	// pin 13 of LCD
#define lcd_d7_msb		LATDbits.LATD5   	// pin 14 of LCD	

// Direction selection of the PIC controller. The pin selected either as input or output as per the requirement
#define RS_lcd_dir          TRISDbits.TRISD0     				
#define Enable_lcd_dir		TRISDbits.TRISD1   
#define lcd_d4_lsb_dir		TRISDbits.TRISD2   // pin 11 of LCD DIR
#define lcd_d5_dir			TRISDbits.TRISD3   // pin 12 of LCD DIR
#define lcd_d6_dir			TRISDbits.TRISD4   // pin 13 of LCD DIR
#define lcd_d7_msb_dir		TRISDbits.TRISD5   // pin 14 of LCD DIR


#define  SWITCH			PORTCbits.RC0
#define  Dir_SWITCH     TRISCbits.TRISC0 


//#define  Dir_LEDSW			TRISDbits.TRISD0
//#define  Dir_SW		   		TRISDbits.TRISD1 
//
//
//#define  LEDSW		   		LATDbits.LATD0
//#define  SW	      			PORTDbits.RD1

#define  Dir_LEDSW			TRISEbits.TRISE0
#define  Dir_SW		   		TRISEbits.TRISE1 


#define  LEDSW		   		LATEbits.LATE0
#define  SW	      			PORTEbits.RE1


#define  Dir_LED1			TRISBbits.TRISB0
#define  Dir_LED2		   	TRISBbits.TRISB1 


#define  LED1		   		LATBbits.LATB0
#define  LED2      			LATBbits.LATB1

//#define  Dir_Copy_LED1		TRISDbits.TRISD0
//#define  Dir_Copy_LED2   	TRISDbits.TRISD1 


//#define  Copy_LED1		   	LATDbits.LATD0
//#define  Copy_LED2      	LATDbits.LATD1

//#define  FAN2		   LATAbits.LATA0
//#define  Dir_FAN2      TRISAbits.TRISA0  
//
//
//#define  LIG2		   LATAbits.LATA2
//#define  Dir_LIG2      TRISAbits.TRISA2 
		
