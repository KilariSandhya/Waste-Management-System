
/*
    filename	:serial_codes.h
	description	:transmit and receive data by serial port
	author		:apsis_team
	date		:18.10.2011
*/

#ifndef __SERIAL_CODES_H__
#define __SERIAL_CODES_H__

#define UART1 0
#define UART2 1
#define TIMED_OUT 256 // Any Value more than 0xFF

unsigned char uchfnReceive_Serial(unsigned char UART_NO);
void fn_Initialize_Serial(unsigned char uchSelectUART);
void fnUARTPutStringDelayed(unsigned char* string,unsigned char uchSelectUART) ;
#endif


/// AT 9600 BaudRate

#define SPBRGH_1MHz_9600	0x05	// If FREQUENCY = FREQUENCY_1MHZ 5 in dec
#define SPBRGH_2MHz_9600	0x0C	// If FREQUENCY = FREQUENCY_2MHZ 12 in dec
#define SPBRGH_4MHz_9600	0x19	// If FREQUENCY = FREQUENCY_4MHZ 25 in dec
#define SPBRGH_8MHz_9600	0x33	// If FREQUENCY = FREQUENCY_8MHZ 51 in dec
#define SPBRGH_16MHz_9600	0x67	// If FREQUENCY = FREQUENCY_16MHZ 103 in dec

#define BAUDRATE_9600	SPBRGH_4MHz_9600












