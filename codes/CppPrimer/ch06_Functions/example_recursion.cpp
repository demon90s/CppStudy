// example: 递归（p204）

#include <iostream>

using std::cout;
using std::endl;
using std::cin;

// 计算val的阶乘，即1 * 2 * 3 ... * val
int factorial(int val)
{
	if (val > 1)
		return factorial(val - 1) * val;
	return 1;
}

int main()
{
	cout << factorial(5) << endl;

	return 0;
}
