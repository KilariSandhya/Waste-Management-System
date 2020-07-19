/*
    filename	:wifimodule.h
	description	:
	author		:apsis_team
	date		:2017-08-09
*/
#define	CR				0x0D // Carriage Return = Enter
#define LF				0x0A // Line Feed = New Line Symbol

#define BAD				0
#define GOOD			1

#define FAIL 			0
#define PASS 			1

#define OK				1
#define NOK				0

#define CHAR_LEN_WEBINFO 					154

#define CHAR_LEN_WEBINFO_GET                 109

void fnConnectToAp(void);
void fnConnectTowebsite(void);
void fnDatauploadTothingspeakwebsite(void);
void fnWifiResponse(void);

void fnSendAPCommand(void);
void fnIPStartCommand(void);
void fnSendTCP(void);
void fnSendURLWebsite(void);
void fnSendPortNumber(void);
void fnSendSSIDName(void);
void fnSendDoubleQuote(void);
void fnSendComma(void);
void fnSendSSIDPassword(void);
void fnSendCarriageReturn(void);
void fnSendNewLine(void);
void fnSendDataToWeb(unsigned int );
void fnTCPRequest(void);
void fnSendIPSENDCommand(void);
void fnHOSTWeb(void);
void fnKeepConAlive(void);


void fnGetRequestCommand(void);
void fnCipsend(void);
void fnExtractDataField(void);


void fnGetRequestCommand(void);
void fnSendAccept(void);

void fnSendChannelNumberAndFieldnumber(void);

void fnSendWebsiteURL(void);

void fnsendGET(void);
void fnFieldDataMerge(void);
void fnFieldValuesFromChannel(void); /// changed on 07-10-2017 By Ajith Kirlaya
void fnESPBluetoothTerminalCheckMode(void);
