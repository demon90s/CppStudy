/*
 * 练习3.35：编写一段程序，利用指针将数组中的元素置为0。
 */

#include <iostream>

using std::begin;
using std::end;
using std::cout;
using std::endl;

int main()
{
	int arr[5] = {1, 2, 3, 4, 5};

	auto b = begin(arr);
	auto e = end(arr);
	auto len = e - b;

	while (b < e) {
		*b = 0;
		++b;
	}

	for (int i = 0; i < len; ++i)
		cout << arr[i] << " ";
	cout << endl;

	return 0;
}
