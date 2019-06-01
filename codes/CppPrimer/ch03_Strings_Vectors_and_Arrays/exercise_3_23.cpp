/*
 * 练习3.23：编写一段程序，创建一个含有10个整数的vector对象，然后使用迭代器将所有元素的值都变成原来的两倍。输出vector对象的内容，检验程序是否正确。
 */

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main()
{
	vector<int> ivec;
	for (int i = 1; i <= 10; ++i)
		ivec.push_back(i);

	for (auto it = ivec.begin(); it != ivec.end(); ++it)
		*it *= 2;

	for (auto it = ivec.cbegin(); it != ivec.cend(); ++it)
		cout << *it << " ";
	cout << endl;

	return 0;
}
