/*
 * 下列程序的输出是什么？
 */

/*
 * x = 1, y = 2
 */

#include <stdio.h>

void swap(int a, int b);

int main()
{
	int x = 1, y = 2;

	swap(x, y);
	printf("x = %d, y = %d\n", x, y);

	return 0;
}

void swap(int a, int b)
{
	int temp;

	temp = a;
	a = b;
	b = temp;
}
