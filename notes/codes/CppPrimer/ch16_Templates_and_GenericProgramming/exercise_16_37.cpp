// 练习16.37：标准库max函数有两个参数，它返回实参中的较大者。此函数有一个模板
// 类型参数。你能在调用max时传递给它一个int和一个double吗？如果可以，如何做？
// 如果不可以，为什么？

#include <iostream>

using namespace std;

int main()
{
	int i = 10;
	double pi = 3.14;

	//cout << std::max(i, pi) << endl; // error: no matching function for call to ‘max(int, double)’
	cout << std::max<double>(i, pi) << endl; // OK

	return 0;
}
