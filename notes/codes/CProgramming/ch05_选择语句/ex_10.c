/*
 * 修改4.1节的程序 upc.c ，使其可以检测 UPC 的有效性。在用户输入 UPC 后，程序将显示 VALID 或 NOT
 * VALID 。
 */

/* 
 * Valid entry: 0 13800 15173 5
 */

#include <stdio.h>

int main()
{
	int d, i1, i2, i3, i4, i5, j1, j2, j3, j4, j5;
	int first_sum, second_sum, total, check_digit, enter_check_digit;

	printf("Enter the first (single) digit: ");
	scanf("%1d", &d);

	printf("Enter first group of five digits: ");
	scanf("%1d%1d%1d%1d%1d", &i1, &i2, &i3, &i4, &i5);

	printf("Enter second group of five digits: ");
	scanf("%1d%1d%1d%1d%1d", &j1, &j2, &j3, &j4, &j5);

	printf("Enter check digit: ");
	scanf("%1d", &enter_check_digit);

	first_sum = d + i2 + i4 + j1 + j3 + j5;
	second_sum = i1 + i3 + i5 + j2 + j4;

	total = 3 * first_sum + second_sum;

	check_digit = 9 - ((total - 1) % 10);

	if (check_digit == enter_check_digit)
		printf("VALID");
	else
		printf("NOTVALID");

	return 0;
}
