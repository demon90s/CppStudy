/*
    time_t mktime(struct tm *tm);

    把分解时间转换成时间戳返回。

    分解时间可以是：

    struct tm {
        int tm_sec;        // seconds
        int tm_min;        // minutes
        int tm_hour;       // hours
        int tm_mday;       // day of the month
        int tm_mon;        // month
        int tm_year;       // year
        int tm_wday;       // day of the week
        int tm_yday;       // day in the year
        int tm_isdst;      // daylight saving time
    };
*/

#include <stdio.h>
#include <time.h>

int main()
{
    /* 获取一年后的今天的时间戳 */
    time_t now = time(NULL);
    struct tm *tm = localtime(&now);
    tm->tm_year += 1;

    unsigned long next_year_now = (unsigned long)mktime(tm);
    printf("%lu\n", next_year_now);

    return 0;
}