/* Displays the current date and time in three formats */

#include <stdio.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    time_t current = time(NULL);
    struct tm *ptr;
    char date_time[19];
    int hour;
    char am_or_pm;

    /* print date and time in default format */
    puts(ctime(&current));

    /* print date and time using strftime to format */
    strftime(date_time, sizeof(date_time), "%m-%d-%y %I:%M%p\n", localtime(&current));
    puts(date_time);

    /* print date and time using custom formatting */
    ptr = localtime(&current);
    hour = ptr->tm_hour;
    if (hour <= 11)
        am_or_pm = 'a';
    else {
        hour -= 12;
        am_or_pm = 'p';
    }
    if (hour == 0)
        hour = 12;
    printf("%.2d-%.2d-%.2d %2d:%.2d%c\n", ptr->tm_mon + 1,
            ptr->tm_mday, ptr->tm_year, hour, ptr->tm_min, am_or_pm);

    return 0;
}
