/*
    #include <assert.h>
    assert(expression)

    如果 expression 为假，那么 assert 显示一条信息到标准输出，然后调用 abort 终止程序。
    abort 可能会生成 core 文件

    由于 assert 引入了额外的检查，因此会增加程序的运行时间。

    如果声明了 NDEBUG 宏，将使得 assert 调用失效。其中一个方法是：
    #define NDEBUG
    #include <assert.h>
*/

#include <assert.h>
#include <stdio.h>

int main()
{
    double a, b;
    
    printf("Enter a b: ");
    scanf("%lf%lf", &a, &b);

    assert(b != 0);
    printf("%g/%g=%g\n", a, b, a/b);

    return 0;
}