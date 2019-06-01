/*
    编写 printf 函数调用，要求如果变量 widget （类型为 int 型）的值为1，则显示 1 widget ；如果值为n，则显示出 n
    widgets 。不允许使用 if 语句或任何其他任何语句；答案必须是一个单独的一个 printf 调用。
*/

#include <stdio.h>

int main(int argc, char const *argv[])
{
    int widget = 1;

    printf("%d widget%s\n", widget, widget > 1 ? "s" : "");

    return 0;
}
