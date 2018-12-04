/*
    编写一条可以随机从7、11、15或19中取一个数分配给变量n的语句。
*/

#include <stdio.h>
#include <stdlib.h>

#define LOOP_TIMES 100000

int main(int argc, char const *argv[])
{
    int n;
    int hit[100] = {0};
    int loop = 0;

    /* 复合语句也是一条语句啦... */
    while (loop++ < LOOP_TIMES)
    {
        int list[] = {7, 11, 15, 19};  
        n = list[rand() % (sizeof(list) / sizeof(list[0]))];

        hit[n]++;
    }

    printf("num\ttimes\tpercent\n");
    printf("7\t%d\t%g\n", hit[7], hit[7] / (double)LOOP_TIMES);
    printf("11\t%d\t%g\n", hit[11], hit[11] / (double)LOOP_TIMES);
    printf("15\t%d\t%g\n", hit[15], hit[15] / (double)LOOP_TIMES);
    printf("19\t%d\t%g\n", hit[19], hit[19] / (double)LOOP_TIMES);
    
    return 0;
}
