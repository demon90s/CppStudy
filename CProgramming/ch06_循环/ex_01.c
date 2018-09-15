/*
 * 编写程序，要求找到用户输入的一串数中的最大数。程序需要提示用户一个一个输入数。当用户输入
 * 0或负数时，程序必须显示输入的最大非负数：
 *
 * Enter a number: 60
 * Enter a number: 100.62
 * Enter a number: 0
 *
 * The largest number entered was 100.62
 *
 * 注意，输入的数不要求一定是整数。
 */

#include <stdio.h>

int main()
{
	float n, largest;

	largest = 0;
	do {
		printf("Enter a number: ");
		scanf("%f", &n);

		if (largest < n) largest = n;
		
	} while (n > 0);

	printf("The largest number entered was %g\n", largest);

	return 0;
}
