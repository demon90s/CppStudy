/*
 * 下列函数假设用来计算数组a中元素的和以及平均值，且数组a长度为n。 avg 和 sum 指向函数需要修改
 * 的变量。函数有几个错误，请找出这些错误并修改它们。
 *
 * void avg_sum(float a[], int n, float *avg, float *sum)
 * {
 * 	int i;
 * 	
 * 	sum = 0.0
 * 	for (i = 0; i < n; i++)
 * 		sum += a[i];
 *	avg = sum / n;
 * }
 */

#include <stdio.h>

void avg_sum(float a[], int n, float *avg, float *sum)
{
	int i;

	*sum = 0.0; /* 此处修改 sum -> *sum */
	for (i = 0; i < n; i++)
		*sum += a[i]; /* 此处修改 sum -> *sum */
	*avg = *sum / n; /* 此处修改 sum -> *sum avg -> *avg */
}

int main()
{
	float a[3] = {1.1, 2.2, 3.3};
	float avg, sum;

	avg_sum(a, 3, &avg, &sum);

	printf("avg: %f, sum: %f\n", avg, sum);

	return 0;
}
