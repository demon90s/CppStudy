/*
    编写一个函数，要求向此函数传递年（比如，1996）时，函数返回一个表示在年份开始处的 time_t 值。
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

time_t f()
{
    int year;
    printf("Enter year: ");
    scanf("%d", &year);

    struct tm t;
    t.tm_mday = 1;
    t.tm_mon = 0;
    t.tm_year = year - 1900;
    t.tm_sec = 0;
    t.tm_min = 0;
    t.tm_hour = 0;
    t.tm_isdst = -1;

    return mktime(&t);
}

int main(int argc, char const *argv[])
{
    time_t t = f();
    printf("%s\n", ctime(&t));

    return 0;
}
