// 练习10.21：编写一个lambda，捕获一个局部int变量，并递减变量值，直至它变为0。
// 一旦变量变为0，再调用lambda应该不再递减变量。lambda应该返回一个bool值，指
// 出捕获的变量是否为0。

#include <iostream>

using namespace std;

int main()
{
	int n = 5;
	auto func = [&n]() -> bool { if (n > 0) --n; return 0 == n; };

	while (!func())
	{
		cout << "func called" << endl;
	}

	return 0;
}
