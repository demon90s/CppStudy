/*
    编写一个程序，提示用户录入两个日期，然后显示两个日期之间相差的天数。提示：请使用 mktime
    函数和 difftime 函数。
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void f()
{
    int month, day, year;
    int i;
    time_t time_list[2];

    for (i = 0; i < 2; i++) {
        printf("Enter year: ");
        scanf("%d", &year);
        printf("Enter month: ");
        scanf("%d", &month);
        printf("Enter day: ");
        scanf("%d", &day);

        struct tm t;
        t.tm_mday = day;
        t.tm_mon = month - 1;
        t.tm_year = year - 1900;
        t.tm_sec = 0;
        t.tm_min = 0;
        t.tm_hour = 0;
        t.tm_isdst = -1;

        time_list[i] = mktime(&t);
    }
    
    printf("diff days: %g\n", difftime(time_list[1], time_list[0]) / (24 * 3600));
}

int main(int argc, char const *argv[])
{
    f();
    return 0;
}
