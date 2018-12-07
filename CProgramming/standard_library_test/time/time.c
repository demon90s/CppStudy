/*
    time_t time(time_t *t);

    获取时间戳，如果 t 不是 NULL ，那么把它存储到 t 的空间，否则返回时间戳。

    time_t 是一种算术运算类型，标准没有告知是整数还是浮点数，但一般用 unsigned long 是可以存储的（也就是整数）。

    PS: 在 Linux 中，time_t 的类型是 long int 。
*/

#include <time.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    long old_timestamp = 0;
    while (1) {
        long timestamp = (long)time(NULL);
        if (old_timestamp != timestamp) {
            printf("%ld\n", timestamp);
            old_timestamp = timestamp;
        }
    }
   
    return 0;
}
