/*
 * 练习1.12：下面的for循环完成了什么功能？sum的终值是多少？
 *
 * int sum = 0;
 * for (int i = -100; i <= 100; ++i)
 *     sum += i;
 */

/*
 * 求-100到100之间所有整数的和，终值是0。
 */

#include <iostream>

int main()
{
	int sum = 0;
	for (int i = -100; i <= 100; ++i)
		sum += i;

	std::cout << sum << std::endl;

	return 0;
}
