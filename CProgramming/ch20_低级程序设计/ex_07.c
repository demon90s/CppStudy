/*
    编写如下函数：
    unsigned int rotate_left(unsigned int i, int n);
    unsigned int rotate_right(unsigned int i, int n);

    函数 rotate_left(i, n)的值应是将i左移n位并将从左侧移入i右端而产生的结果。
    （例如，假定整型占16位， rotate_left(0x1234, 4) 将返回0x2341。）类似地，
    函数 rotate_right 也类似，只是将数字中的位向右循环移位。
*/

/*
    PS: unsigned int 在我的机子上是32位，不方便输入测试，故采用 unsigned short
*/

#include <stdio.h>

typedef unsigned short UInt16;

typedef enum { LEFT, RIGHT } CutDir;
static unsigned short cut(UInt16 i, CutDir dir, int n)
{
    UInt16 mask = 0;
    const int bits = sizeof(UInt16) * 8;
    int b;

    if (dir == LEFT) {
        for (b = bits - 1; b > bits - 1 - n; b--) {
            mask |= (1 << b);
        }
    }
    else if (dir == RIGHT) {
        for (b = 0; b < n; b++) {
            mask |= (1 << b);
        }
    }
    else {
        return i;
    }

    i &= mask;
    if (dir == LEFT) {
        i = i >> (bits - n);
    }
    else {
        i = i << (bits - n);
    }

    return i;
}

UInt16 rotate_left(UInt16 i, int n)
{
    UInt16 cutted;

    cutted = cut(i, LEFT, n);

    i = i << n;
    i |= cutted;

    return i;
}
UInt16 rotate_right(UInt16 i, int n)
{
    UInt16 cutted;

    cutted = cut(i, RIGHT, n);

    i = i >> n;
    i |= cutted;

    return i;
}

int main(int argc, char const *argv[])
{
    UInt16 res;
    UInt16 i = 0x1234;

    printf("%hx\n", i);
    
    res = rotate_left(i, 4);
    printf("%hx\n", res);

    res = rotate_right(i, 4);
    printf("%hx\n", res);

    return 0;
}
