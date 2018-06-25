/*
 * 练习2.20：请叙述下面这段代码的作用。
 *
 * int i = 42;
 * int *p1 = &i;
 * *p1 = *p1 * *p1;
 */

/*
 * 通过指针p1，求得i的值的平方，将其赋值给i。
 */

#include <iostream>

int main()
{
	int i = 42;
	int *p1 = &i;
	*p1 = *p1 * *p1;

	std::cout << "42 * 42 = " << 42 * 42 << std::endl;
	std::cout << "i = " << i << std::endl;

	return 0;
}
