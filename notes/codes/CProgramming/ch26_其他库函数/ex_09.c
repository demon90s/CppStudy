/*
    编写两个函数来测试 atexit 函数。一个函数显示 That's all, ，另一个显示 folks! 。在程序终止时
    用 atexit 函数来注册这两个要调用的函数。请一定确保两个函数按照正确的顺序进行调用，只有这样
    才可以在屏幕上看到 That's all, folks! 。
*/

#include <stdlib.h>
#include <stdio.h>

void f1()
{
    printf("That's all, ");
}

void f2()
{
    printf("folks!\n");
}

int main(int argc, char const *argv[])
{
    atexit(f2);
    atexit(f1);
    
    return 0;
}
