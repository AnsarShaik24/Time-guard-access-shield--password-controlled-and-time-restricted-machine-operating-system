//timelimit
#include "rtc.h"
#include "lcd.h"

u32 timelimit(u32 sh, u32 sm, u32 eh, u32 em)
{
    s32 cur_h, cur_m, cur_s;
    u32 cur_total, start_total, end_total;

    // 1. Read RTC time
    GetRTCTimeInfo(&cur_h, &cur_m, &cur_s);

    // 2. Convert everything to minutes from midnight
    cur_total   = cur_h * 60 + cur_m;
    start_total = sh   * 60 + sm;
    end_total   = eh   * 60 + em;

    // 3. Check if time window crosses midnight
    if(start_total < end_total)
    {
        // Normal case (e.g., 10:00 ? 18:00)
        if(cur_total >= start_total && cur_total <= end_total)
            return 1;   // allowed
        else
            return 0;   // not allowed
    }
    else
    {
        // Midnight crossover (e.g., 22:00 ? 05:00)
        if(cur_total >= start_total || cur_total <= end_total)
            return 1;
        else
            return 0;
    }
}
