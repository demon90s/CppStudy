/*
 * 练习5.3：使用逗号运算符（参见4.10节，第140页）重写1.4.1节（第10页）的while循环，使它不再需要块，观察改写之后的代码的可读性提高了还是降低了。
 */

#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main()
{
	int sum = 0, i = 50;

	while (i <= 100) 
		sum += i, ++i;

	std::cout << "Sum of 50 to 100 inclusive is " << sum << std::endl;

	return 0;
}
