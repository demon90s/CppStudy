/*
 * 练习1.9：编写程序，使用while循环将50到100的整数相加
 */

#include <iostream>

int main()
{
	int sum = 0, i = 50;

	while (i <= 100) {
		sum += i;
		++i;
	}

	std::cout << "Sum of 50 to 100 inclusive is " << sum << std::endl;

	return 0;
}
