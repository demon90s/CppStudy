/*
    假设按照下列形式调用 scanf 函数：
    n = scanf("%d%f%d", &i, &x, &j);
    (其中，i, j, 和n都是 int 型变量。)假设输入流含有下面所示的字符，请指出
    这个调用后i, j, n和x的值。此外，请说明一下调用会消耗掉哪些字符。

    (a) 10`20`30-
    (b) 1.0`2.0`3.0-
    (c) 0.1`0.2`0.3-
    (d) .1`.2`.3-
*/

/*
    (a) i 10, j 30, x 20.0, n 3, 消耗 10`20`30
    (b) i 1, j 2, x 0.0, n 3, 消耗 1.0`2
    (c) i 0, j 0, x 0.1, n 3, 消耗 0.1`0
    (d) i, j, x 为定义, n 0, 无消耗
*/

#include <stdio.h>

int main()
{
    int i, j;
    float x;
    int n;

    n = scanf("%d%f%d", &i, &x, &j);
    printf("n: %d\n", n);
    printf("i: %d\n", i);
    printf("j: %d\n", j);
    printf("x: %f\n", x);

    return 0;
}