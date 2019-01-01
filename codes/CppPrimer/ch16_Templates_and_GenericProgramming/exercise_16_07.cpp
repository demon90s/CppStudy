// 编写一个constexpr模板，返回给定数组的大小。

#include <iostream>

using namespace std;

template<typename T, unsigned N>
constexpr unsigned arr_size(T (&arr)[N])
{
	return N;
}

int main()
{
	int a[10] = {0};

	cout << arr_size(a) << endl;

	return 0;
}
