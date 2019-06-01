/*
    设a是有100个整数的数组。请编写函数 qsort 的调用，此调用只对数组a中后50个元素进行排序。
    （不需要编写比较函数）。
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM 100

int compare_int(const void* p1, const void* p2)
{
    return *(int*)p1 - *(int*)p2;
}

int main(int argc, char const *argv[])
{
    int a[NUM];
    int i;

    srand(time(NULL));

    for (int i = 0; i < NUM; i++) {
        a[i] = rand() % 100;
    }

    qsort(a + NUM / 2, NUM / 2, sizeof(int), compare_int);

    printf("prev 50 number:");
    for (i = 0; i < NUM / 2; i++) {
        printf(" %d", a[i]);
    }
    printf("\n");

    printf("last 50 number:");
    for (i = NUM / 2; i < NUM; i++) {
        printf(" %d", a[i]);
    }
    printf("\n");

    return 0;
}
