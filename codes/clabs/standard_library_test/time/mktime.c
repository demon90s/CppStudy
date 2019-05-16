/*
    time_t mktime(struct tm *tm);

    把分解时间转换成时间戳返回。

    分解时间可以是：

    struct tm {
        int tm_sec;        // seconds 0~61
        int tm_min;        // minutes 0~59
        int tm_hour;       // hours 0~23
        int tm_mday;       // day of the month 1~31
        int tm_mon;        // month 0~11
        int tm_year;       // year 0~?
        int tm_wday;       // day of the week 0~6
        int tm_yday;       // day in the year 0~365
        int tm_isdst;      // daylight saving time
    };

    mktime 会修正 tm 代表的日期。
*/

#include <stdio.h>
#include <time.h>

void test1()
{
    /* 获取一年后的今天的时间戳 */
    time_t now = time(NULL);
    struct tm *tm = localtime(&now);
    tm->tm_year += 1;

    unsigned long next_year_now = (unsigned long)mktime(tm);
    printf("%lu\n", next_year_now);
}

void test2()
{
    /* 获取某一年的开始时间, 要大于格林尼治时间1970年0点0分0秒 */
    int year;
    printf("Enter year: ");
    scanf("%d", &year);

    struct tm t;
    t.tm_mday = 1;
    t.tm_mon = 0;
    t.tm_year = year - 1900;    /* 可取值 >= 1970 */
    t.tm_sec = 0;
    t.tm_min = 0;
    t.tm_hour = 8/*0*/;         /* 我在中国, 比格林尼治时间早8小时 */
    t.tm_isdst = -1;

    unsigned long next_year = (unsigned long)mktime(&t);
    printf("%lu\n", next_year);
}

int main()
{
    //test1();
    test2();

    return 0;
}