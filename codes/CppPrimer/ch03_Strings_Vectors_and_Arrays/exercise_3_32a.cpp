/*
 * 练习3.32：将上一题刚刚创建的数据拷贝给另外一个数组。利用vector重写程序，实现类似的功能。
 */

#include <iostream>

using std::cout;
using std::endl;

int main()
{
	constexpr size_t LEN = 10;

	int arr[LEN] = {};
	for (size_t i = 0; i < LEN; ++i)
		arr[i] = i;

	// copy array
	int arr2[LEN] = {};
	for (size_t i = 0; i < LEN; ++i)
		arr2[i] = arr[i];

	// print copied array
	for (auto i : arr2)
		cout << i << " ";
	cout << endl;

	return 0;
}
