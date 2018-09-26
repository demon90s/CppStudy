/*
 * 编写函数，使得函数返回下列值。（假设a和n是形式参数，其中a是有 int 型值的数组，而n则是数组
 * 的长度。）
 *
 * (a) 数组a中的最大元素
 * (b) 数组a中所有元素的平均值
 * (c) 数组a中正数元素的数量
 */

#include <stdio.h>

#define ARRAY_SZ (int)(sizeof(a) / sizeof(a[0]))

int array_max_element(int array[], int count);
int array_average(int array[], int count);
int array_positive_count(int array[], int count);

int main()
{
	int a[] = {1, 42, -3, -10, 6, -8};

	printf("array max element: %d\n", array_max_element(a, ARRAY_SZ));
	printf("array average: %d\n", array_average(a, ARRAY_SZ));
	printf("array positive count: %d\n", array_positive_count(a, ARRAY_SZ));

	return 0;
}

int array_max_element(int array[], int count)
{
	int max_number = array[0];
	int i;

	for (i = 1; i < count; i++) {
		if (max_number < array[i]) max_number = array[i];
	}

	return max_number;
}

int array_average(int array[], int count)
{
	int sum = 0;
	int i;

	for (i = 0; i < count; i++) {
		sum += array[i];
	}

	return sum / count;
}

int array_positive_count(int array[], int count)
{
	int positive_cnt = 0;
	int i;

	for (i = 0; i < count; i++) {
		if (array[i] > 0) positive_cnt++;
	}

	return positive_cnt;
}
