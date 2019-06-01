/*
 * 编写下列函数：
 *
 * Bool search(int a[], int n, int key);
 *
 * a是要搜寻的数组，n是数组内元素的数量，而且key是搜索键。如果key与数组a的某个元素匹配了，
 * 那么 search 函数必须返回 TRUE ，否则返回 FALSE 。要求使用指针算术运算而不是下标来访问数组元素。
 */

#include <stdio.h>

#define TRUE 1
#define FALSE 0

typedef int Bool;

Bool search(int a[], int n, int key)
{
	int* p;

	for (p = a; p != a + n; p++) {
		if (*p == key) return TRUE;
	}
	return FALSE;
}

int main()
{
	int a[4] = {1, 2, 3, 4};

	printf("1 in array: %s\n", (search(a, 4, 1) ? "yes" : "no"));
	printf("5 in array: %s\n", (search(a, 4, 5) ? "yes" : "no"));

	return 0;
}
