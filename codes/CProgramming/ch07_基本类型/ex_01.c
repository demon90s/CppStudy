/*
 * 请给出下列整型常量的十进制数值。
 *
 * (a) 077
 * (b) 0x77
 * (c) 0XABC
 */

#include <stdio.h>

int main()
{
	printf("%d\n", 077); /* 63 */
	printf("%d\n", 0x77); /* 119 */
	printf("%d\n", 0XABC); /* 2748 */

	return 0;
}
