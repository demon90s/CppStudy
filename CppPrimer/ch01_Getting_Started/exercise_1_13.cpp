/*
 * 练习1.13：使用for循环重做1.4.1节中的所有练习（第11页）
 */

#include <iostream>

// 练习1.9
/*
int main()
{
	int sum = 0;
	for (int val = 50; val <= 100; ++val)
		sum += val;

	std::cout << "Sum of 50 to 100 is " << sum << std::endl;

	return 0;
}
*/

// 练习1.10
/*
int main()
{
	for (int val = 10; val >= 0; --val)
		std::cout << val << std::endl;

	return 0;
}
*/

// 练习1.11
int main()
{
	int lval = 0, rval = 0;

	std::cout << "Enter two integers:" << std::endl;
	std::cin >> lval >> rval;

	for (int i = lval; i <= rval; ++i)
		std::cout << i << std::endl;

	return 0;
}
