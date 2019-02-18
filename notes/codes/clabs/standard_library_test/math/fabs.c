/*
    fabs(arg)
    计算浮点值 arg 的绝对值。
*/

#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    double pi = 3.14;
    printf("%f\n", fabs(pi));
    printf("%f\n", fabs(-pi));

    return 0;
}
