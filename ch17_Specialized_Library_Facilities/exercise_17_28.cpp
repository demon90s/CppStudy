// 练习17.28：编写函数，每次调用生成并返回一个均匀分布的随机unsigned int。

#include <iostream>
#include <random>

using namespace std;

unsigned int Random()
{
	//static uniform_int_distribution<unsigned> u(0, 9);
	static default_random_engine e;

	return e();
}

int main()
{
	cout << Random() << endl;
	cout << Random() << endl;
	cout << Random() << endl;

	return 0;
}
