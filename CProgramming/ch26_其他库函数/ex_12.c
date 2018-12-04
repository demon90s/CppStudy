/*
    编写一个程序，提示用户录入一个日期（月、日和年）和一个整数，然后显示n天后的日期。
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

time_t f()
{
    int month, day, year;
    int n;
    printf("Enter year: ");
    scanf("%d", &year);
    printf("Enter month: ");
    scanf("%d", &month);
    printf("Enter day: ");
    scanf("%d", &day);
    printf("Enter pass days: ");
    scanf("%d", &n);

    struct tm t;
    t.tm_mday = day + n;
    t.tm_mon = month - 1;
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
