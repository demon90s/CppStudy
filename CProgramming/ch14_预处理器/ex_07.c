/*
 * (a) 编写宏 DISP(f, x) ，使其扩展后调用 printf 函数来显示函数f的参数为x时的值。例如：
 *
 * DISP(sqrt, 3.0);
 *
 * 应该扩展为：
 *
 * printf("sqrt(%g) = %g\n", 3.0, sqrt(3.0));
 *
 * (b) 编写宏 DISP2(f, x, y) ，类似 DISP 但应用于有两个参数的函数。
 */

#include <stdio.h>
#include <math.h>

#define DISP(f, x) (printf(#f "(%g) = %g\n", (x), (f)(x)))

#define DISP2(f, x, y) (printf(#f "(%g, %g) = %g\n", (x), (y), (f)(x, y)))

double sum(double a, double b)
{
	return a + b;
}

int main()
{
	DISP(sqrt, 3.0);
	DISP2(sum, 3.5, 4.3);

	return 0;
}
