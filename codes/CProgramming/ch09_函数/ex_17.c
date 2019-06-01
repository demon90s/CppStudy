/*
 * 编写程序，要求用户录入一串整数（把这串整数存储在数组中），然后通过调用 selection_sort 函数
 * 来排序这些整数。在给定n个元素的数组后， selection_sort 函数必须做下列工作：
 * (a) 搜索数组找出数组中最大的元素，然后把它移到数组的最后
 * (b) 递归地调用函数本身来对前n-1个数组元素进行排序
 */

#include <stdio.h>

#define ARR_LEN 5

void selection_sort(int array[], int count)
{
	int i;
	int max_index, tmp;

	if (count <= 1) return;

	max_index = 0;
	for (i = 0; i < count; i++) {
		if (array[max_index] < array[i])
			max_index = i;
	}

	tmp = array[count - 1];
	array[count - 1] = array[max_index];
	array[max_index] = tmp;

	selection_sort(array, count - 1);
}

int main()
{
	int array[ARR_LEN];
	int i;
	printf("Enter numbers: ");
	for (i = 0; i < ARR_LEN; i++) {
		scanf("%d", &array[i]);
	}

	selection_sort(array, ARR_LEN);

	for (i = 0; i < ARR_LEN; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");

	return 0;
}
