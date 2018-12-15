/*
    register 存储类型
    声明变量具有 register 存储类型就要求编译器把变量存储在寄存器中，而不是内存中。
    但，这是一种要求而不是命令，编译器可以自由地把 register 型变量存储在内存中。

    register 存储类型只对声明在块内的变量有效， register 型变量和自动变量的存储期限、
    作用域和链接一样，但是它没有地址，不能对其做取地址的运算。

    register 存储类型最好用于频繁进行访问和更新的变量，例如，作为 for 语句的循环因子。

    但今天的编译器已经可以自动决定变量保留在寄存器中是否可以获得最大的好处。

    PS：一般不必使用 register
*/

#include <stdio.h>

int sum_array(int a[], int n)
{
    register int i;
    int sum = 0;
    for (i = 0; i < n; i++) {
        sum += a[i];
    }
    return sum;
}

int main(int argc, char const *argv[])
{
    int a[4] = {1, 2, 3, 4};

    printf("sum of a: %d\n", sum_array(a, 4));

    return 0;
}
