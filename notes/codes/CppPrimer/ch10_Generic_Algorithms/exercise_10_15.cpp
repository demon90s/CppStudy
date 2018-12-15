// 练习10.15：编写一个lambda，捕获它所在函数的int，并接受一个int参数。lambda应该
// 返回捕获的int和int参数的和。

#include <iostream>

using namespace std;

int main()
{
	int base = 10;

	auto func = [base](int a) -> int { return base + a; };

	cout << func(5) << endl;

	return 0;
}
