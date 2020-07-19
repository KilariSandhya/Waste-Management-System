/*
LCD.h
*/

#define HIGHER_NIBBLE 1
#define LOWER_NIBBLE  0


#define LCD_LINE_1	1
#define LCD_LINE_2	2

#define LOCATION_0	0
#define LOCATION_1	1
#define LOCATION_2	2
#define LOCATION_3	3
#define LOCATION_4	4
#define LOCATION_5	5
#define LOCATION_6	6
#define LOCATION_7	7
#define LOCATION_8	8
#define LOCATION_9	9
#define LOCATION_10	10
#define LOCATION_11	11
#define LOCATION_12	12
#define LOCATION_13	13
#define LOCATION_14	14
#define LOCATION_15	15


void fn_lcd_select_line_and_location(char ch_line_no, char ch_location_no); 
void fn_Clear_LCD(char ch_line_no);
void fn_Display_String_LCD(unsigned char *generic_ptr);
void write_port_lcd(unsigned char high_low_nibble); 
void lcd_write_command(void) ;
void lcd_write_data(void); 
void lcd_dummy_write(void); 
void lcd_function_set(void); 
void lcd_16_2_Initialisation(void); 
void lcd_select_line_one(void); 
void lcd_select_line_two(void); 
void fn_clear_display(void);


void fnSendDegreeSymbolToLCD(void);

