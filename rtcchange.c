//rtcchange
#include "type.h"
	#include "pin_function_defines.h"
	#include "pin_connect_block.h"
	#include "lcd.h"
	#include "lcd_defines.h"
	#include "delay.h"
	#include<string.h>
	#include "kpm.h"
	#include "rtc.h"
	void time(void);
	void date(void);
	void day(u32 *);
	void hour(u32 *);
	void min(u32 *);
	void sec(u32 *);
	void dat(u32 *);
	void mon(u32 *);
	void year(u32 *);
	u32 getnumkey(void);
	void display_RTC(void);
	extern u32 h,mins,secs,d,m,y,dy;
	void rtcchange(void)
	{
		while(1){
		char c1;
		cmdLCD(0x01);
		strLCD("1.time  2.date");
		cmdLCD(GOTO_LINE2_POS0);
		strLCD("3.day  4.exit");
		delay_ms(200);
		c1=keyscan();
			delay_ms(30);
		if(c1=='4')
		{
			while(colscan()==0);
			delay_ms(200);
			cmdLCD(0x01);
			break;
		}
		switch(c1)
		{
			case '1':time();break;
			case '2':date();break;
			case '3':day(&dy);break;
		}
	}
	}
	void time(void)
	{
		while(1){
		char c2;
		cmdLCD(0x01);
		strLCD("1.hour  2.min");
		cmdLCD(GOTO_LINE2_POS0);
		strLCD("3.sec  4.exit");
		delay_ms(100);
		c2=keyscan();
			delay_ms(30);
		if(c2=='4')
		{
			while(colscan()==0);
			delay_ms(200);
			cmdLCD(0x01);
			SetRTCTimeInfo(h,mins,secs);
			delay_ms(300);
			display_RTC();
			delay_ms(400);
			break;
		}
		switch(c2)
		{
			case '1':hour(&h);break;
			case '2':min(&mins);break;
			case '3':sec(&secs);break;
		}
	}
	}
	void date(void)
	{
		while(1){
		char c3;
		cmdLCD(0x01);
		strLCD("1.date 2.month");
		cmdLCD(GOTO_LINE2_POS0);
		strLCD("3.year 4.exit");
		delay_ms(100);
		c3=keyscan();
			delay_ms(30);
		if(c3=='4')
		{
			while(colscan()==0);
			delay_ms(200);
			cmdLCD(0x01);
			SetRTCDateInfo(d,m,y);
			delay_ms(300);
			display_RTC();
			delay_ms(400);
			break;
		}
		switch(c3)
		{
			case '1':dat(&d);break;
			case '2':mon(&m);break;
			case '3':year(&y);break;
		}
	}
	}
	void day(u32 *dy)
	{
		u32 temp;
		cmdLCD(0x01);
		delay_ms(100);
		strLCD("ENTER DAY(0-6)");
		cmdLCD(GOTO_LINE2_POS0);
		delay_ms(100);
		temp=getnumkey();
		delay_ms(30);
		if(temp<7)
		{
			*dy=temp;
			cmdLCD(CLEAR_LCD);
			delay_ms(5);
			SetRTCDay(*dy);
			delay_ms(30);
			strLCD("DAY UPDATED");
			delay_ms(500);
			return;
		}
		cmdLCD(CLEAR_LCD);
		strLCD("Invalid DAY");
		delay_ms(500);
	}
	void hour(u32 *h)
	{
		
		u32 temp;
		cmdLCD(0x01);
		delay_ms(400);
		strLCD("ENTER HOUR 0-23");
		temp=getnumkey();
		delay_ms(30);
		if(temp<=23&&temp>=0)
		{
			*h=temp;
			cmdLCD(CLEAR_LCD);
			delay_ms(5);
			strLCD("HOUR UPDATED");
			delay_ms(500);
			return;
		}
		cmdLCD(CLEAR_LCD);
		strLCD("Invalid Hour");
		delay_ms(500);
	}
	void min(u32 *mins)
	{
		u32 temp;
		cmdLCD(0x01);
		delay_ms(400);
		strLCD("ENTER MINS 0-59");
		temp=getnumkey();
		delay_ms(30);
		if(temp<=59 && temp>=0)
		{
			*mins=temp;
			cmdLCD(CLEAR_LCD);
			delay_ms(5);
			strLCD("MINS UPDATED");
			delay_ms(500);
			return;
		}
		cmdLCD(CLEAR_LCD);
		strLCD("Invalid MINS");
		delay_ms(500);
	}
	void sec(u32 *secs)
	{
		u32 temp;
		cmdLCD(0x01);
		delay_ms(400);
		strLCD("ENTER SECS 0-59");
		temp=getnumkey();
		delay_ms(30);
		if(temp<=59 && temp>=0)
		{
			*secs=temp;
			cmdLCD(CLEAR_LCD);
			delay_ms(5);
			strLCD("SECS UPDATED");
			delay_ms(500);
			return;
		}
		cmdLCD(CLEAR_LCD);
		strLCD("Invalid SECS");
		delay_ms(500);
	}
	void dat(u32 *d)
{
    u32 temp;
    cmdLCD(0x01);
    delay_ms(400);
    strLCD("ENTER DATE 1-31");
    temp = getnumkey();
    delay_ms(30);
    if(temp >= 1 && temp <= 31)
    {
        *d = temp;
        cmdLCD(CLEAR_LCD);
        delay_ms(5);
        strLCD("DATE UPDATED");
        delay_ms(500);
        return;
    }

    cmdLCD(CLEAR_LCD);
    strLCD("Invalid DATE");
    delay_ms(500);
}
	void mon(u32 *m)
	{
		u32 temp;
		cmdLCD(0x01);
		delay_ms(400);
		strLCD("ENTER MNTH 1-12");
		temp=getnumkey();
		delay_ms(30);
		if(temp<=12 && temp>0)
		{
			*m=temp;
			cmdLCD(CLEAR_LCD);
			delay_ms(5);
			strLCD("MNTH UPDATED");
			delay_ms(500);
			return;
		}
		cmdLCD(CLEAR_LCD);
		strLCD("Invalid MNTH");
		delay_ms(500);
	}
	void year(u32 *y)
	{
		u32 temp;
		cmdLCD(0x01);
		delay_ms(400);
		strLCD("ENTER YEAR");
		temp=getnumkey();
		delay_ms(30);
		if(temp<=2030&&temp>1950)
		{
			*y=temp;
			cmdLCD(CLEAR_LCD);
			delay_ms(5);
			strLCD("YEAR UPDATED");
			delay_ms(500);
			return;
		}
		cmdLCD(CLEAR_LCD);
		strLCD("Invalid YEAR");
		delay_ms(500);
	}
	u32 getnumkey(void)
{
    char b[5]={0};
    char key;
    int i=0;

    cmdLCD(GOTO_LINE2_POS0);

    while(1)
    {
        key = keyscan();
        delay_ms(150);

        if(key >= '0' && key <= '9')
        {
            if(i < 4)
            {
                b[i] = key;
                cmdLCD(GOTO_LINE2_POS0 + i);
                charLCD(b[i]);
                i++;
            }
        }
        else if(key == '-')   // BACKSPACE
        {
            if(i > 0)
            {
                i--;
                b[i] = '\0';

                cmdLCD(GOTO_LINE2_POS0 + i);
                charLCD(' ');
                cmdLCD(GOTO_LINE2_POS0 + i);
            }
        }
        else if(key == '=')   // ENTER
        {
            if(i == 0) continue;

            if(i == 1)
                return b[0] - '0';

            if(i == 2)
                return (b[0]-'0')*10 + (b[1]-'0');

            if(i == 3)
                return (b[0]-'0')*100 +
                       (b[1]-'0')*10 +
                       (b[2]-'0');

            if(i == 4)
                return (b[0]-'0')*1000 +
                       (b[1]-'0')*100 +
                       (b[2]-'0')*10 +
                       (b[3]-'0');
        }
    }
}

	
		
		
