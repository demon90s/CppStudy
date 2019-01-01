// 练习17.29：修改上一题中编写的函数，允许用户提供一个种子作为可选参数。

#include <iostream>
#include <random>

using namespace std;

unsigned int Random(int seed)
{
	//static uniform_int_distribution<unsigned> u(0, 9);
	static default_random_engine e;
	e.seed(seed);

	return e();
}

int main()
{
	cout << Random(1) << endl;
	cout << Random(2) << endl;
	cout << Random(3) << endl;

	return 0;
}
