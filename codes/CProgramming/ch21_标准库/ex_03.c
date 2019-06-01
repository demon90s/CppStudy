/*
    当使用宏隐藏函数时，在头文件中哪一个必须放在前面：宏定义还是函数原型？验证你的结论。
*/

/*
    函数要放在前面
*/

#include <stdio.h>

void Test()
{
    printf("I am function\b");
}

#define Test() printf("I am macro\n")

int main(int argc, char const *argv[])
{
    Test();

    return 0;
}
