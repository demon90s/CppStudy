/*
 * 练习2.18：编写代码分别更改指针的值以及指针所指对象的值。
 */

#include <iostream>

int main()
{
	int a = 0;
	int *p = nullptr;

	p = &a;
	*p = 10;

	std::cout << *p << std::endl;

	return 0;
}
