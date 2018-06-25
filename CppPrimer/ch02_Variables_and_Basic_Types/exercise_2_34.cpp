/*
 * 练习2.34：基于上一个练习中的变量和语句编写一段程序，输出赋值前后变量的内容，你刚才的推断正确吗？如果不对，请反复研读本节的示例直到你明白错在何处位置。
 */

#include <iostream>

int main()
{
	int i = 0, &r = i;
	const int ci = i, &cr = ci;

	auto a = r;	// a is int
	auto b = ci;	// b is int
	auto c = cr;	// c is int
	auto d = &i;	// d is int*
	auto e = &ci;	// e is const int*
	auto &g = ci;	// g is const int&

	a = 42;
	std::cout << "a: " << a << std::endl;

	b = 42;
	std::cout << "b: " << b << std::endl;

	c = 42;
	std::cout << "c: " << c << std::endl;

	//d = 42;
	//e = 42;
	//g = 42;

	return 0;
}
