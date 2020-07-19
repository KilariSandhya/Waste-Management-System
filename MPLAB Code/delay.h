void Delay_1ms(void);
void delay_in_half_seconds(unsigned char uchcount);
void delay_in_seconds(unsigned char uch_Count);
void Delay_in_ms(unsigned int uint_Count1);

/*
// ---------------------------------------------------------------------------
// *                        www.apsis-solutions.com
// *               Copyright (c) Apsis Solutions, Bangalore
// *--------------------------------------------------------------------------
// *    Project			: Generic
// *    Module 			: ADC 
// *    Description		: Used to Configure the ADC and Read ADC
// *	   Author			: Bharat Vishal Tiwary
// *    Workfile			: ..\ADC.h
// *    Revision			: 1.0
// *    Last changed on	: Date: 2011-07-28 
// *                     
// *    Last changed on	: 2011-07-28
// *    Last changed by	: Bharat Vishal Tiwary
// *
// *--------------------------------------------------------------------------
// *  History: 
// *  1. Added fnInitializeADC.
// *  2. Added fnAcquisitionTime. 
// *  3. Added unfnReadADCChannel. 
// *  4. Added unfnReadADC. 
// *  5. Added uchfnNumberOfAnalogChannels. 
// *  
// ---------------------------------------------------------------------------	

#include "p18f4520Generic.h"
#include <p18f4520>

#define CHANNEL_0 	0
#define CHANNEL_1 	1
#define CHANNEL_2	2
#define CHANNEL_3 	3
#define CHANNEL_4 	4
#define CHANNEL_5 	5
#define CHANNEL_6 	6
#define CHANNEL_7 	7
#define CHANNEL_8 	8
#define CHANNEL_9 	9
#define CHANNEL_10 	10
#define CHANNEL_11 	11
#define CHANNEL_12 	12

#define PASS 0
#define FAIL 1

#define ADC8BIT 	0
#define ADC10BIT 	1



#define ANALOGVOLTAGEREF 			1
#define ANALOGVOLTAGEREFEXT			1
#define ANALOGVOLTAGEREFVCCVSS		0

#define CONVERSIONINCOMPLETE		ADCON0bits.GO


unsigned int unfnReadADCChannel(char chChannelNo, char chADC8_10BitMode);
void uchfnNumberOfAnalogChannels(unsigned char uchNoOfChannel);
unsigned int unfnReadADC(char chADC8_10BitMode);
void fnInitializeADC(void);
char chfnSelectADCChannel(char chChannelNo) ;
void fnAcquisitionTime(void);
*/