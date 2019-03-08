/*
    struct tm* localtime(const time_t *timer);

    把时间戳 timep 转换成分解时间返回。

    分解时间可以是：

    struct tm {
        int tm_sec;        // seconds
        int tm_min;        // minutes
        int tm_hour;       // hours
        int tm_mday;       // day of the month
        int tm_mon;        // month since 0, 因此实际月份要 +1
        int tm_year;       // year since 1990, 因此实际年要 +1990
        int tm_wday;       // day of the week [0,6] 星期天是0
        int tm_yday;       // day in the year
        int tm_isdst;      // daylight saving time
    };

    struct tm* gmtime(const time_t *timer);
    和 localtime 的功能一样，只不过返回的是格林威治时间（Greenwich Mean Time）
*/

#include <time.h>
#include <stdio.h>

void test_localtime()
{
    time_t now = time(NULL);
    struct tm *now_tm = localtime(&now);

    printf("local date: %d-%02d-%02d %02d:%02d:%02d weekday: %d\n", 
        now_tm->tm_year + 1900, now_tm->tm_mon + 1, now_tm->tm_mday,
        now_tm->tm_hour, now_tm->tm_min, now_tm->tm_sec,
        now_tm->tm_wday);
}

void test_gmtime()
{
    time_t now = time(NULL);
    struct tm *now_tm = gmtime(&now);

    printf("greenwich date: %d-%02d-%02d %02d:%02d:%02d\n", 
        now_tm->tm_year + 1900, now_tm->tm_mon + 1, now_tm->tm_mday,
        now_tm->tm_hour, now_tm->tm_min, now_tm->tm_sec);
}

int main(int argc, char const *argv[])
{
    test_localtime();
    test_gmtime();
    
    return 0;
}
