/*
 * 练习6.34：如果factorial函数的停止条件如下所示，将发生什么情况？
 * if (val != 0)
 */

/*
 * 如果val是个负数，那么函数将永远递归下去，直到栈溢出。提示：Segmentation fault (core dumped)
 * 如果是正数，那么会多调用一次，即调用factorial(1) --> factorial(0) * 1 --> 1 * 1，这是多余的。
 */

#include <iostream>

using std::cout;
using std::endl;
using std::cin;

// 计算val的阶乘，即1 * 2 * 3 ... * val
int factorial(int val)
{
	if (val != 0)
		return factorial(val - 1) * val;
	return 1;
}

int main()
{
	//cout << factorial(5) << endl;
	cout << factorial(-5) << endl;
	

	return 0;
}
