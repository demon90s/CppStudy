/*
    floor(arg)
    返回不大于 arg 的最大整数值（向下取整）
*/

#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    printf("floor(+2.7) = %+.1f\n", floor(2.7));            // +2.0
    printf("floor(-2.7) = %+.1f\n", floor(-2.7));           // -3.0

    return 0;
}
