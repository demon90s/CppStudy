/*
 * 练习6.4：编写一个与用户交互的函数，要求用户输入一个数字，计算生成该数字的阶乘。
 * 在main函数中调用该函数。
 */

#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int calc_fact_for_user()
{
	int n = 0;
	cout << "Enter a number: ";
	cin >> n;

	if (n <= 0 || n > 12) {	// 超过此范围的结果将是非法的，简单起见，终止程序
		std::cerr << "Check valid range: [1, 12]" << endl;
		exit(1);
	}

	int ret = 1;
	for (; n > 1; --n) {
		ret *= n;
	}
	return ret;
}

int main()
{
	int ret = calc_fact_for_user();
	cout << ret << endl;

	return 0;
}
