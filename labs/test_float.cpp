// 测试float与int的类型转换

#include <iostream>

using namespace std;

int main()
{
	// int -> float
	int a = 10;
	float f = 0;
	f = a; // no warning
	cout << f << endl;

	// float -> int
	f = 5.5;
	int b = f; // no warning
	cout << b << endl;

	return 0;
}
