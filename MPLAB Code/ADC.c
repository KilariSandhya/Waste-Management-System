

// ---------------------------------------------------------------------------
// *                        www.apsis-solutions.com
// *               Copyright (c) Apsis Solutions, Bangalore
// *--------------------------------------------------------------------------
// *    Project         : Generic
// *    Module          : ADC 
// *    Description     : Used to Configure the ADC and Read ADC
// *    Author          : Prakash Dabhi
// *    Workfile        : ADC.c
// *    Revision        : 1.0
// *    Last changed on : Date: 2011-10-22 
// *                     
// *    Last changed on : 2011-07-28
// *    Last changed by : Prakash Dabhi
// *
// *--------------------------------------------------------------------------
// *  History: 
// *  1. Created the place holder for the file
// *  2. Added fnInitializeADC for initializing ADC by switching it on and
//       setting frequency of conversion and Acquisition time.
// *  3. Added fnAcquisitionTime for 32Mhz, 16Mhz, 8Mhz, 4Mhz, 2Mhz and 1Mhz.
// *  4. Added unfnReadADCChannel for allocating no. of channels, selecting 
//       channels, read ADC and returning the value
// *  5. Added unfnReadADC for reading ADC and returning the value.
// *  6. Added uchfnNumberOfAnalogChannels for setting pins as Analog.


// *--------------------------------------------------------------------------


#include <p18f46k22.h> 
#include "P18F46K22generic.h"
#include "PinAllocation.h"
#include "ADC.H"
/*
void init_ADC(void)
{
    ADCON0 = ADCON0_UNIMPLIMENTED|ADCON0_CHS4_CLR|ADCON0_CHS3_CLR|ADCON0_CHS2_CLR|ADCON0_CHS1_CLR|ADCON0_CHS0_CLR|ADCON0_DONE|ADCON0_ADON_ENABLE;		//Select ANO as an analog input channel              //### Turn On ADC and select channel 10	
	ADCON1 = ADCON1_TRIGSEL_CTMU|ADCON1_UNIMPLIMENTED_BIT6|ADCON1_UNIMPLIMENTED_BIT5|ADCON1_UNIMPLIMENTED_BIT4|ADC_VREF_CONNECTED_TO_INTERNAL_SIGNAL_AVDD| ADC_VREFNEG_CONNECTED_TO_INTERNAL_SIGNAL_AVSS;              //### Select Vref+ = VDD, Vref- = VSS, AN0 = Analog Input
	ADCON2 = ADCON2_ADFM_RIGHT|UNIMPLEMENTED|ADCON2_TAD_12|ADCON2_FOSC_BY_2;              //### Acquisition delay 12 TAD, A/D conversion clock 8TOSC
	ANSELA = 0X01;
} 

unsigned int get_ADC(void)
{

    ADCON0bits.GO = 1;          //### Start ADC.
	while(ADCON0bits.GO);       //### Wait until ADC completes.
	return(ADRESL+256*ADRESH);	//return the 10 bit output of thr ADC.
}

*/

#include <p18f46k22.h>  
#include "p18f46K22Generic.h"
#include "ADC.h"
#define FAIL 0
#define PASS 1
// ****************************************************************************
// *    Function Name      		: unfnReadADCChannel
// *    Description         	: This function is used to 
// *                        	: 1.Set the ADC Channel
// *                        	: 2.Read the ADC
// *                        	: 3.Returning the 8 bit or 10 bit Value  
// *                       
// *    Parameters          	: Arg1 -> chChannelNo: Defines which channel to be used
// *                          	: Arg2 -> uchADC8_10BitMode : Defines the range of the ADC output
// *    Globals Modified    	:
// *    Return Value        	: ADC converted value in Integer is returned        
// ****************************************************************************
unsigned int unfnReadADCChannel(unsigned char uchChannelNo, unsigned char uchADC8_10BitMode)
{
    
    fn_ch_Select_ADC_Channel(uchChannelNo);
	switch(uchADC8_10BitMode)
	{
		case ADC_8BIT_MODE:
						{   
							ADCON2 &= ~ADCON2_ADFM_RIGHT;   //Adjusting to Left Justify
							ADCON0 =ADCON0 | ADCON0_GO;     //TO start conversion
							while(CONVERSIONINCOMPLETE);
							return(ADRESH);
						}

		case ADC_10BIT_MODE:
						{   
							ADCON2 |= ADCON2_ADFM_RIGHT;
							ADCON0 = ADCON0 |ADCON0_GO;     //TO start conversion
							while(CONVERSIONINCOMPLETE);
					 
							return((ADRESH * 256) +ADRESL);
						}

	}
}


// ****************************************************************************
// *    Function Name      		: fnInitializeADC
// *    Description         	: This function is used to 
// *                        	: 1. Switch on ADC  
// *                        	: 2. Set the Acquisitiontime
// *							: 3. Clock frequenc for the ADC.
// *    Parameters          	: None
// *                      
// *    Globals Modified    	:
// *    Return Value        	:None
// ****************************************************************************

void fnInitializeADC(void)
{
    //Switch ADC ON
    ADCON0 =ADCON0_ADON_ENABLE;
    //select Reference voltage for ADC
    ADCON1 = ADCON1_TRIGSEL_CTMU|ADCON1_UNIMPLIMENTED_BIT6|ADCON1_UNIMPLIMENTED_BIT5|ADCON1_UNIMPLIMENTED_BIT4|ADC_VREF_CONNECTED_TO_INTERNAL_SIGNAL_AVDD| ADC_VREFNEG_CONNECTED_TO_INTERNAL_SIGNAL_AVSS;              //### Select Vref+ = VDD, Vref- = VSS, AN0 = Analog Input
  
	
	#if (ACQUISITIONTIME==TAD_0)                                  
        ADCON2 = ADCON2_TAD_0;
    #elif(ACQUISITIONTIME==TAD_2)
        ADCON2 = ADCON2_TAD_2;
	#elif(ACQUISITIONTIME==TAD_4)
		ADCON2 = ADCON2_TAD_4;
	#elif(ACQUISITIONTIME==TAD_6)
		ADCON2 = ADCON2_TAD_6;
	#elif(ACQUISITIONTIME==TAD_8)
		ADCON2 = ADCON2_TAD_8;
	#elif(ACQUISITIONTIME==TAD_12)
		ADCON2 = ADCON2_TAD_12;
	#elif(ACQUISITIONTIME==TAD_16)
		ADCON2 = ADCON2_TAD_16;
	#endif
	
	#if(ADC_CLOCK==FOSC_BY_2)
		ADCON2  = 	ADCON2|ADCON2_FOSC_BY_2;
	#elif(ADC_CLOCK==FOSC_BY_8)
		ADCON2 | = ADCON2_FOSC_BY_8;
	#elif(ADC_CLOCK==FOSC_BY_32)
		ADCON2 | = ADCON2_FOSC_BY_32;
	#elif(ADC_CLOCK==FOSC_RC_1)
		ADCON2 | = ADCON2_FOSC_RC_1;
	#elif(ADC_CLOCK==FOSC_BY_4)
		ADCON2 | = ADCON2_FOSC_BY_4;
	#elif(ADC_CLOCK==FOSC_BY_16)
		ADCON2 | = ADCON2_FOSC_BY_16;
	#elif(ADC_CLOCK==FOSC_BY_64)
		ADCON2 | = ADCON2_FOSC_BY_64;
	#elif(ADC_CLOCK==FOSC_RC_2)
		ADCON2 | = ADCON2_FOSC_RC_2;
	#endif

}


// ****************************************************************************
// *    Function Name		: chfnSelectADCChannel
// *    Description        	: This function is used to select the ADC channel and Configure the Channel to the Analog input channel
// *                          used for ADC 
// *    Parameters       	: Arg1 -> uchChannelNo: Selecting input channel 
// *                         	 from 0 to 27  
// *                      
// *    Globals Modified 	:
// *    Return Value     	: None 
// ****************************************************************************


char fn_ch_Select_ADC_Channel(unsigned char uchChannelNo) 
{
 
    switch(uchChannelNo)
    {
        //  Selecting channel 0
            case 0:
                {       
						TRISAbits.TRISA0 = 1;//as input
                        ANSELA |= ANSELA_ANSA0_SET;
                        ADCON0 = 0x01;
                        ADCON0 = ADCON0 | CHANNEL_AN0;
                        break;
                }
        //  Selecting channel 1
            case 1:
                {	
						TRISAbits.TRISA1 = 1;//as input
                        ANSELA |= ANSELA_ANSA1_SET;
                        ADCON0 = 0x01;
                        ADCON0 = ADCON0 | CHANNEL_AN1;
                        break;
					
//						ANSELA = ANSELA_ANSA1_SET;
//                        ADCON0 =  ADCON0 | CHANNEL_AN1;
//                        break;
                }
        //  Selecting channel 2
            case 2:
                {
						
						TRISAbits.TRISA2 = 1;//as input
                        ANSELA |= ANSELA_ANSA2_SET;
                        ADCON0 = 0x01;
                        ADCON0 = ADCON0 | CHANNEL_AN2;
                        break;
                }
        //  Selecting channel 3
            case 3:
                {
						TRISAbits.TRISA3 = 1;
						ANSELA = ANSELA_ANSA3_SET;
						ADCON0 = 0x01;
                        ADCON0 =  ADCON0 | CHANNEL_AN3;
                        break;
                }
        //  Selecting channel 4
            case 4:
                {
						TRISAbits.TRISA5 = 1;//as input
                        ANSELA |= ANSELA_ANSA5_SET;
                        ADCON0 = 0x01;
                        ADCON0 = ADCON0 | CHANNEL_AN4;
                        break;
                }
        //  Selecting channel 5
            case 5:
                {
						TRISEbits.TRISE0 = 1;//as input
                        ANSELE |= ANSELE_ANSE0_SET;
                        ADCON0 = 0x01;
                        ADCON0 = ADCON0 | CHANNEL_AN5;
                        break;
                }
        //  Selecting channel 6
            case 6:
                {	
						TRISEbits.TRISE1 = 1;//as input
                        ANSELE |= ANSELE_ANSE1_SET;
                        ADCON0 = 0x01;
                        ADCON0 = ADCON0 | CHANNEL_AN6;
                        break;
                }
        //  Selecting channel 7
            case 7:
                {
						TRISEbits.TRISE2 = 1;//as input
                        ANSELE |= ANSELE_ANSE2_SET;
                        ADCON0 = 0x01;
                        ADCON0 = ADCON0 | CHANNEL_AN7;
                        break;
                }
        //  Selecting channel 8
            case 8:
                {
						ANSELB = ANSELB_ANSB2_SET;
                        ADCON0 =  ADCON0 | CHANNEL_AN8;
                        break;
                }
        
        //  Selecting channel 9
            case 9:
                {
						ANSELB = ANSELB_ANSB3_SET;
                        ADCON0 =  ADCON0 | CHANNEL_AN9;
                        break;
                }
         //  Selecting channel 10
            case 10:
                {
						ANSELB = ANSELB_ANSB1_SET;
                        ADCON0 =  ADCON0 | CHANNEL_AN10;
                        break;
                }
         //  Selecting channel 11
            case 11:
                {
						ANSELB = ANSELB_ANSB4_SET;
                        ADCON0 =  ADCON0 | CHANNEL_AN11;
                        break;
                }
         //  Selecting channel 12
            case 12:
                {
						ANSELB = ANSELB_ANSB0_SET;
                        ADCON0 =  ADCON0 | CHANNEL_AN12;
                        break;
                }
                                
         //  Selecting channel 13 by default
            case 13:
                {
						ANSELB = ANSELB_ANSB5_SET;
                        ADCON0 =  ADCON0 | CHANNEL_AN13;
                        break;
                }
		//  Selecting channel 14 by default
            case 14:
                {
						TRISCbits.TRISC2 = 1;//as input
                        ANSELC |= ANSELC_ANSC2_SET;
                        ADCON0 = 0x01;
                        ADCON0 = ADCON0 | CHANNEL_AN14;
                        break;
                }
		//  Selecting channel 15 by default
            case 15:
                {
						ANSELC = ANSELC_ANSC3_SET;
                        ADCON0 =  ADCON0 | CHANNEL_AN15;
                        break;
                }
		//  Selecting channel 16 by default
            case 16:
                {
						ANSELC = ANSELC_ANSC4_SET;
                        ADCON0 =  ADCON0 | CHANNEL_AN16;
                        break;
                }
		//  Selecting channel 17 by default
            case 17:
                {
						ANSELC = ANSELC_ANSC5_SET;
                        ADCON0 =  ADCON0 | CHANNEL_AN17;
                        break;
                }
		//  Selecting channel 18 by default
            case 18:
                {
						ANSELC = ANSELC_ANSC6_SET;
                        ADCON0 =  ADCON0 | CHANNEL_AN18;
                        break;
                }
		//  Selecting channel 19 by default
            case 19:
                {
						ANSELC = ANSELC_ANSC7_SET;
                        ADCON0 =  ADCON0 | CHANNEL_AN19;
                        break;
                }
		//  Selecting channel 20 by default
            case 20:
                {
						ANSELD = ANSELD_ANSD0_SET;
                        ADCON0 =  ADCON0 | CHANNEL_AN20;
                        break;
                }
		//  Selecting channel 21 by default
            case 21:
                {
						ANSELD = ANSELD_ANSD1_SET;
                        ADCON0 =  ADCON0 | CHANNEL_AN21;
                        break;
                }
		//  Selecting channel 22 by default
            case 22:
                {
						ANSELD = ANSELD_ANSD2_SET;
                        ADCON0 =  ADCON0 | CHANNEL_AN22;
                        break;
                }
		//  Selecting channel 23 by default
            case 23:
                {
						ANSELD = ANSELD_ANSD3_SET;
                        ADCON0 =  ADCON0 | CHANNEL_AN23;
                        break;
                }
		//  Selecting channel 24 by default
            case 24:
                {
						ANSELD = ANSELD_ANSD4_SET;
                        ADCON0 =  ADCON0 | CHANNEL_AN24;
                        break;
                }
		//  Selecting channel 25 by default
            case 25:
                {
						ANSELD = ANSELD_ANSD5_SET;
                        ADCON0 =  ADCON0 | CHANNEL_AN25;
                        break;
                }
		//  Selecting channel 26 by default
            case 26:
                {
						ANSELD = ANSELD_ANSD6_SET;
                        ADCON0 =  ADCON0 | CHANNEL_AN26;
                        break;
                }
		//  Selecting channel 27 by default
            case 27:
                {
						ANSELD = ANSELD_ANSD7_SET;
                        ADCON0 =  ADCON0 | CHANNEL_AN27;
                        break;
                }
		//  Selecting channel 28 by default
            case 28:
                {
						
                        ADCON0 =  ADCON0 | RESERVED;
                        break;
                }
		//  Selecting channel 29 by default
            case 29:
                {
                        ADCON0 =  ADCON0 | CTMU;
                        break;
                }
		//  Selecting channel 30 by default
            case 30:
                {
                        ADCON0 =  ADCON0 | DAC;
                        break;
                }
		//  Selecting channel 31 by default
            case 31:
                {
                        ADCON0 =  ADCON0 | FVR_BUF2;
                        break;
                }	
    }   
    return(PASS);
}
    

