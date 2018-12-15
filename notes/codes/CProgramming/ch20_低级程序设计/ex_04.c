/*
    在计算机图形处理中，颜色通常是用3个数存储的，分别代表红、绿和蓝3种颜色。假定每个颜色需要
    8位来存储，而且我们希望将三种颜色一起存放在一个长整型数据中。请编写一个名为 MK_COLOR 的宏，
    包括3个参数（红、绿、蓝的强度）。 MK_COLOR 宏需要返回一个 long int 值，其中后3个字节分别
    包含红、绿和蓝，红作为最后一个字节。
*/

#include <stdio.h>

struct color_field {
    unsigned long:8;
    unsigned long b:8;
    unsigned long g:8;
    unsigned long r:8;
};

union color {
    struct color_field cf;
    long int v;
};

long int mk_color(int r, int g, int b)
{
    union color c;
    c.cf.r = r;
    c.cf.g = g;
    c.cf.b = b;
    return c.v;
}
#define MK_COLOR(r, g, b) mk_color(r, g, b)

void get_color(long int v, unsigned char colors[3])
{
    union color c;
    c.v = v;
    colors[0] = c.cf.r;
    colors[1] = c.cf.g;
    colors[2] = c.cf.b;
}

int main(int argc, char const *argv[])
{
    printf("%ld\n", MK_COLOR(244, 122, 60));

    unsigned char colors[3];
    get_color(MK_COLOR(244, 122, 60), colors);
    printf("%u %u %u\n", colors[0], colors[1], colors[2]);

    return 0;
}
