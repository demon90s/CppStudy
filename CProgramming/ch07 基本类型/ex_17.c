/*
 * 假设程序包含下列声明：
 *
 * char c = '\1';
 * short int s = 2;
 * int i = -3;
 * long int m = 5;
 * float f = 6.5;
 * double d = 7.5;
 *
 * 请给出下列每个表达式的值和类型。
 *
 * (a) c * i
 * (b) s + m
 * (c) f / c
 * (d) d / s
 * (e) f - d
 * (f) (int)f
 */

#include <stdio.h>

int main()
{
	char c = '\1';
	short int s = 2;
	int i = -3;
	long int m = 5;
	float f = 6.5;
	double d = 7.5;

	printf("%d\n", c * i);	/* int, -3				*/
	printf("%ld\n", s + m);	/* long int, 7 			*/
	printf("%f\n", f / c);	/* float, 6.5			*/
	printf("%f\n", d / s);	/* double, 3.75			*/
	printf("%f\n", f - d);	/* double, -1.0			*/
	printf("%d\n", (int)f);	/* int, 6				*/

	return 0;
}
