/*
    filename	:main.h
	description	:
	author		:apsis_team
	date		:18.10.2011

*/

//#ifndef __MAINCODE
//#define __MAINCODE

#define UART1 0
#define UART2 1

void main(void);
void FnDeviceInitialisation(void);

void UART1_isr(void);
void timer0_isr(void);

                 
