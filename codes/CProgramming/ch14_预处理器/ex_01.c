/*
 * 编写宏来计算下面的值。
 * (a) x的立方。
 * (b) x除以4的余数。
 * (c) 如果x与y的乘积小于100值为1，否则值为0。
 */

#include <stdio.h>

#define EX_A(x) ((x)*(x)*(x))
#define EX_B(x) ((x) % 4)
#define EX_C(x, y) ((x) * (y) < 100 ? 1 : 0)

int main()
{
	int x = 10;
	int y = 20;

	printf("%d\n", EX_A(x));
	printf("%d\n", EX_B(x));
	printf("%d\n", EX_C(x, y));

	return 0;
}
