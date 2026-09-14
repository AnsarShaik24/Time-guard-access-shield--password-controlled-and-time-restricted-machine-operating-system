//display rtc
#include "rtc.h"
#include "rtc_defines.h"
#include "lcd.h"
#include "lcd_defines.h"
#include "delay.h"

void display_RTC(void)
{
	s32 hour,min,sec,month,year,date,day;
GetRTCTimeInfo(&hour,&min,&sec);
DisplayRTCTime(hour,min,sec);
GetRTCDateInfo(&date,&month,&year);
DisplayRTCDate(date,month,year);
GetRTCDay(&day);
DisplayRTCDay(day);
}

