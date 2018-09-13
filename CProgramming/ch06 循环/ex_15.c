/*
 * 重写下面的循环，从而使其循环体为空。
 *
 * for (n = 0; m > 0; n++)
 * 	m /= 2;
 */

#include <stdio.h>

int main()
{
	int n, m;

	m = 8;
	for (n = 0; m > 0; m /= 2, n++);

	return 0;
}
