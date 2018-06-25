// 练习16.63：定义一个函数模板，统计一个给定值在一个vector中出现的次数。
// 测试你的函数，分别传递给它一个double的vector，一个int的vector以及一个
// string的vector。

#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

template <typename T>
int GetOccurTimes(const T &value, const std::vector<T> &vec)
{
	int times = 0;

	for (const auto &item : vec)
	{
		if (item == value)
		{
			++ times;
		}
	}

	return times;
}

// 特例化版本，练习16.64
template <>
int GetOccurTimes(const char* const &value, const std::vector<const char*> &vec)
{
	int times = 0;

	for (auto item : vec)
	{
		if (strcmp(value, item) == 0)
		{
			++ times;
		}
	}

	return times;
}

int main()
{
	vector<int> ivec{1, 2, 3, 3, 3, 5, 2};
	cout << GetOccurTimes(2, ivec) << endl;

	vector<double> dvec{1.1, 2.2, 3.3, 4.4, 2.2};
	cout << GetOccurTimes(2.2, dvec) << endl;

	vector<string> svec{"hello", "hi", "hi", "wow"};
	cout << GetOccurTimes(string("hi"), svec) << endl;

	vector<const char*> cstr_vec{"hello", "hi", "hi", "wow"};
	cout << GetOccurTimes(string("hi"), svec) << endl;

	return 0;
}
