/*
 * 编写循环用来显示出（练习13中的）temperatures数组中行i存储的所有温度读数。利用指针来访
 * 问该行中的每个元素。
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
	int temperatures[7][24] = {
		{0},
		{22, 25, 26, 0},
		{0},
		{0},
		{0},
		{0},
		{0},
	};

	int *p;
	int i = 1;

	for (p = &temperatures[i][0]; p != &temperatures[i][24]; p++) {
		printf("%d ", *p);
	}
	printf("\n");

	return 0;
}
