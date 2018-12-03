/*
    #include <stdlib.h>
    double strtod(const char *str, char **str_end);
    转译 str 为浮点值。
    函数设置 str_end 所指向的指针指向最后被转译字符的后一字符，若 str_end 为 NULL ，则忽略掉它。

    long strtol(const char *str, char **str_end, int base);
    unsigned long strtoul(const char *str, char **str_end, int base);
    转译 str 为 整数 。
    base 的合法集是2-36，即进制，如果 base 为0，则自动检测， str 前缀为0表示八进制，为0x表示十六进制，否则为十进制。

    如果转换产生的值超过了范围，那么会把 ERANGE 存储在 errno 中，并返回最大值。若无法转换，返回0 。
*/

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    printf("%f\n", strtod("3.14", NULL));
    printf("%ld\n", strtol("1000", NULL, 2));   // 1000 -> 8
    printf("%lu\n", strtoul("0xFF", NULL, 0));

    return 0;
}
