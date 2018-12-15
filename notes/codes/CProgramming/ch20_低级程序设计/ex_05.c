/*
    编写名字为 GET_RED, GET_GREEN, GET_BLUE 3个宏，并以一个给定的颜色值作为参数（见练习4）。
    宏会返回一个8位的值表示给定颜色中红、绿、或蓝。
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

enum color_type { RED, GREEN, BLUE };
unsigned char get_certain_color(long int v, enum color_type ct)
{
    unsigned char colors[3];
    get_color(v, colors);
    return colors[ct];
}

#define GET_RED(v) get_certain_color(v, RED)
#define GET_GREEN(v) get_certain_color(v, GREEN)
#define GET_BLUE(v) get_certain_color(v, BLUE)

int main(int argc, char const *argv[])
{
    long int v = MK_COLOR(244, 122, 60);
    printf("%ld\n", v);

    unsigned char colors[3];
    get_color(v, colors);
    printf("%u %u %u\n", GET_RED(v), GET_GREEN(v), GET_BLUE(v));

    return 0;
}