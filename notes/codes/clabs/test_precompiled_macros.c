/*
    测试预定义宏

    __LINE__ 行号，十进制常数
    __FILE__ 文件名
    __DATE__ 文件编译时的日期
    __TIME__ 文件编译时的时间
*/

/*
    output example:
    
    *** Attempt to divide by zero on line 23 of file test_precompiled_macros.c ***
    Compiled on Dec 15 2018 at 12:51:24
*/

#include <stdio.h>

#define CHECK_ZERO(divisor)\
    if (divisor == 0)\
        printf("*** Attempt to divide by zero on line %d of file %s ***\n", __LINE__, __FILE__)

void print_compile_info()
{
    printf("Compiled on %s at %s\n", __DATE__, __TIME__);
}

int main()
{
    CHECK_ZERO(0);

    print_compile_info();

    return 0;
}