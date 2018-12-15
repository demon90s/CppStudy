/*
 * 编写下列函数：
 *
 * void find_two_largest(int a[], int n, int *largest, int *second_largest);
 *
 * 当传递长度为n的数组a时，函数将在数组a中搜寻最大元素和第二大元素，把它们分别
 * 存储在 largest 和 second_largest 指向的变量中。
 */

#include <stdio.h>

void find_two_largest(int a[], int n, int *largest, int *second_largest);

int main()
{
	int a[5] = {4, 41, 42, 100, 9};
	int largest, second_largest;

	find_two_largest(a, 5, &largest, &second_largest);

	printf("largest: %d, second_largest: %d\n", largest, second_largest);

	return 0;
}

void find_two_largest(int a[], int n, int *largest, int *second_largest)
{
	int i, tmp;

	if (n <= 1) {
		*largest = *second_largest = a[0];
		return;
	}

	*largest = a[0];
	*second_largest = a[1];

	if (*largest < *second_largest) {
		tmp = *largest;
		*largest = *second_largest;
		*second_largest = tmp;
	}

	for (i = 2; i < n; i++) {
		if (*second_largest < a[i]) {
			if (*largest < a[i]) {
				*second_largest = *largest;
				*largest = a[i];
			}
			else if (a[i] != *largest) {
				*second_largest = a[i];
			}
		}
	}
}
