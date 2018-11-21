/*
    假定函数f的实现如下：

    unsigned int f(unsigned int i, int m, int n)
    {
        return (i >> (m+1-n) & ~(~0 << n));
    }

    (a) ~(~0 << n)的结果是什么？
    (b) 函数f的作用是什么？
*/

/*
    (a) 将1左移n位，然后对每一位取反
    (b) 将i右移一个值，这个值是 (m+1-n) 与 ~(~0 << n)) 的位与的结果
*/

#include <stdio.h>

unsigned int f(unsigned int i, int m, int n)
{
    return (i >> (m+1-n) & ~(~0 << n));
}

int main(int argc, char const *argv[])
{
    unsigned int i = 0x1111;

    printf("%hx\n", f(i, 4, 1));
    
    return 0;
}
