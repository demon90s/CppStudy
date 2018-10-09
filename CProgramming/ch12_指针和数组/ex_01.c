/*
 * 假设下列声明是有效的：
 *
 * int a[] = {5, 15, 34, 54, 14, 2, 52, 72};
 * int *p = &a[1], *q = &a[5];
 *
 * (a) *(p + 3)的值是多少？
 *
 * (b) *(q - 3)的值是多少？
 *
 * (c) p-q的值是多少？
 *
 * (d) p<q的结果是真还是假？
 *
 * (e) *p<*q的结果是真还是假？
 */

#include <stdio.h>

int main()
{
	int a[] = {5, 15, 34, 54, 14, 2, 52, 72};
	int *p = &a[1], *q = &a[5];

	/* (a) 14 */
	printf("(a) %d\n", *(p + 3));

	/* (b) 34 */
	printf("(b) %d\n", *(q - 3));

	/* (c) -4 */
	printf("(c) %ld\n", p-q);

	/* (d) true */
	printf("(d) %s\n", p<q ? "true" : "false");

	/* (e) false */
	printf("(e) %s\n", *p<*q ? "true" : "false");

	return 0;
}
