/*
    double sin(double arg);
    double cos(double arg);
    double tan(double arg);

    计算以弧度衡量的 arg 的正弦, 余弦, 正切
*/

#include <stdio.h>
#include <math.h>

#define PI 3.1415926            // 180 度

int main()
{
    double res;

    printf("sin(PI) = %.2f\n", sin(PI));
    printf("sin(PI/2) = %.2f\n", sin(PI/2));

    printf("cos(PI) = %.2f\n", cos(PI));
    printf("cos(PI/2) = %.2f\n", cos(PI/2));

    printf("tan(PI/4) = %.2f\n", tan(PI/4));

    return 0;
}