//password.c
#include "lcd.h"
#include "lcd_defines.h"
#include "type.h"
#include "delay.h"
#include <string.h>
#include "kpm.h"
#define len 3
char default_pw[len+1]="000";
int password(void)
{
	u32 i=0;
	u8 key;
  char pw[len+1];
	cmdLCD(CLEAR_LCD);
	strLCD("enter password");
	delay_ms(100);
	cmdLCD(GOTO_LINE2_POS0);
	while(i<len)
	{
		key=keyscan();
		if(key=='-')
		{
			if(i>0)
			{
			i--;
			pw[i]='\0';
			cmdLCD(GOTO_LINE2_POS0+i);
			charLCD(' ');
			cmdLCD(GOTO_LINE2_POS0+i);
			}
		}
		else
		{
		pw[i]=key;
		charLCD(pw[i]);
		delay_ms(200);
		cmdLCD(GOTO_LINE2_POS0+i);
		charLCD('*');
		i++;
		}
		delay_ms(200);
	}
	pw[i]='\0';
	if(strcmp(default_pw,pw)==0)
	{
		cmdLCD(0x01);
		strLCD("granted");
		delay_ms(1000);
		return 1;
	}
	else
	{
		cmdLCD(0x01);
		strLCD("incorrect");
		delay_ms(1000);
		return 0;
	}
}


		
		
	
	
	
	
