#include <p18f46k22.h> 
#include "PinAllocation.h"
#include "serial_codes.h"
#include "delay.h"
#include "LCD.h"
#define NUMBER_OF_NOPS 6

unsigned char  uch_Lcd_Data;

void fnNop(unsigned int nNumber)
{
	int i;
	for(i=0;i<=nNumber;i++)
		Nop();
}

void fn_Display_String_LCD(unsigned char *generic_ptr)
{   
	while (*generic_ptr) 
	{
	    uch_Lcd_Data =*generic_ptr;
        lcd_write_data();
		generic_ptr++;
	}
}

void write_port_lcd(unsigned char  high_low_nibble) 
{
    if (high_low_nibble != 0)
    {
        if(uch_Lcd_Data & 0x80)
        {
            lcd_d7_msb = 1;
        }
        else
        {
            lcd_d7_msb = 0;
        }
        if(uch_Lcd_Data & 0x40)
        {
            lcd_d6 = 1;
        }
        else
        {
            lcd_d6 = 0;
        }  
        if(uch_Lcd_Data & 0x20)
        {
            lcd_d5 = 1;
        }
        else
        {
            lcd_d5 = 0;
        }
        if(uch_Lcd_Data & 0x10)
        {
            lcd_d4_lsb = 1;
        }
        else
        {
            lcd_d4_lsb = 0;
        }   
  
    }
    else
    {
        if(uch_Lcd_Data & 0x08)
        {
            lcd_d7_msb = 1;
        }
        else
        {
            lcd_d7_msb = 0;
            
        } 
        if(uch_Lcd_Data & 0x04)
        {
            lcd_d6 = 1;
        }
        else
        {
            lcd_d6 = 0;
        }   
        if(uch_Lcd_Data & 0x02)
        {
            lcd_d5 = 1;
        }
        else
        {
            lcd_d5 = 0;
        }
        if(uch_Lcd_Data & 0x01)
        {
            lcd_d4_lsb = 1;
        }
        else
        {
            lcd_d4_lsb = 0;
        }
//        lcd_d7_msb	=	uch_Lcd_Data & 0x08;   
//        lcd_d6		=	uch_Lcd_Data & 0x04;   
//        lcd_d5		=	uch_Lcd_Data & 0x02;   
//        lcd_d4_lsb	=	uch_Lcd_Data & 0x01;   
    }
}

void lcd_write_command(void) 
{
    RS_lcd = 0;
    Enable_lcd = 0;	
    write_port_lcd(HIGHER_NIBBLE);
    Nop();
    Nop();
    Nop();
    fnNop(NUMBER_OF_NOPS);
    Enable_lcd = 1;
    Delay_in_ms(1);
    Enable_lcd = 0;
    
    Nop();
    Nop();
    Nop();
    Nop();
    Nop();
    Nop();

    write_port_lcd(LOWER_NIBBLE);
    Nop();
    Nop();
    Nop();
    Nop();
    Nop();
    Nop();
    fnNop(NUMBER_OF_NOPS);
    Enable_lcd = 1;
    Delay_in_ms(1);
    Enable_lcd = 0;
    
}    

void lcd_write_data(void) 
{
    RS_lcd = 1;
    Enable_lcd = 0;	
    write_port_lcd(HIGHER_NIBBLE);
    fnNop(NUMBER_OF_NOPS);
    Nop();
    Nop();
    Nop();
    Nop();
    Nop();
    Nop();
    Enable_lcd = 1;
    Delay_in_ms(1);
    Enable_lcd = 0;

    Nop();
    Nop();
    Nop();
    Nop();
    Nop();
    Nop();fnNop(NUMBER_OF_NOPS);
	fnNop(NUMBER_OF_NOPS);
    write_port_lcd(LOWER_NIBBLE);
    Nop();
    Nop();
    Nop();;
    Enable_lcd = 1;
    Delay_in_ms(1);
    Enable_lcd = 0;
}


void lcd_dummy_write(void) 
{
    uch_Lcd_Data = 0x20;

    RS_lcd = 0;
    Enable_lcd = 0;	
    write_port_lcd(HIGHER_NIBBLE);
    Nop();
    Nop();
    Nop();
     Nop();
    Nop();
    Nop();
    Enable_lcd = 1;
    Delay_in_ms(1);
    Enable_lcd = 0;

}

void lcd_16_2_Initialisation(void) 
{

    ANSELEbits.ANSE0 = SET_DIGITAL;
    ANSELDbits.ANSD5 = SET_DIGITAL;
   
    ANSELDbits.ANSD0 = SET_DIGITAL;
    ANSELDbits.ANSD1 = SET_DIGITAL;
    ANSELDbits.ANSD2 = SET_DIGITAL;
    ANSELDbits.ANSD3 = SET_DIGITAL;

    lcd_d4_lsb_dir = SET_OUTPUT;
    lcd_d5_dir = SET_OUTPUT;
    lcd_d6_dir = SET_OUTPUT;
    lcd_d7_msb_dir = SET_OUTPUT;
   
    RS_lcd_dir = SET_OUTPUT;
    Enable_lcd_dir = SET_OUTPUT;
    delay_in_half_seconds(1);
    lcd_dummy_write();

    uch_Lcd_Data = 0x2C;  ; //function set first time interface 8 bit long
    lcd_write_command();

    uch_Lcd_Data = 0x0C;  ; //display 0ff
    lcd_write_command();
     
    uch_Lcd_Data = 0x06;  ; //entry mode
    lcd_write_command();
  
    uch_Lcd_Data = 0x01;  ; //clear display
    lcd_write_command();
    Delay_in_ms(10);
}

void fn_lcd_select_line_and_location(char ch_line_no, char ch_location_no) 
{
	if (ch_line_no== LCD_LINE_2)
		uch_Lcd_Data = 0xC0 + ch_location_no;
	else
    	uch_Lcd_Data = 0x80	+ ch_location_no;

    lcd_write_command();
    Delay_in_ms(10);
}

void fn_clear_display(void)
{	uch_Lcd_Data = 0x01;  ; //clear display
    lcd_write_command();
    Delay_in_ms(10);
}

void fnSendDegreeSymbolToLCD(void)
{
   uch_Lcd_Data = 248;          //Ascii Value for Degree Symbol
   lcd_write_data();

}
