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

int main()
{
	cout << compare(1, 0) << endl; // T为int

	vector<int> vec1{1, 2, 3}, vec2{4, 5, 6};
	cout << compare(vec1, vec2) << endl; // T为vector<int>

	cout << compare("aaa", "aaa") << endl;

	return 0;
}
