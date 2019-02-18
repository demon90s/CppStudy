// 随机数生成器，参考：http://zh.cppreference.com/w/cpp/numeric/random/random_device

#include <iostream>
#include <random>

using namespace std;

int main()
{
	random_device rd;

	for (int i = 0; i < 10; ++i)
		cout << rd() << " ";
	cout << endl;

	return 0;
}
