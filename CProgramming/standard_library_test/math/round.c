/*
    double round(double x);
    返回离x最近的整数。
*/

#include <stdio.h>
#include <math.h>

int main()
{
    printf("round(3.3): %f\n", round(3.3));
    printf("round(3.6): %f\n", round(3.6));

    printf("round(-3.3): %f\n", round(-3.3));
    printf("round(-3.6): %f\n", round(-3.6));

    return 0;
}