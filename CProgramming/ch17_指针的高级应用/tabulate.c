/*
    tabulate.c
    三角函数的列表值
*/

#include <stdio.h>
#include <math.h>

void tabulate(double (*f)(double), double first, double last, double incre);

#define PRINT_TAB(func)\
do {\
    printf("x\t" #func "(x)\n");\
    printf("--------------\n");\
    tabulate((func), first, last, incre);\
    printf("\n");\
} while (0)

int main(int argc, char const *argv[])
{
    double first, last, incre;

    printf("Enter first: ");
    scanf("%lf", &first);

    printf("Enter last: ");
    scanf("%lf", &last);

    printf("Enter incre: ");
    scanf("%lf", &incre);

    PRINT_TAB(cos);

    PRINT_TAB(sin);

    PRINT_TAB(tan);
    
    return 0;
}

void tabulate(double (*f)(double), double first, double last, double incre)
{
    double x;
    int i, intervals;

    intervals = ceil((last - first) / incre);

    for (i = 0; i <= intervals; i++) {
        x = first + incre * i;
        printf("%.2f\t%.3f\n", x, f(x));
    }
}