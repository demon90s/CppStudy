/*
    要想从标准输入流中读取一个字符，下列调用方式哪种是无效的？

    (a) getch()
    (b) getchar()
    (c) getc(stdin)
    (d) fgetc(stdin)
*/

/*
    经过测试，都可以，但 getch() 不是标准库函数。 
*/

#include <stdio.h>

int main(int argc, char const *argv[])
{
    int c;

    //c = getch();
    //c = getchar();
    //c = getc(stdin);
    c = fgetc(stdin);
    printf("c: %c\n", c);

    return 0;
}
