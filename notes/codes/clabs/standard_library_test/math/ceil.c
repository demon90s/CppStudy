/*
    ceil
    double ceil(double arg)
    返回不小于 arg 的最小整数（向上取整）

    若 arg 为0或者正负无穷，则不修改
*/

#include <math.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    printf("ceil(2.4): %.1f\n", ceil(2.4));                   // 3.0
    printf("ceil(-2.4): %.1f\n", ceil(-2.4));                 // -2.0
    printf("ceil(0): %.1f\n", ceil(0.0));                     // 0.0
    printf("ceil(INFINITY): %.1f\n", ceil(INFINITY));         // inf
    
    return 0;
}
