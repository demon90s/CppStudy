/*
 * 练习4.21：编写一段程序，使用条件运算符从vector<int>中找到哪些元素的值是奇数，然后将这些奇数值翻倍。
 */

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::cin;
using std::vector;

int main()
{
	vector<int> ivec = {1, 3, 4, 6, 7};

	for (auto &i : ivec)
		(i % 2 != 0) ? i *= 2 : i;	// 这样写没问题，一定先对i % 2求值

	for (const auto i : ivec)
		cout << i << " ";
	cout << endl;

	return 0;
}
