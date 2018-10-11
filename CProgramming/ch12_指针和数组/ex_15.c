/*
 * 编写循环用来显示（练习13中的）temperatures数组一星期中每一天的最高温度。循环体应该调用
 * find_largest 函数，且一次传递数组的一行。
 */

#include <stdio.h>

int find_largest(int a[], int count)
{
	int max;
	int i;

	max = a[0];
	for (i = 1; i < count; i++) {
		if (a[i] > max) max = a[i];
	}

	return max;
}

int main()
{
	int temperatures[7][24] = {
		{22, 21, 20},
		{20, 19, 17},
		{0},
		{0},
		{0},
		{0},
		{0},
	};

	int i;

	for (i = 0; i < 7; i++) {
		printf("max of day %d: %d\n", i+1, find_largest(&temperatures[i][0], 24));
	}
	
	return 0;
}
