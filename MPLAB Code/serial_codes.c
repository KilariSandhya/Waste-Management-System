// ---------------------------------------------------------------------------
// *                        www.apsis-solutions.com
// *               Copyright (c) Apsis Solutions, Bangalore
// *--------------------------------------------------------------------------
// *    Project         : Generic
// *    Module          : UART
// *    Description     : Used to Initialised UART,Send and Receive the data through UART.Here we have two UART
// *					  We can select any of that as per our requirement.	  
// *    Author          : Madhusudhan BL
// *    Workfile        : serial_codes.c
// *    Revision        : 2.0
// *    Last changed on : Date: 2016-07-13 
// *                     
// *    Last changed on : 2016-07-14
// *    Last changed by : Madhusudhan BL
// *
// *--------------------------------------------------------------------------

#include<p18f46k22.h>
#include "serial_codes.h"
#include "P18F46K22generic.h"
#include "timers.h"

// ****************************************************************************
// *    Function Name      			: fn_Initialize_Serial
// *    Description         		: This function is used to 
// *                        		: 1. Set the TXSTAX and RXSTAX register
// *                        		: 2. Set the baudrate for UART1 and UART2
// *                        		
// *    Parameters          		: Arg1 -> uchSelectUART: Selct the UART1 or UART2                     		
// *    Globals Modified    	:
// *    Return Value        	: ADC converted value in Integer is returned        
// ****************************************************************************

void fn_Initialize_Serial(unsigned char uchSelectUART)
{
   /* TODO: Write code to
    Description: For SFR configuration refer word doc file provided 
	1. Enable Transmitter and select High Baud Rate in TXSTA1 and TXSTA2.
	2. Select a value in SPGRB1 and SPGRB2 register to generate 9600 baud rate 
	3. Enable Serial port in RCSTAX register
	4. Enable continuous reception in RCSTA1 and RCSTA2
	5. Clear Transmit interrupt flag initially in PIR1<TX1IF> and PIR3<TX2IF> register
	6. Clear Receive interrupt flag initially in PIR1<RC1IF> and PIR3<RC2IF> register
	7. Disable Trasmit complete interrupt in in PIE1<TX1IE> and PIE1<TX2IE> register
	8. Enable receive interrupt in PIE1<RC1IE> and PIE3<RC2IE>register	
	9. Enable Peripheral interrupt in INTCON <PEIE>
	10. Enable Global interrupt in INTCON<GIE>
	


  **************************************************************************************************/
	 
	switch(uchSelectUART)
	{
		case UART1:
 	  			  
				TXSTA1 				= 0x00;
				RCSTA1 				= 0x00;
				BAUDCON1 			= 0x00;
				
				SPBRG1				= BAUDRATE_9600;         // ### Select the baud rate 9600 for uart1  at frequency 4MHZ(SYNC = 0, BRGH = 1, BRG16 = 0)
				
				TRISCbits.TRISC6	= 1;
				TRISCbits.TRISC7	= 1;
				ANSELCbits.ANSC6	= 0;
				ANSELCbits.ANSC7	= 0;
				
				//			(SYNC = 0, BRGH = 1, BRG16 = 0)			 
				TXSTA1bits.SYNC		= 0;	// Clearing SYNC Bit for Enableing Asynchronous Serial PORT 
				TXSTA1bits.BRGH		= 1;	// Set for High Speed Transmission
				BAUDCON1bits.BRG16	= 0;	// Clear BRG16 
				
				RCSTA1bits.SPEN		= 1;	// Setting SPEN For Enabling Asynchronous Serial Port
				TXSTA1bits.TX9		= 0;	// Disable 9th Bit Transmission
				RCSTA1bits.RX9		= 0;	// Disable 9th Bit Receive
				BAUDCON1bits.CKTXP	= 0;	// Idle state for Tx is High
				BAUDCON1bits.DTRXP	= 0;	// Data Receicve is not Inverted
                TXSTA1bits.TXEN		= 1;	// Enable Asynchronous Transmission
                RCSTA1bits.CREN		= 1;	// Enable Continuous Reception
 
				PIE1bits.TX1IE		= 0;    // ### Clear Transit interrupt enable bit
				PIE1bits.RC1IE		= 0;    // ### Set Receive interrupt enable bit          
				IPR1bits.RC1IP		= 1;
				
 				break;
					
        case UART2:
        
				TXSTA2 				= 0x00;
				RCSTA2 				= 0x00;
				BAUDCON2 			= 0x00;
				
				SPBRG2				= BAUDRATE_9600;         // ### Select the baud rate 9600 for uart2  at frequency 4MHZ(SYNC = 0, BRGH = 1, BRG16 = 0)
				
				TRISDbits.TRISD6	= 1;
				TRISDbits.TRISD7	= 1;
				ANSELDbits.ANSD6	= 0;
				ANSELDbits.ANSD7	= 0;
				
				//			(SYNC = 0, BRGH = 1, BRG16 = 0)			 
				TXSTA2bits.SYNC		= 0;	// Clearing SYNC Bit for Enableing Asynchronous Serial PORT 
				TXSTA2bits.BRGH		= 1;	// Set for High Speed Transmission
				BAUDCON2bits.BRG16	= 0;	// Clear BRG16 
				
				RCSTA2bits.SPEN		= 1;	// Setting SPEN For Enabling Asynchronous Serial Port
				TXSTA2bits.TX9		= 0;	// Disable 9th Bit Transmission
				RCSTA2bits.RX9		= 0;	// Disable 9th Bit Receive
				BAUDCON2bits.CKTXP	= 0;	// Idle state for Tx is High
				BAUDCON2bits.DTRXP	= 0;	// Data Receicve is not Inverted
                TXSTA2bits.TXEN		= 1;	// Enable Asynchronous Transmission
                RCSTA2bits.CREN		= 1;	// Enable Continuous Reception
 
				PIE3bits.TX2IE		= 0;    //### Clear Transit interrupt enable bit
				PIE3bits.RC2IE		= 0;    // ### Set Receive interrupt enable bit           
				IPR3bits.RC2IP		= 1;
				
 				break;             
	}		
	INTCONbits.GIE	= 1;     // ### Enable Global interrupt	
	INTCONbits.PEIE = 1; 	 // ### Enable Peripheral Interrupt
}

// ****************************************************************************
// *    Function Name      			: fnTransmit_Serial
// *    Description         		: This function is used to 
// *                        		: 1. Send the character to UART1 or UART2
// *                       
// *    Parameters          		: Arg1 -> uchTransmit_data: Defines the charecter to be transmitted.
// *                          		: Arg2 -> uchSelectUART : Selct the UART1 or UART2
// *    Globals Modified    		:
// *    Return Value        		: None    
// ****************************************************************************
void fnTransmit_Serial(unsigned char uchTransmit_data,unsigned char uchSelectUART)
{

	switch(uchSelectUART)
	{
		case UART1:
				{
				PIR1bits.TX1IF = 0;
				TXREG1 = uchTransmit_data;
				while (!TXSTA1bits.TRMT);
				TXSTA1bits.TRMT=0;
				PIR1bits.TX1IF = 0;
				break;
				}
	
		case UART2:
				{
				PIR3bits.TX2IF = 0;
				TXREG2 = uchTransmit_data;
				while (!TXSTA2bits.TRMT);
				TXSTA2bits.TRMT=0;
				PIR3bits.TX2IF = 0;
				break;
				}
	}
				
}

// ****************************************************************************
// *    Function Name      			: uchfnReceive_Serial
// *    Description         		: This function is used to 
// *                        		: 1. Receive the data through UART
// *                        		
// *    Parameters          		: Arg1 -> uchSelectUART:  Selct the UART1 or UART2
// *                          		
// *    Globals Modified    		:
// *    Return Value        		: Received character is returned       
// ****************************************************************************
unsigned char uchfnReceive_Serial(unsigned char uchSelectUART)
{
	unsigned char uchReceive_data1,uchReceive_data2;
	switch(uchSelectUART)
	{
	case UART1:	PIR1bits.RC1IF = 0;
				while (!PIR1bits.RC1IF);
				if(RCSTA1bits.FERR==1 || RCSTA1bits.OERR==1 )
			    {
			      RCSTA1bits.CREN=0;    //Overrun error (can be cleared by clearing bit CREN)
			      uchReceive_data1=RCREG1;    //clear Framing error 
			      RCSTA1bits.CREN=1;
				}
				uchReceive_data1=RCREG1;
				PIR1bits.RC1IF = 0;
				return uchReceive_data1;
				break;
	case UART2:			
				PIR3bits.RC2IF = 0;		
				while (!PIR3bits.RC2IF);
				if(RCSTA2bits.FERR==1 || RCSTA2bits.OERR==1 )
			    {
			      RCSTA2bits.CREN=0;    //Overrun error (can be cleared by clearing bit CREN)
			      uchReceive_data2=RCREG2;    //clear Framing error 
			      RCSTA2bits.CREN=1;
				}
				uchReceive_data2=RCREG2;
				PIR3bits.RC2IF = 0;
				RC2STAbits.CREN = 1;
				return uchReceive_data2;
				break;
	}
}
void fnUARTPutString(unsigned char* string,unsigned char uchSelectUART) 
{
	  switch(uchSelectUART)
	 {
		case UART1:
					while(*string)
					{
					fnTransmit_Serial(*string,UART1);
					string++;
					}
					break;
		case UART2:
					while(*string)
					{
					fnTransmit_Serial(*string,UART2);
					string++;
					}
					break;
	}
}



	
