// 练习10.14：编写一个lambda，接受两个int，返回它们的和。

#include <iostream>

using namespace std;

int main()
{
	int a = 5, b = 4;

	auto func = [](int a, int b) -> int { return a + b; };

	cout << func(a, b) << endl;

	return 0;
}
