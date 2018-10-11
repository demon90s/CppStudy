/*
 * 假设下列数组含有一周24小时的温度读数，数组的每一行是某一天的读数：
 *
 * int temperatures[7][24];
 *
 * 编写语句，使用 search 函数在整个 temperatures 数组中寻找值32。
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
	int temperatures[7][24];

	memset(temperatures, 0, sizeof(temperatures));

	if (search(&temperatures[0][0], 7 * 24, 32)) {
		printf("Find\n");
	}
	else {
		printf("Not Find\n");
	}

	temperatures[1][22] = 32;

	if (search(&temperatures[0][0], 7 * 24, 32)) {
		printf("Find\n");
	}

	return 0;
}
