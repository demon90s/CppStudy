/*
 * 练习2.36：关于下段代码，请指出每一个变量的类型以及程序结束时它们各自的值
 *
 * int a = 3, b = 4;
 * decltype(a) c = a;
 * decltype((b)) d = a;
 * ++c;
 * ++d;
 */

/*
 * a: int, 结束时值为4。
 * b: int, 结束时值为4。
 * c：int，结束时值为4。
 * d：int&，结束时值为4。
 */

#include <iostream>

int main()
{
	int a = 3, b = 4;
	decltype(a) c = a;
	decltype((b)) d = a;
	++c;
	++d;

	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "c: " << c << std::endl;
	std::cout << "d: " << d << std::endl;

	return 0;
}
