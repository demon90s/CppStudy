/*
 * 第4章中的练习3要求编写程序可以显示两位数字的反向。设计一个程序可以实现一位、两位、三位或者多位数的反向。提示：使用 do 循环重复除以10，直到值达到0为止。
 */

#include <stdio.h>

int main()
{
	int n, tmp;

	printf("Enter a number: ");
	scanf("%d", &n);

	do {
		tmp = n - n / 10 * 10;
		n /= 10;

		printf("%d", tmp);

	} while (n);

	return 0;
}
