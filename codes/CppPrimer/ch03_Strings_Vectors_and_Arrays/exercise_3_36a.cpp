/*
 * 练习3.36：编写一段程序，比较两个数组是否相等。再写一段程序，比较两个vector对象是否相等。
 */

#include <iostream>

using std::begin;
using std::end;
using std::cout;
using std::endl;

int main()
{
	int arr1[] = {1, 2, 3};
	int arr2[] = {1, 2, 3};

	auto len1 = end(arr1) - begin(arr1);
	auto len2 = end(arr2) - begin(arr2);

	bool is_equal = true;
	if (len1 != len2)
		is_equal = false;
	else
	{
		for (int i = 0; i < len1; ++i)
			if (arr1[i] != arr2[i]) {
				is_equal = false;
				break;
			}
	}

	if (is_equal)
		cout << "Is equal" << endl;
	else
		cout << "Is not equal" << endl;

	return 0;
}
