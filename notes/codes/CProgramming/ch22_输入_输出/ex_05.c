/*
    printf 函数的转换说明 %.4d 和 %04d 有区别吗？如果有，请说明区别是什么。
*/

/*
    区别是，如果指定了精度，那么 04d 中的0就没有意义了。
*/

#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a = 42;

    printf("%.4d\n", a);
    printf("%04d\n", a);
    printf("%05.4d\n", a);
    
    return 0;
}
