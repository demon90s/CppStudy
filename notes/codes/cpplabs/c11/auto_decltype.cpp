/*
    auto var = expr; 使用等号右边的表达式推导出变量的类型，并且会执行表达式

    decltype(expr) var; 使用其表达式的结果推导出其类型，而不会执行表达式

    两者的类型推导都是在编译期完成
*/

#include <cstdio>

int make_int()
{
    printf("make_int called\n");
    return 42;
}

void test_auto()
{
    auto i = make_int();        // i 是 int
    printf("i: %d\n", i);
}

void test_decltype()
{
    decltype(make_int()) i;    // i 是 int
    i = 42;
    printf("i: %d\n", i);
}

int main()
{
    //test_auto();
    test_decltype();

    return 0;
}