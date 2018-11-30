/*
    编写一个程序，使用下面的公式求方程 ... 的根 ...
    程序需要提示a, b, c的值，然后显示出x的两个解。...
*/

#include <stdio.h>
#include <math.h>

int main()
{
    double a, b, c;
    double tmp;

    printf("Enter a b c: ");
    scanf("%lf%lf%lf", &a, &b, &c);

    tmp = pow(b, 2) - 4 * a * c;
    if (tmp < 0) {
        printf("imaginary number!\n");
        return 1;
    }

    printf("res1: %f\n", (-b + sqrt(tmp)) / (2 * a));
    printf("res2: %f\n", (-b - sqrt(tmp)) / (2 * a));

    return 0;
}