/*
	delay.c
*/
#include "clock_setting.h"


void Delay_1ms(void)
{
	#if (FREQUENCY == FREQUENCY_4MHZ)
		{
		 
			{
				unsigned int i,j;
				for(i=0;i<64;i++){}
			}
		}
	#elif (FREQUENCY == FREQUENCY_8MHZ)
			{
			 
				
					unsigned int i,j;
					for(i=0;i<131;i++){}
				
			}
	#elif (FREQUENCY == FREQUENCY_16MHZ)
			{
					unsigned int i,j;
					for(i=0;i<265;i++){}
				
			}
	#endif
}		

void Delay_in_ms(unsigned int uint_Count1)
{
				while(uint_Count1--)
				{
					Delay_1ms();
				}
}

void delay_in_half_seconds(unsigned char uchcount) 
{
	
			unsigned char i;
			for(i=0;i<uchcount;i++)
			{
			Delay_in_ms(100);
			Delay_in_ms(100);
			Delay_in_ms(100);
			Delay_in_ms(100);
			Delay_in_ms(100);
			}
}

void delay_in_seconds(unsigned char uch_Count)
{
	
		    unsigned int i;
		    for(i=0;i<uch_Count;i++)
		    {
		        delay_in_half_seconds(2);;
		    }
}
		

	

