/*
    预定义宏

    __LINE__ 行号，十进制常数
    __FILE__ 文件名
    __DATE__ 文件编译时的日期
    __TIME__ 文件编译时的时间

    __FUNCTIONS__ 函数名字, 但在g++下测试, 无法输出其作用域
    __PRETTY_FUNCTION__ 返回值 函数名(参数列表), 适用于g++

    关于平台的预定义宏:
    unix: __unix
    windows: _WIN32
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

void test_FUNCTIONS()
{
    printf("this function name is: %s\n", __FUNCTION__);
}

namespace detail {
void test_PRETTY_FUNCTION(int i, double d)
{
    printf("this function detail is: %s\n", __PRETTY_FUNCTION__);
}
}

int main()
{
    CHECK_ZERO(0);

    print_compile_info();

    test_FUNCTIONS();

    detail::test_PRETTY_FUNCTION(0, 0);

    return 0;
}