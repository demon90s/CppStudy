/*
 * 练习1.11：编写程序，提示用户输入两个整数，打印出这两个整数所指定的范围内的所有整数。
 */

#include <iostream>

int main()
{
	int lval = 0, rval = 0;

	std::cout << "Enter two integers:" << std::endl;
	std::cin >> lval >> rval;

	while (lval <= rval) {
		std::cout << lval << std::endl;
		lval++;
	}

	return 0;
}
