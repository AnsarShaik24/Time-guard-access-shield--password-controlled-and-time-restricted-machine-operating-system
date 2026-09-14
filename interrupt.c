//eint0_virq..interrupt

	#include <lpc21xx.h>
	#include "type.h"
	#include "pin_function_defines.h"
	#include "pin_connect_block.h"
	#include "lcd.h"
	#include "lcd_defines.h"
	#include "delay.h"
	#include<string.h>
	#include "kpm.h"
	#define len 3
	#define EINT0_VIC_CHNO 14
	#define EINT0_PIN_0_1 3
	extern u32 eint0_flag;
	//char ch;
	void pwdchange(void);
	void rtcchange(void);
	void tlc(void);
void eint0_isr(void)__irq;
void interrupt_init(void)
{
		cfgportpinfunc(0,1,EINT0_PIN_0_1);
		VICIntEnable=1<<EINT0_VIC_CHNO;
		VICVectCntl0=(1<<5)|EINT0_VIC_CHNO;
		VICVectAddr0=(u32)eint0_isr;
		EXTMODE=1<<0;
}
void eint0_isr(void)__irq
{
	eint0_flag=1;
	/*cmdLCD(0x01);
	
	while(1)
	{
		cmdLCD(0x01);
		strLCD("1.PW 2.RTC");
		cmdLCD(GOTO_LINE2_POS0);
		strLCD("3.TLC 4.EXT");
		ch=keyscan();
		if(ch=='4')
		{
			while(colscan()==0);
			delay_ms(200);
			cmdLCD(0x01);
			break;
		}
		switch(ch)
		{
			case '1':pwdchange();break;
			case '2':rtcchange();break;
			case '3':tlc();break;
		}
	}
	delay_ms(500);
	*/
	EXTINT=1<<0;
	VICVectAddr=0;
}



	
	
		
