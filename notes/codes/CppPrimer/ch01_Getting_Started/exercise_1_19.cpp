/*
 * 练习1.19：修改你为1.4.1节练习1.10（第11页）所编写的程序（打印一个范围内的数），使其能够处理用户输入的第一个数比第二个数小的情况
 */

/*
 * 书本上似有误，应该是修改练习1.11
 */

#include <iostream>

int main()
{
	int lval = 0, rval = 0;

	std::cout << "Enter two integers:" << std::endl;
	std::cin >> lval >> rval;

	if (lval > rval) {
		int tmp = rval;
		rval = lval;
		lval = tmp;
	}

	while (lval <= rval) {
		std::cout << lval << std::endl;
		lval++;
	}

	return 0;
}
