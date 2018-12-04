/*
    编写一个可以随机返回 double 型值 d （0.0 <= d < 1.0）的函数。
*/

#include <stdio.h>
#include <stdlib.h>

double random_double()
{
    return (rand() % 100) / 100.0;
}

int main(int argc, char const *argv[])
{
    double num;
    int hit_range[5] = {0};
    int loop = 0;

    while (loop++ < 100000) {
        num = random_double();
        //printf("%g\n", num);

        if (num >= 0.0 && num < 0.2) {
            hit_range[0]++;
        }
        else if (num >= 0.2 && num < 0.4) {
            hit_range[1]++;
        }
        else if (num >= 0.4 && num < 0.6) {
            hit_range[2]++;
        }
        else if (num >= 0.6 && num < 0.8) {
            hit_range[3]++;
        }
        else {
            hit_range[4]++;
        }
    }

    printf("range\t\ttimes\n");
    printf("[0.0, 0.2)\t%d\n", hit_range[0]);
    printf("[0.2, 0.4)\t%d\n", hit_range[1]);
    printf("[0.4, 0.6)\t%d\n", hit_range[2]);
    printf("[0.6, 0.8)\t%d\n", hit_range[3]);
    printf("[0.8, 1.0)\t%d\n", hit_range[4]);

    return 0;
}
