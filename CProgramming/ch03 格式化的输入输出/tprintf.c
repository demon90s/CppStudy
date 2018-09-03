/* Print int and float values in various formats */

#include <stdio.h>

int main()
{
    int i;
    float x;

    i = 40;
    x = 839.21f;

    printf("|%d|%5d|%-5d|%5.3d|\n", i, i, i, i);
    printf("|%10.3f|%10.3e|%10g|\n", x, x, x);

    return 0;
}
