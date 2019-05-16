/*
    size_t strftime(char *s, size_t maxsize,
                    const char *format,
                    const struct tm *timeptr);

    把分解时间 timeptr 转换成字符串格式，以格式串 format 存储到数组 s 中，最多存储 maxsize 个字符。

    返回写入 s 的字符数量，不包括空字符。

    格式串中的转换说明可以有：

    %a          缩写的星期名
    %A          完整的星期名
    %b          缩写的月份名
    %B          完整的月份名
    %c          完全的日期和时间（比如， Aug 30 17:08:12 1994 ）
    %d          月内的天（01~31）
    %H          24小时制的小时（00~23）
    %I          12小时制的小时（01~12）
    %j          年内的天（001~366）
    %m          月份（1~12）
    %M          分钟（00~59）
    %p          AM/PM指示符
    %S          秒（00~61），允许两个额外的闰秒
    %U          星期数（00~53）把第一个星期日看作是第一个星期的开始
    %w          星期几（0~6）
    %W          星期数量（00~53）把第一个星期看作是第一个星期的开始
    %x          完全的日期（比如，Aug 30 1994 ）
    %X          完全的时间（比如，17:07:12）
    %y          不含世纪的年（00~99）
    %Y          含有世纪的年（比如，1994年）
    %Z          时区名或缩写（比如，EST）
    %%          %
*/

#include <stdio.h>
#include <time.h>

// CST HH:MM:SS
void test1()
{
    time_t now = time(NULL);
    struct tm *tmp_now = localtime(&now);

    char date[1024];
    strftime(date, 1024, "%Z %X", tmp_now);
    printf("%s\n", date);
}

// YY-MM-DD HH:MM:SS
void test2()
{
    time_t now = time(NULL);
    struct tm *tmp_now = localtime(&now);

    char date[1024];
    strftime(date, 1024, "%Y-%m-%d %H:%M:%S", tmp_now);
    printf("%s\n", date);
}

int main(int argc, char const *argv[])
{
    test1();

    test2();

    return 0;
}
