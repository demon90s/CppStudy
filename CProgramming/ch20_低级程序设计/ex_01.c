/*
    指出下面每一个代码段的输出。假定i, j和k都是 unsigned int 类型的变量。

    (a) i = 8; j = 9;
        printf("%d", i >> 1 + j >> 1);

    (b) i = 1;
        printf("%d", i & ~i);

    (c) i = 2; j = 1; k = 0;
        printf("%d", ~i & j ^ k);

    (d) i = 7; j = 8; k = 9;
        printf("%d", i ^ j & k);
*/

/*
    (a) 0
    (b) 0
    (c) 1
    (d) 15
*/

#include <stdio.h>

int main(int argc, char const *argv[])
{
    int i, j, k;

    i = 8; j = 9;
    printf("a: %d\n", i >> 1 + j >> 1);

    i = 1;
    printf("b: %d\n", i & ~i);

    i = 2; j = 1; k = 0;
    printf("c: %d\n", ~i & j ^ k);
    
    i = 7; j = 8; k = 9;
    printf("d: %d\n", i ^ j & k);

    return 0;
}
