/*
    扩展 round 函数，使它可以将x舍入成小数点后n位。例如，调用 round(3.14159, 3) 会返回3.142。
    提示：将x乘以10n，舍入成最近的整数，再除以10n。确保你的函数对正数x和负数x都可以正常工作。
*/

#include <stdio.h>
#include <math.h>

double my_round(double x, int n)
{
    x = x * pow(10, n);
    x = round(x);
    x = x / pow(10, n);
    return x;
}

int main()
{
    printf("round(3.14159, 3): %g\n", my_round(3.14159, 3));
    printf("round(-3.14159, 3): %g\n", my_round(-3.14159, 3));

    return 0;
}