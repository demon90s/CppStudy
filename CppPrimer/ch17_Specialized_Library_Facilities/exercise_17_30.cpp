// 练习17.30：再次修改你的程序，此次再增加两个参数，表示函数允许返回的最小值和
// 最大值。

#include <iostream>
#include <random>

using namespace std;

unsigned int Random(int seed, std::pair<int, int> range)
{
	static uniform_int_distribution<unsigned> u(range.first, range.second);
	static default_random_engine e(seed);

	return u(e);
}

int main()
{
	cout << Random(1, {1, 10}) << endl;
	cout << Random(1, {1, 10}) << endl;
	cout << Random(1, {1, 10}) << endl;

	return 0;
}
