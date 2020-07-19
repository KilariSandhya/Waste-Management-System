// ---------------------------------------------------------------------------
// *                        www.apsis-solutions.com
// *               Copyright (c) Apsis Solutions, Bangalore
// *--------------------------------------------------------------------------
// *    Project         : Generic
// *    Module          : Project Main
// *    Description     : Project Starts Here
// *					  	  
// *    Author          : Ajith Kirlaya
// *    Workfile        : Projectmain.c
// *    Revision        : 2.0
// *    Last changed on : Date: 2017-10-08
// *                     
// *    Last changed by : Vijay
// *
// *--------------------------------------------------------------------------

#include <p18f46k22.h>    
#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#include "ProjectMain.h"  
#include "serial_codes.h"
#include "ADC.H" 
#include "PinAllocation.h"
#include "LCD.h"
#include "delay.h"
#include "timers.h"
#include "wifimodule.h" 

unsigned char guchLCDLine1String[17],guchLCDLine2String[17];
unsigned char uchBuffDisplay[] = "APSIS SOLUTIONS\n\r";
#pragma udata udata3
unsigned char uchRecieve150Ch[150],i = 0;
unsigned int guchDataTowebsite;
unsigned char gunField1Value,gunField2Value,gunField3Value,gunField4Value, gunField5Value, gunField6Value;

//extern unsigned char guchField5Value;
unsigned int unInch,j;
unsigned char uchDistance[50]={0};
unsigned char uchTempDistance[50]={0};
unsigned long unTimerFinalValue, ulnDistInCmSensor1, ulnDistInCmSensor2 ;
unsigned int unCentimeter;
unsigned int unData;
unsigned int unData1;
unsigned int unData2;
unsigned int unData3;
unsigned int unData4;
unsigned int unData5;
void fnPulse(void);
//void fnlcddisplay();
void fnDistanceLessThanTen(void);
void fnDistanceGreaterThanTen(void);
void fnDistanceGreaterThanHundred(void);
void fnDistanceGreaterThanThousand(void);
//void fnlcddisplay(void);
void fnUltraSonicSensor1(void);
void fnUltraSonicSensor2(void);
void fnUltraSonicSensor3(void);
void fnCloudValues();
void ValueUpdate(void);
void Value1Update(void);
void fnRange(void);





void fnMain_Project()
{

	unsigned int  unADCvalue3=0;
 	unsigned int  unADCvalue4=0;

 	gunField1Value = -1;
 	gunField2Value = -1;
 	gunField3Value = -1;
 	gunField4Value = -1;
		
	ANSELD = 0X00;
	TRISD  = 0X00;
	TRISBbits.TRISB0 = 1;
	ANSELBbits.ANSB0 = 0;
	TRISBbits.TRISB1 = 0;

	ANSELBbits.ANSB1 = 0;	
	TRISCbits.TRISC2 = 1;
	ANSELCbits.ANSC2 = 0;
	TRISCbits.TRISC3 = 0;
	ANSELCbits.ANSC3 = 0;
	
	TRISAbits.TRISA2 = 1;
	ANSELAbits.ANSA2 = 0;
	TRISAbits.TRISA3 = 0;
	ANSELAbits.ANSA3 = 0;

 
	T0CON	= 0x00;
 printf("Welcome to Apsis Solutions \n\r ");

 	while(1)
 	{

	fnUltraSonicSensor1();
	ValueUpdate();
	delay_in_seconds(2);

 	}







}



// void fnSensorsReadings(void)
// {
// 	fnUltraSonicSensor1();
// 	//delay_in_seconds(1);
// 	fnUltraSonicSensor2();
// 	//delay_in_seconds(1);
// }


void ValueUpdate(void)
{
// 	if (ulnDistInCmSensor1 < ulnDistInCmSensor2)
//   	{
	//	printf("ulnDistInCmSensor1 is greater than ulnDistInCmSensor2\n\r");
		//fnRange();

		if(ulnDistInCmSensor1 >= 150)
		{
			//gunField1Value=1;
		//	printf("Garbage bin is not full_1\n\r");
			// strcpypgm2ram(guchLCDLine2String," BIN IS NOT FULL");
			// fn_lcd_select_line_and_location(LCD_LINE_2,LOCATION_0);
			// fn_Display_String_LCD(guchLCDLine2String);

			fnUltraSonicSensor1();
			strcpypgm2ram(guchLCDLine2String," BIN IS NOT FULL");
			fn_lcd_select_line_and_location(LCD_LINE_2,LOCATION_0);
			fn_Display_String_LCD(guchLCDLine2String);
		//fnDatauploadTothingspeakwebsite();	
		}

		else if((ulnDistInCmSensor1 >= 120) && (ulnDistInCmSensor1 < 150))
		{
    		//gunField1Value=2;
		//	printf("Garbage bin is not full_2\n\r");
			// strcpypgm2ram(guchLCDLine2String," BIN IS NOT FULL");
			// fn_lcd_select_line_and_location(LCD_LINE_2,LOCATION_0);
			// fn_Display_String_LCD(guchLCDLine2String);
			fnUltraSonicSensor1();
			strcpypgm2ram(guchLCDLine2String," BIN IS NOT FULL");
			fn_lcd_select_line_and_location(LCD_LINE_2,LOCATION_0);
			fn_Display_String_LCD(guchLCDLine2String);
			//fnDatauploadTothingspeakwebsite();	
		}
		else if((ulnDistInCmSensor1 >= 100) && (ulnDistInCmSensor1 < 120))
		{
			//gunField1Value=3;
		//	printf("Garbage bin is not full_3\n\r");
			// strcpypgm2ram(guchLCDLine2String," BIN IS NOT FULL");
			// fn_lcd_select_line_and_location(LCD_LINE_2,LOCATION_0);
			// fn_Display_String_LCD(guchLCDLine2String);
			fnUltraSonicSensor1();
			strcpypgm2ram(guchLCDLine2String," BIN IS NOT FULL");
			fn_lcd_select_line_and_location(LCD_LINE_2,LOCATION_0);
			fn_Display_String_LCD(guchLCDLine2String);
			//fnDatauploadTothingspeakwebsite();	
		}
		else if((ulnDistInCmSensor1 >= 80) && (ulnDistInCmSensor1 < 100))
		{
			//gunField1Value=4;
		//	printf("Garbage bin is half full_4\n\r");
			// strcpypgm2ram(guchLCDLine2String,"BIN IS HALF FULL");
			// fn_lcd_select_line_and_location(LCD_LINE_2,LOCATION_0);
			// fn_Display_String_LCD(guchLCDLine2String);
			fnUltraSonicSensor1();
			strcpypgm2ram(guchLCDLine2String,"BIN IS HALF FULL");
			fn_lcd_select_line_and_location(LCD_LINE_2,LOCATION_0);
			fn_Display_String_LCD(guchLCDLine2String);
			//fnDatauploadTothingspeakwebsite();	
		}
		else if((ulnDistInCmSensor1 >= 70) && (ulnDistInCmSensor1 < 80))
		{
			//gunField1Value=5;
		//	printf("Garbage bin is about to fill_5\n\r");
			// strcpypgm2ram(guchLCDLine2String,"  BIN IS FULL   ");
			// fn_lcd_select_line_and_location(LCD_LINE_2,LOCATION_0);
			// fn_Display_String_LCD(guchLCDLine2String);
			fnUltraSonicSensor1();
			strcpypgm2ram(guchLCDLine2String,"  BIN IS FULL   ");
			fn_lcd_select_line_and_location(LCD_LINE_2,LOCATION_0);
			fn_Display_String_LCD(guchLCDLine2String);
			//fnDatauploadTothingspeakwebsite();	
		}	
		else if(ulnDistInCmSensor1 <= 60)
		{
			printf("*\n\r");
			//gunField1Value=6;
		//	printf("Garbage Is Full Send The Truck_6\n\r");
			// strcpypgm2ram(guchLCDLine2String," SEND THE TRUCK ");
			// fn_lcd_select_line_and_location(LCD_LINE_2,LOCATION_0);
			// fn_Display_String_LCD(guchLCDLine2String);
			fnUltraSonicSensor1();
			strcpypgm2ram(guchLCDLine2String," SEND THE TRUCK ");
			fn_lcd_select_line_and_location(LCD_LINE_2,LOCATION_0);
			fn_Display_String_LCD(guchLCDLine2String);
			//fnDatauploadTothingspeakwebsite();	
		}
		else if(ulnDistInCmSensor1 <= 55)
		{
			//gunField1Value=7;
		//	printf("Garbage Is Full Send The Truck_6\n\r");
			// strcpypgm2ram(guchLCDLine2String," SEND THE TRUCK ");
			// fn_lcd_select_line_and_location(LCD_LINE_2,LOCATION_0);
			// fn_Display_String_LCD(guchLCDLine2String);
			fnUltraSonicSensor1();
			strcpypgm2ram(guchLCDLine2String," SEND THE TRUCK ");
			fn_lcd_select_line_and_location(LCD_LINE_2,LOCATION_0);
			fn_Display_String_LCD(guchLCDLine2String);
			//fnDatauploadTothingspeakwebsite();	
		}
	}		
  	


void fnUltraSonicSensor1()
{
	
	   	LATBbits.LATB1 = 1;
    	fnPulse();
		LATBbits.LATB1 = 0;
		
		TMR0L = TMR0H =0x00;
    	while(!PORTBbits.RB0);           
    	T0CONbits.TMR0ON = 1;         
        while(PORTBbits.RB0);            	
        T0CONbits.TMR0ON = 0;              
	  	printf("TL= %d    ",TMR0L);
		printf("TH= %d    ",TMR0H);
    	unTimerFinalValue= (TMR0L | (TMR0H*256)); 
    	  	
    	printf("unTimerFinalValue= %ld cm\n\r",unTimerFinalValue);
    	
    	unInch=(unTimerFinalValue*10)/148;
    	unInch=(unInch*2)+1;									// Converting to Inch
    //	printf("Distance in Inches for sensor1 = %d in\r\n",unInch);
    		
    	ulnDistInCmSensor1 =  (unTimerFinalValue*1000)/5882;			// Converting to Centimeter
    	ulnDistInCmSensor1 = ulnDistInCmSensor1*2;
	    		//printf("ulnDistInCmSensor1 = %ld cm\r\n",ulnDistInCmSensor1);
	    sprintf(uchTempDistance,"%ld\n\r",ulnDistInCmSensor1); 
//	    if(ulnDistInCmSensor1<50)
//{
//		printf('A');
//}	   
		
	   	// printf("uchTempDistance=%s\n\r",uchTempDistance);   //Distance before obtaining decimal pt
	    sprintf(guchLCDLine1String,"%ld\n\r",uchDistance);
	  
	  		
	    
	    fnDistanceLessThanTen();
	    fnDistanceGreaterThanTen();
	    fnDistanceGreaterThanHundred();
	    fnDistanceGreaterThanThousand();
	     //fnlcddisplay();
       
        delay_in_seconds(2);
}














////////pulse///////////////////

void fnPulse()
{
	INTCONbits.TMR0IF =0;
//	T0CON	= 0x00;
	TMR0L	= 0xFB;
	TMR0H	= 0xFF;
	T0CONbits.TMR0ON = 1;
//	printf("TOCON pulse = %0x     ",T0CON);
	while(INTCONbits.TMR0IF);
	T0CONbits.TMR0ON = 0;
	INTCONbits.TMR0IF =0;
	
}

	
void fnDistanceLessThanTen()
{
	if(ulnDistInCmSensor1<10)
	{
		for(j=0;j<1;j++)
		{
			uchDistance[j]=uchTempDistance[j];
		}
		uchDistance[j]='.';
		uchDistance[j+1]=uchTempDistance[j];
		j++;
		uchDistance[j+1]=uchTempDistance[j];
		j++;
		uchDistance[j+1]='\0';
		printf("%s\n\r",uchDistance);
		//return uchDistance;
	
    }   		
}	




//////Distance Greater Than 10////////

void fnDistanceGreaterThanTen()
{
	if(ulnDistInCmSensor1>=10 && ulnDistInCmSensor1<100)
	{
		for(j=0;j<1;j++)
		{
			uchDistance[j]=uchTempDistance[j];
		}
		uchDistance[j]='.';
		uchDistance[j+1]=uchTempDistance[j];
		j++;
		uchDistance[j+1]=uchTempDistance[j];
		j++;
		uchDistance[j+1]='\0';
		printf("Distance=%s\n\r",uchDistance);
		//return uchDistance;
	 }   		
}


	
//////Distance Greater Than 100////////

void fnDistanceGreaterThanHundred()
{
	if(ulnDistInCmSensor1>=100 && ulnDistInCmSensor1<1000)
	{
		for(j=0;j<2;j++)
		{
			uchDistance[j]=uchTempDistance[j];
		}
		uchDistance[j]='.';
		uchDistance[j+1]=uchTempDistance[j];
		j++;
		uchDistance[j+1]=uchTempDistance[j];
		j++;
		uchDistance[j+1]='\0';
		printf("Distance=%s\n\r",uchDistance);	
		//return uchDistance;
    }   		
}	

/////Distance Greater Than 1000////////

void fnDistanceGreaterThanThousand()
{
	if(ulnDistInCmSensor1>=1000)
	{
		for(j=0;j<3;j++)
		{
			uchDistance[j]=uchTempDistance[j];
		}
		uchDistance[j]='.';
		uchDistance[j+1]=uchTempDistance[j];
		j++;
		uchDistance[j+1]=uchTempDistance[j];
		j++;
		uchDistance[j+1]=uchTempDistance[j];
		j++;
		uchDistance[j+1]='\0';
		printf("Distance =%s\n\r",uchDistance);	
		//return uchDistance;
    }   		
}	

