/*
 * 练习3.31：编写一段程序，定义一个含有10个int的数组，令每个元素的值就是其下标值。
 */

#include <iostream>

using std::cout;
using std::endl;

int main()
{
	int arr[10] = {};
	for (int i = 0; i < 10; ++i)
		arr[i] = i;

	for (auto i : arr)
		cout << i << " ";
	cout << endl;

	return 0;
}
