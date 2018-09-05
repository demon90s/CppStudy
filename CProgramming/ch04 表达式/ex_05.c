/*
 * 重新编写练习4中的程序，使新程序不用数学式的分割数字方法就可以显示出三位的反向数。提示：
 * 复习程序upc.c。
 */

#include <stdio.h>

int main()
{
	int d1, d2, d3;

	printf("Enter a three-digit number: ");
	scanf("%1d%1d%1d", &d1, &d2, &d3);

	printf("The reversal is: %d%d%d\n", d3, d2, d1);

	return 0;
}
