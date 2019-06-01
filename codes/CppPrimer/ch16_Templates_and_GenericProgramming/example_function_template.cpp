// example: 函数模板（p578）

#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

template<typename T>
int compare(const T &v1, const T &v2)
{
	if (v1 < v2) return -1;
	if (v2 < v1) return 1;
	return 0;
}

// 非类型模板参数
template<unsigned N>
int compare(const char (&p1)[N], const char (&p2)[N])
{
	return strcmp(p1, p2);
}

// 默认模板实参（p594）
template<typename T, typename F = std::less<T>>
int compare2(const T &v1, const T &v2, F f = F()) // 重载会造成二义性调用
{
	if (f(v1, v2)) return -1;
	if (f(v2, v1)) return 1;

	return 0;
}

// 模板特例化（p625）
template <>
int compare(const char* const &p1, const char* const &p2)
{
	int ret = strcmp(p1, p2);
	if (ret < 0) return -1;
	if (ret == 0) return 0;
	
	return 1;
}

int main()
{
	cout << compare(1, 0) << endl; // T为int

	vector<int> vec1{1, 2, 3}, vec2{4, 5, 6};
	cout << compare(vec1, vec2) << endl; // T为vector<int>

	cout << compare("aaa", "aaa") << endl;

	cout << compare2(5, 6) << endl;

	// 练习16.39，使用显式模板实参，注意这里用的是compare2
	cout << compare2<string>("hello", "z") << endl;

	{
		const char* p1 = "hello";
		const char* p2 = "z";
		cout << compare(p1, p2) << endl;
	}


	return 0;
}
