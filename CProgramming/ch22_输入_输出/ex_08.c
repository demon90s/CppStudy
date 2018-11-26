/*
    在前面几章中，当希望跳过空白字符而读取非空白字符时，已经使用过 scanf 函数的 " %c" 格式串。而一些程序员用"%1s"来代替。这两种方法等效吗？如果不等效，区别是什么？
*/

/*
    经过测试，是等价的。
*/

#include <stdio.h>

int main()
{
    char c;

    //scanf(" %c", &c);
    scanf("%1s", &c);
    printf("%d\n", c);

    return 0;
}