//main project
#include<lpc21xx.h>
#include "lcd.h"
#include "delay.h"
#include "lcd_defines.h"
#include "rtc.h"
#include "rtc_defines.h"
#include "initial.h"
#include "pin_connect_block.h"
#include "pin_function_defines.h"
#define led 4
u32 eint0_flag=0;
u32 h=12,mins=24,secs=20;
u32 d=4,m=12,y=2025;
u32 dy=4;
u32 s_h=9,s_m=0,e_h=17,e_m=0;
char ch;
int main() 
{ 
Init_LCD();
init_kpm();
RTC_Init();
interrupt_init();
SetRTCTimeInfo(h,mins,secs);
SetRTCDateInfo(d,m,y);
SetRTCDay(dy);
IODIR0|=1<<led;
while(1) 
{ 
	do{ 
		display_RTC(); 
	}while(colscan()&&eint0_flag==0);
	
	if(colscan()==0)
	{
			if(password())
			{
				if(timelimit(s_h,s_m,e_h,e_m))
				{
					cmdLCD(0x01);
					strLCD("device turn on");
					delay_ms(500);
					IOPIN0=((IOPIN0&~(1<<led))|(1<<led));
					delay_ms(1000);
					cmdLCD(0x01);
				}
				else
				{
					cmdLCD(0x01);
					strLCD("time limit");
					cmdLCD(GOTO_LINE2_POS0);
					strLCD("exceeds");
					delay_ms(500);
					cmdLCD(0x01);
				}
			}
			else
			{
				  cmdLCD(0x01);
					strLCD("retry");
					delay_ms(500);
					cmdLCD(0x01);
			}
		}
		
			if(eint0_flag)
    {
        eint0_flag = 0;       // clear flag

        while(1)
        {
            cmdLCD(0x01);
            strLCD("1.PW 2.RTC");
            cmdLCD(GOTO_LINE2_POS0);
            strLCD("3.TLC 4.EXT");

            ch = keyscan();

            if(ch == '4')   // exit menu
            {
                while(colscan()==0);
                delay_ms(200);
                cmdLCD(0x01);
                break;
            }

            switch(ch)
            {
                case '1': pwdchange(); break;
                case '2': rtcchange(); break;
                case '3': tlc(); break;
            }
        }
    }

	}
}


	
	

	
