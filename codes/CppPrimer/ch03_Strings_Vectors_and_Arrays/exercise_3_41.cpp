/*
 * 练习3.41：编写一段程序，用整型数组初始化一个vector对象。
 */

#include <iostream>
#include <vector>

using std::endl;
using std::cout;
using std::vector;

int main()
{
	int a[] = {1, 2, 3, 4, 5};
	vector<int> vec(std::begin(a), std::end(a));

	for (auto i : vec)
		cout << i << " ";
	cout << endl;

	return 0;
}
