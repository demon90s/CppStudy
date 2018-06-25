/*
 * 练习9.5：重写上一题的函数，返回一个迭代器指向找到的元素。注意，程序必须处理
 * 未找到给定值的情况。
 */

#include <iostream>
#include <vector>

using namespace std;

using VecIt = vector<int>::const_iterator;

VecIt find_val(VecIt beg, VecIt end, int i)
{
	while (beg != end) {
		if (*beg == i) return beg;
		++beg;
	}
	return end;
}

int main()
{
	vector<int> vec = {1, 2, 3, 4, 5};
	VecIt pos_it = find_val(vec.begin(), vec.end(), 3);
	if (pos_it != vec.end())
		cout << "find, pos: " << pos_it - vec.begin() << endl;
	else
		cout << "not find" << endl;

	return 0;
}
