// ---------------------------------------------------------------------------
// *                        www.apsis-solutions.com
// *               Copyright (c) Apsis Solutions, Bangalore
// *--------------------------------------------------------------------------
// *    Project				: Generic
// *    Module 				: ADC 
// *    Description			: Used to Configure the ADC and Read ADC
// *	   Author			: Prakash Dabhi
// *    Workfile			: ADC.h
// *    Revision			: 1.0
// *    Last changed on		: Date: 2011-10-22 
// *                     
// *    Last changed on		: 2011-10-22
// *    Last changed by		:Prakash Dabhi
// *
// *--------------------------------------------------------------------------


#include "p18f46k22Generic.h"
#include <p18f46k22.h>


#define ACQUISITIONTIME		TAD_12
#define ADC_CLOCK 			FOSC_BY_2
#define ADC_MODE			ADC_8BIT_MODE

#define ADC_8BIT_MODE 	0
#define ADC_10BIT_MODE	1

#define CHANNEL_0 	0
#define CHANNEL_1 	1
#define CHANNEL_2 	2
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
#define CHANNEL_13 	13
#define CHANNEL_14 	14
#define CHANNEL_15 	15
#define CHANNEL_16 	16
#define CHANNEL_17 	17
#define CHANNEL_18 	18
#define CHANNEL_19 	19
#define CHANNEL_20 	20
#define CHANNEL_21 	21
#define CHANNEL_22 	22
#define CHANNEL_23 	23
#define CHANNEL_24 	24
#define CHANNEL_25 	25
#define CHANNEL_26 	26
#define CHANNEL_27 	27


//#define PASS 0
//#define FAIL 1



#define TAD_0			0
#define TAD_2			1
#define TAD_4			2
#define TAD_6			3
#define TAD_8			4
#define TAD_12			5
#define TAD_16			6
#define TAD_20			7

#define FOSC_BY_2		0
#define FOSC_BY_8		1
#define FOSC_BY_32		2
#define FOSC_RC_1		3
#define FOSC_BY_4		4
#define FOSC_BY_16		5
#define FOSC_BY_64		6
#define FOSC_RC_2		7

#define CONVERSIONINCOMPLETE		ADCON0bits.GO


// ****************************************************************************
unsigned int unfnReadADCChannel(unsigned char uchChannelNo, unsigned char uchADC8_10BitMode);
unsigned int unfnReadADC(unsigned char uchADC8_10BitMode);
void fnInitializeADC(void);
char fn_ch_Select_ADC_Channel(unsigned char uchChannelNo); 



