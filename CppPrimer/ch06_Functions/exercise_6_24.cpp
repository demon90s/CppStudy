/*
 * 练习6.24：描述下面这个函数的行为。如果代码中存在问题，请指出并改正。
 *
 * void print(const int ia[10])
 * {
 *     for (size_t i = 0; i != 10; ++i)
 *         cout << ia[i] << endl;
 * }
 */

// ia的类型是const int*，如果指向的是数组首元素，那么此数组的长度不一定就是10。
// 改成下面那样。

#include <iostream>

using std::cout;
using std::endl;
using std::cin;

void print(const int (&ia)[10])
{
	for (size_t i = 0; i != 10; ++i)
	    cout << ia[i] << endl;
}

int main()
{
	int a[10] = {1, 2, 3, 4, 5};
	print(a);

	return 0;
}
