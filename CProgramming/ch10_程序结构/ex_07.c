/*
 * 编写下列函数：
 *
 * int *find_middle(int a[], int n);
 *
 * 当传递长度为n的数组a时，函数将返回指向数组的中间元素的指针。（如果n是偶数，选择较大下标的
 * 中间元素。例如，如果n=4，中间元素是a[2]，不是a[1]。）
 */

#include <stdio.h>

int *find_middle(int a[], int n);

int main()
{
	int a[5] = {1, 4, 3, 10, 42};
	int b[4] = {42, 100, 10, 2};

	printf("middle of a: %d\n", *find_middle(a, 5));
	printf("middle of b: %d\n", *find_middle(b, 4));

	return 0;
}

int *find_middle(int a[], int n)
{
	return &a[n/2];
}
