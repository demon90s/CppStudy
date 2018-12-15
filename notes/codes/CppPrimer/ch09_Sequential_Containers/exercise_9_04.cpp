/*
 * 练习9.4：编写函数，接受一对指向vector<int>的迭代器和一个int值。在两个迭代器
 * 指定的范围中查找给定的值，返回一个布尔值来指出是否找到。
 */

#include <iostream>
#include <vector>

using namespace std;

using VecIt = vector<int>::const_iterator;

bool find_val(VecIt beg, VecIt end, int i)
{
	while (beg != end) {
		if (*beg++ == i) return true;
	}
	return false;
}

int main()
{
	vector<int> vec = {1, 2, 3, 4, 5};
	if (find_val(vec.begin(), vec.end(), 3))
		cout << "find" << endl;
	else
		cout << "not find" << endl;

	return 0;
}
