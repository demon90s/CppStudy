/*
    编写一个可以按照下列每种格式显示当前日期和时间的程序。请使用 strftime 函数来完成全部或
    大部分格式化工作。

    (a) Tuesday, August 30, 1994    05:07p
    (b) Tue, 30 Aug 94  17:07
    (c) 08/30/94 5:07:12 PM
*/

#include <stdio.h>
#include <time.h>

void a()
{
    time_t now = time(NULL);
    struct tm *tmp_now = localtime(&now);

    char date[1024];
    int len = strftime(date, 1024, "%A, %B %d, %Y\t%I:%M", tmp_now);
    char a_or_p = 'a';
    if (tmp_now->tm_hour > 11)
        a_or_p = 'p';
    date[len++] = a_or_p;
    date[len] = '\0';
    printf("%s\n", date);
}

void b()
{
    time_t now = time(NULL);
    struct tm *tmp_now = localtime(&now);

    char date[1024];
    int len = strftime(date, 1024, "%a, %d %b %y\t%H:%M", tmp_now);
    printf("%s\n", date);
}

void c()
{
    time_t now = time(NULL);
    struct tm *tmp_now = localtime(&now);

    char date[1024];
    int len = strftime(date, 1024, "%m/%d/%y %I:%M:%S %p", tmp_now);
    printf("%s\n", date);
}

int main(int argc, char const *argv[])
{
    a();
    b();
    c();
    return 0;
}
