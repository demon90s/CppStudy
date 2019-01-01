/*
 * 练习2.13：下面程序中j的值是多少？
 *
 * int i = 42;
 * int main()
 * {
 *     int i = 100;
 *     int j = i;
 * }
 */

/*
 * 100。
 */

#include <iostream>

int i = 42;
int main()
{
	int i = 100;
	int j = i;

	std::cout << j << std::endl;

	return 0;
}
