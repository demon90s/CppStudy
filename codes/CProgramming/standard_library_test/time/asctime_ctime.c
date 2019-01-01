/*
    char* asctime(const struct tm *timeptr);
    使用分解时间，构造一个字符串并返回，它类似 Tue Aug 30 17:17:12 1994\n

    char* ctime(const time_t *timer);
    功能和 asctime 一样，只不过参数不一样
*/

#include <stdio.h>
#include <time.h>

void test_asctime()
{
    time_t now = time(NULL);
    printf("%s", asctime(localtime(&now)));
}

void test_ctime()
{
    time_t now = time(NULL);
    printf("%s", ctime(&now));
}

int main(int argc, char const *argv[])
{
    test_asctime();
    test_ctime();

    return 0;
}
