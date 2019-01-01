/*
 * 编写一个程序用来确定一个数的位数：
 *
 * Enter a number: 374
 * The number 374 has 3 digits
 *
 * 假设输入的数最多不超过四位。提示：利用 if 语句进行数的判定。例如，如果数是在0到9之间的，那
 * 么位数为一。如果数是在10到99之间的，那么位数为二。
 */

#include <stdio.h>

int main()
{
	int n, digits;

	printf("Enter a number: ");
	scanf("%d", &n);

	if (n >= 0 && n <= 9) digits = 1;
	else if (n >= 10 && n <= 99) digits = 2;
	else if (n >= 100 && n <= 999) digits = 3;
	else digits = 4;

	printf("The number %d has %d digits\n", n, digits);

	return 0;
}
