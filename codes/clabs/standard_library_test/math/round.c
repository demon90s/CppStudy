/*
    double round(double x);
    返回离x最近的整数（就近取整，四舍五入???）
*/

#include <stdio.h>
#include <math.h>

int main()
{
    printf("round(3.3): %.1f\n", round(3.3));               // 3.0
    printf("round(3.6): %.1f\n", round(3.6));               // 4.0

    printf("round(-3.3): %.1f\n", round(-3.3));             // -3.0
    printf("round(-3.6): %.1f\n", round(-3.6));             // -4.0

    return 0;
}