// ---------------------------------------------------------------------------
// *                        www.apsis-solutions.com
// *               Copyright (c) Apsis Solutions, Bangalore
// *--------------------------------------------------------------------------
// *    Project         : Generic
// *    Module          : WIFIMODULE
// *    Description     : Used to Send and Receive the data through ESP8266 WIFI module To/from The websites.
// *					  We can select any of that as per our requirement.	  
// *    Author          : Santhosh Kumar N
// *    Workfile        : wifimodule.c
// *    Revision        : 2.0
// *    Last changed on : Date: 201-09-29 
// *                     
// *    Last changed by : Ajith Kirlaya
// *
// *--------------------------------------------------------------------------



#include <p18f46k22.h>    
#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#include "wifimodule.h"
#include "serial_codes.h"
#include "ProjectMain.h"  
#include "serial_codes.h"
#include "ADC.H" 
#include "PinAllocation.h"
#include "LCD.h"
#include "delay.h"

extern unsigned int guchDataTowebsite;

unsigned char WIFIPattern[5][9] = 
					{
						"OK", 			// Pattern 0 
						"CONNECTED", 	// Pattern 1 
						"ERROR",		// Pattern 2 
						"FAIL",			// Pattern 3 
						"LINKED"  		// Pattern 4 
					};
					
unsigned char guchSSIDName[]= "unigps";  // Name of the ssid ..Hotspot name
unsigned char guchSSIDPassword[] = "thakur50076";// Password of Network
unsigned char guchURLWebsite[] = "api.thingspeak.com";// website

unsigned char MAIN_URL[] = "https://api.thingspeak.com/update?api_key=";
unsigned char HOST_WEBSITE[] = "api.thingspeak.com";
unsigned  char API_POSTkey[]="GY7TCGD9J0VNFY9M";  /// API key for indiviaul channels

unsigned char guchChannelNumber[8]="472615"; // channnel number 
unsigned char guchFieldNumber=1;// field Number 


unsigned char guchTempFieldStore[15];
unsigned char guchBuffer[];

unsigned char gunWifiResponse;
unsigned char guchStoreString[20];

unsigned int  gunStrlenGETRequest;
unsigned int  gunStrlenChannel;

unsigned char guchField5Value;

extern unsigned char gunField1Value,gunField2Value,gunField3Value,gunField4Value, gunField5Value, gunField6Value;

#pragma udata udata1

/// esp module varibales
unsigned char guchPostData1[70]; 
//unsigned char uchBuffer[20]; 
unsigned int gunStrlenPostData = 0;
unsigned int gunStrlenMAINURL = 0;
unsigned int gunStrlenPOSTKEY = 0;
unsigned int gunStrlenHOST_WEB = 0;
unsigned int gunCIPSENDlenPOST = 0;
unsigned char uchStrToKeepConAlive1[] = "Content-Type: application\/x-www-form-urlencoded\r\n\r\nAccept: *\/*\r\n";


void fnConnectToAp(void)
{
	fnSendAPCommand();
	
	fnSendDoubleQuote();
	fnSendSSIDName();
	fnSendDoubleQuote();
	
	fnSendComma();
	
	fnSendDoubleQuote();
	fnSendSSIDPassword();
	fnSendDoubleQuote();
	
	fnSendCarriageReturn();
	fnSendNewLine();
	
    delay_in_seconds(10);
}

void fnConnectTowebsite(void)
{ 
	fnTCPRequest();
		
	delay_in_seconds(8);
	
	fnSendDataToWeb(guchDataTowebsite); 
		
    fnHOSTWeb();
	
    fnKeepConAlive();
	
}	

void fnDatauploadTothingspeakwebsite(void)
{
	fnConnectToAp();
	fnFieldDataMerge();
	fnConnectTowebsite();	
	// Connect TO Access point 
}

void fnWifiResponse(void)
{
	gunWifiResponse = uchfnReceive_Serial(UART1);
	if(strstrrampgm(gunWifiResponse,WIFIPattern[1]))
	{
		strcpypgm2ram(guchStoreString,"Device is connected to network\n\r");
		fnUARTPutString(guchStoreString,UART2);
		//printf("Device is connected to network\n\r");
	}
}

void fnSendAPCommand(void)
{
	unsigned char uchAccPointComm[] = "AT+CWJAP=";
	
	fnUARTPutString(uchAccPointComm,UART2);

}

void fnSendSSIDName(void)
{
	//unsigned char uchSSIDName[] = "VIBE K5 NOTE";
	
	fnUARTPutString(guchSSIDName,UART2);
}

void fnSendDoubleQuote(void)
{
	unsigned char uchDoubleQuote[] = "\"";
	
	fnUARTPutString(uchDoubleQuote,UART2);	

}

void fnSendComma(void)
{
	unsigned char uchComma = ',';
	
	fnTransmit_Serial(uchComma,UART2);
}

void fnSendSSIDPassword(void)
{
	//unsigned char uchSSIDPassword[] = "IDOGREATTHINGS";
	
	fnUARTPutString(guchSSIDPassword,UART2);
}

void fnSendCarriageReturn(void)
{
	unsigned char uchCarriageReturn = '\r';
	
	fnTransmit_Serial(uchCarriageReturn,UART2);
}

void fnSendNewLine(void)
{
	unsigned char uchNewLine = '\n';
	
	fnTransmit_Serial(uchNewLine,UART2);
}

void fnIPStartCommand(void)
{
	unsigned char uchIPStart[] = "AT+CIPSTART=";
	
	fnUARTPutString(uchIPStart,UART2);
}

void fnSendTCP(void)
{
	unsigned char uchTCP[] = "TCP";
	
	fnUARTPutString(uchTCP,UART2);
}

void fnSendURLWebsite(void)
{
	//unsigned char uchURLWebsite[] = "api.thingspeak.com";

	fnUARTPutString(guchURLWebsite,UART2);
}

void fnSendPortNumber(void)
{
	unsigned char uchPortNumber[] = "80";
	
	fnUARTPutString(uchPortNumber,UART2);
}

void fnSendDataToWeb(unsigned int unData)
{
	unsigned char uchPost[] = "POST ";

	guchBuffer[0]='\0';

	
	gunStrlenPostData=strlen(guchPostData1);
	gunStrlenMAINURL=strlen(MAIN_URL);
	gunStrlenPOSTKEY=strlen(API_POSTkey);
	gunStrlenHOST_WEB=strlen(HOST_WEBSITE);
	
	gunCIPSENDlenPOST = gunStrlenMAINURL+gunStrlenPOSTKEY+gunStrlenHOST_WEB+gunStrlenPostData+CHAR_LEN_WEBINFO;
//	printf(" CIP lenght =%d",gunCIPSENDlenPOST);
	sprintf(guchBuffer,"%d",gunCIPSENDlenPOST);
	fnSendIPSENDCommand();
	fnUARTPutString(guchBuffer,UART2);
	
	fnSendCarriageReturn();
	fnSendNewLine();
	
	//printf("AT+CIPSEND=%d\r\n",gunCIPSENDlenPOST);
    delay_in_seconds(4);
    
    fnUARTPutString(uchPost,UART2);  
    
	//printf("POST ");
    
    fnUARTPutString(MAIN_URL,UART2);
    fnUARTPutString(API_POSTkey,UART2);
    fnUARTPutString(guchPostData1,UART2);
    	
}

void fnTCPRequest(void)
{
	fnIPStartCommand();
	fnSendDoubleQuote();
	fnSendTCP();
	fnSendDoubleQuote();
	
	fnSendComma();
	
	fnSendDoubleQuote();
	fnSendURLWebsite();
	fnSendDoubleQuote();
	
	fnSendComma();
	fnSendPortNumber();
	
	fnSendCarriageReturn();
	fnSendNewLine();
}

void fnSendIPSENDCommand(void)
{
	unsigned char uchIPSENDCommand[] = "AT+CIPSEND=";
	
	fnUARTPutString(uchIPSENDCommand,UART2);
}

void fnHOSTWeb(void)
{
	unsigned char uchHost[] = " HTTP\/1.1\r\nHost: ";
    
    fnUARTPutString(uchHost,UART2);
	//printf(" HTTP\/1.1\r\nHost: ");
   
	fnUARTPutString(HOST_WEBSITE,UART2);
	//printf("%s",HOST_WEBSITE);
}

void fnKeepConAlive(void)
{
	unsigned char uchStrToKeepConAlive[] = "\r\nConnection: keep-alive\r\nContent-Length: 0\r\nCache-Control: no-cache\r\n";
	
	fnUARTPutString(uchStrToKeepConAlive,UART2);
	
	fnUARTPutString(uchStrToKeepConAlive1,UART2);
	
	
}

void fnCollectDataFromWebsite(void)
{

	unsigned char uchCIPsendcount[];
	
	unsigned int  undatasend1=115;
	
	delay_in_seconds(8);
	uchCIPsendcount[0]='\0';

	fnTCPRequest();
	delay_in_seconds(10);
/*	fnSendIPSENDCommand();
			

	sprintf(uchCIPsendcount,"%d",undatasend1);
	fnUARTPutString(uchCIPsendcount,UART2);

	fnSendNewLine();
	fnSendCarriageReturn();
//	printf("AT+CIPSEND=115\r\n");

*/
	fnCipsend();
	delay_in_seconds(4);
	fnGetRequestCommand();
	
//	printf("GET https://api.thingspeak.com/channels/282444/fields/4/last.json HTTP\/1.1\r\nHost: api.thingspeak.com\r\n\r\nAccept: */*");



}




// ****************************************************************************
// *    Function Name      			: fnGetRequestCommand
// *    Description         		: This function is used to 
// *                        		: send to following command to Esp module GET https://api.thingspeak.com/channels/282444/fields/4/last.json HTTP\/1.1\r\nHost: api.thingspeak.com\r\n\r\nAccept: */*
// *                        		: 
// *                        		
// *    Parameters          		: Void                    		
// *    Globals Modified    	:
// *    Return Value        	: void        
// ****************************************************************************



void fnGetRequestCommand(void)   
{

//	unsigned char uchGetData[50];
//	sprintf(uchGetData,"GET https://api.thingspeak.com/channels/296627/fields/4/last.json HTTP\/1.1\r\nHost: api.thingspeak.com\r\n\r\nAccept: */*\n\r");

	fnsendGET();
	fnSendWebsiteURL();
	fnSendChannelNumberAndFieldnumber();
	fnHOSTWeb();	
//	fnSendWebsiteURL();
	fnSendAccept();
	
	
	//delay_in_seconds(8);
//	fnUARTPutString(uchGetData,UART2);

}


void fnsendGET(void)
{
	unsigned char uchTemp[20];
	sprintf(uchTemp,"GET https://");
	fnUARTPutString(uchTemp,UART2);
	
}

void fnSendWebsiteURL(void)
{	
	fnUARTPutString(guchURLWebsite,UART2);
}


void fnSendChannelNumberAndFieldnumber(void)
{
	unsigned char uchTempData[40];
	sprintf(uchTempData,"/channels/%s/fields/%d/last.json",guchChannelNumber,guchFieldNumber);
	fnUARTPutString(uchTempData,UART2);
}



void fnSendAccept(void)
{
	unsigned char uchTemp[20];
	sprintf(uchTemp,"\r\n\r\nAccept: */*\n\r");
	fnUARTPutString(uchTemp,UART2);
}

void fnCipsend(void)
{

	unsigned char uchCipData[40];
	gunStrlenChannel=strlen(guchChannelNumber);
	gunStrlenGETRequest=CHAR_LEN_WEBINFO_GET+gunStrlenChannel;	
	{
	sprintf(uchCipData,"AT+CIPSEND=%d\r\n",gunStrlenGETRequest);
	fnUARTPutString(uchCipData,UART2);
	}
}

void fnExtractDataField(void)
{
	unsigned char uchfieldData[45];
	unsigned char uchspecialChar;
	unsigned char uchTemprecieve;
	unsigned char i=0,j=0;
//	unsigned int FieldValue[];

  	while((uchspecialChar = uchfnReceive_Serial(UART2))!= '{');
	for(i=0;i<9;i++)
	{
	while((uchspecialChar = uchfnReceive_Serial(UART2))!= '"');
	}
	i=0;
	while((uchTemprecieve = uchfnReceive_Serial(UART2))!= '"')
	{
		uchfieldData[i]=uchTemprecieve;
		i++;
	}	
	uchfieldData[i]=0;
	guchField5Value=uchfieldData[0];
	
//	fnUARTPutString(uchfieldData,UART1);
	printf("Current Value in the Field %d  of Channel number %s is %s\n\r",guchFieldNumber,guchChannelNumber,uchfieldData);

 }




void fnFieldDataMerge(void)
{

	guchTempFieldStore[0]='\0';
	guchPostData1[0]='\0';
//	uchTempvalue[0]='\0';
	
	if(gunField1Value!=-1)
	{
	
		sprintf(guchPostData1,"&field1=%d",gunField1Value);//
//		printf("%s\n\r",guchPostData1);
	
		//printf("%s\n\r",guchPostData);
	}
	if(gunField2Value!=-1)
	{	
		
		guchTempFieldStore[0]='/0';
		sprintf(guchTempFieldStore,"&field2=%d",gunField2Value);
//		printf(" field 2 values is %s\n\r",guchTempFieldStore);
		sprintf(guchPostData1,"%s%s",guchPostData1,guchTempFieldStore);
//		printf("final strng is %s\n\r",guchPostData1);
		
	
	}
	if(gunField3Value!=-1)
	{
		guchTempFieldStore[0]='/0';
		sprintf(guchTempFieldStore,"&field3=%d",gunField3Value);
//		printf(" field 3 values is %s\n\r",guchTempFieldStore);
		sprintf(guchPostData1,"%s%s",guchPostData1,guchTempFieldStore);
//		printf("final strng is %s\n\r",guchPostData1);
	
	//	strcat(guchPostData,guchTempFieldStore);
		
	
	}
	

	if(gunField4Value!=-1)
	{
		guchTempFieldStore[0]='/0';
		sprintf(guchTempFieldStore,"&field4=%d",gunField4Value);
//		printf(" field 4 values is %s\n\r",guchTempFieldStore);
		sprintf(guchPostData1,"%s%s",guchPostData1,guchTempFieldStore);
//		printf("final strng is %s\n\r",guchPostData1);
	
}




}



void fnFieldValuesFromChannel(void)// changed on 07-10-2017 By Ajith Kirlaya
{
	fnConnectToAp();
	fnCollectDataFromWebsite();
	fnExtractDataField();
}



void fnESPBluetoothTerminalCheckMode(void)
{

	TRISCbits.RC6=1;
	TRISCbits.RC7=1;
	TRISDbits.RD6=1;
	TRISDbits.RD7=1;
}
