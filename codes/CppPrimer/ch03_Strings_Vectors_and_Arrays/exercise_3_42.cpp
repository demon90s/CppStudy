/*
 * 练习3.42：编写一段程序，将含有整数元素的vector对象拷贝给一个整型数组。
 */

#include <iostream>
#include <vector>

using std::endl;
using std::cout;
using std::vector;

int main()
{
	vector<int> vec = {1, 2, 3, 4, 5};

	constexpr size_t LEN = 5;
	int a[LEN] = {0};

	size_t cnt = 0;
	for (auto i : vec) {
		a[cnt++] = i;
		if (cnt >= LEN)
			break;
	}

	for (size_t i = 0; i < LEN; ++i)
		cout << a[i] << " ";
	cout << endl;

	return 0;
}
