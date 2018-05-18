// 练习16.41：编写一个新的sum版本，它的返回类型保证足够大，足以容纳加法的结果。

#include <iostream>
#include <initializer_list>
#include <string>

using namespace std;

template<typename T>
long long sum(initializer_list<T> il)
{
	long long sum = 0;
	for (auto i : il)
		sum += i;

	return sum;
}

int main()
{
	cout << sum({1, 2, 3, 4, 5}) << endl;
	cout << sum({(short)30000, (short)30000}) << endl;

	return 0;
}
