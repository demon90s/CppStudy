/*
 * 编写程序显示 sizeof(int) 、 sizeof(short int) 、 sizeof(long int) 、 sizeof(float) 、
 * sizeof(double) 和 sizeof(long double) 的值。
 */

#include <stdio.h>

int main()
{
	printf("sizeof(int): %lu\n", sizeof(int));
	printf("sizeof(short): %lu\n", sizeof(short));
	printf("sizeof(long int): %lu\n", sizeof(long int));
	printf("sizeof(float): %lu\n", sizeof(float));
	printf("sizeof(double): %lu\n", sizeof(double));
	printf("sizeof(long double): %lu\n", sizeof(long double));

	return 0;
}
