/*
 * 练习2.4：编写程序检测你的估计是否正确，如果不正确，请仔细研读本节直到弄明白问题所在。
 */

#include <iostream>

int main()
{
	unsigned u = 10, u2 = 42;
	std::cout << u2 - u << std::endl;
	std::cout << u - u2 << std::endl;

	int i = 10, i2 = 42;
	std::cout << i2-i<<std::endl;
	std::cout << i - i2<<std::endl;
	std::cout << i - u<< std::endl;
	std::cout << u - i<<std::endl;

	return 0;
}
