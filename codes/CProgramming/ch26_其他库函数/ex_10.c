/*
    编写一个程序，用 clock 函数来测算 qsort 函数对有100个整数的数组进行排序所用的时间，其中此
    数组初始时是反序排列元素的。确保该程序还可以用于有1000个整数的数组或10000个整数的数组。
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LEN 1000

int compare(const void* p1, const void* p2)
{
    return *(int*)p1 - *(int*)p2;
}

int main(int argc, char const *argv[])
{
    int arr[LEN];
    int i;
    int num = LEN;
    for (i = 0; i < LEN; i++) {
        arr[i] = num--;
    }

    clock_t start_clock = clock();

    qsort(arr, LEN, sizeof(arr[0]), compare);

    clock_t end_clock = clock();

    printf("cost time: %g ms\n", (end_clock - start_clock) / (double)CLOCKS_PER_SEC);
    
    for (i = 0; i < LEN; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
