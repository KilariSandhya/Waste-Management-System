/*********************************************************************
*
*                   
*
*********************************************************************
* FileName:        Math.C
* Dependencies:    See INCLUDES section below
* Processor:       
* Compiler:        MCC18 
* Company:         Microchip Technology, Inc.
*
* Software License Agreement
*
* The software supplied herewith by Microchip Technology Incorporated
* (the “Company”) for its PICmicro® Microcontroller is intended and
* supplied to you, the Company’s customer, for use solely and
* exclusively on Microchip PICmicro Microcontroller products. The
* software is owned by the Company and/or its supplier, and is
* protected under applicable copyright laws. All rights are reserved.
* Any use in violation of the foregoing restrictions may subject the
* user to criminal sanctions under applicable laws, as well as to
* civil liability for the breach of the terms and conditions of this
* license.
*
* THIS SOFTWARE IS PROVIDED IN AN “AS IS” CONDITION. NO WARRANTIES,
* WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED
* TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
* PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. THE COMPANY SHALL NOT,
* IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL OR
* CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
*
*
* Author               Date        Comment
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Microchip		  02-May-06	
********************************************************************/
#include <p18f46K22.h>

void bin_2_bcd(unsigned int );
void Bin2BCD (unsigned char);    // Coverts Binary Value to BCD and ASCII for LCD
unsigned char TenK,Thou,Hund,Tens,Ones;
unsigned char tempbcd[5];

unsigned char Most_Sig_Byte,Middle_Sig_Byte,Least_Sig_Byte;
/**************************************************************************************
;
;16 bit Binay to 5 digit BCD
;
;
;
***************************************************************************************/


void bin_2_bcd(unsigned int counter)
{
   int i;
   for(i=0;i<5;i++)
      tempbcd[i]=0;
   while(counter!=0)
   {
      counter--;
      tempbcd[0]++;
      if(tempbcd[0]==0x0a)
      {
         tempbcd[0]=0;
         tempbcd[1]++;
         if(tempbcd[1]==0x0a)
         {
            tempbcd[1]=0;
            tempbcd[2]++;
            if(tempbcd[2]==0x0a)
            {
               tempbcd[2]=0;
               tempbcd[3]++;
               if(tempbcd[3]==0x0a)
               {
                  tempbcd[3]=0;
                  tempbcd[4]++;
               }
            }
         }
      }

   }
   Hund = tempbcd[2];
   Tens = tempbcd[1];
   Ones = tempbcd[0];

}

/*********************************************************************************************************************************************
   Description:
      - This function will convert 8 bit Binay to 3 digit BCD
      - This function uses repeated subtraction method
         1. Subtract Byte with 100 until byte is greater than 100, count number of iterations (Gives Most_Sig_Byte )
         2. Then subtract with 10 until byte is greater than 10, count number of interations (Gives Middle_Sig_Byte)
         3. Then the remainder is unit (Gives Least_Sig_Byte)
         4. Then convert all value to respective ASCII (by adding 0x30) to display on LCD
**********************************************************************************************************************************************/

void Bin2BCD (unsigned char temp)
{
   Least_Sig_Byte = temp;
   for (Most_Sig_Byte = 0 ; Least_Sig_Byte >= 100 ; Least_Sig_Byte>=100?(Least_Sig_Byte -= 100):Least_Sig_Byte, Most_Sig_Byte++ );
   for (Middle_Sig_Byte = 0 ; Least_Sig_Byte >= 10  ; Least_Sig_Byte>=10?(Least_Sig_Byte -= 10):Least_Sig_Byte,  Middle_Sig_Byte++);
   Most_Sig_Byte += 0x30;
   Middle_Sig_Byte += 0x30;
   Least_Sig_Byte += 0x30;
}
