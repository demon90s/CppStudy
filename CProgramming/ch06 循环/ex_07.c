/*
 * 重新安排程序 square3.c 以便 for 循环对变量i进行初始化，对变量i进行判定，并且对变量i进行
 * 自增操作。不需要重写程序，特别是不要使用任何乘法。
 */

#include <stdio.h>

int main()
{
	int i, n, odd, square;

	printf("This program prints a table of squares.\n");
	printf("Enter number of entries in table: ");
	scanf("%d", &n);

	odd = 3;
	for (i = 1, square = 1; i <= n; odd += 2, ++i) {
		printf("%10d%10d\n", i, square);
		square += odd;
	}

	return 0;
}
