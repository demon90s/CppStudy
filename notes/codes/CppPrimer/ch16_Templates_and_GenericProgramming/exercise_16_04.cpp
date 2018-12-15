// 练习16.4：编写行为类似标准库find算法的模板。函数需要两个模板类型参数，一个
// 表示函数的迭代器参数，另一个表示值的类型。使用你的函数在一个vector<int>和
// 一个list<string>中查找给定值。

#include <iostream>
#include <vector>
#include <list>

using namespace std;

template<typename It, typename S>
It my_find(It beg, It end, S sought)
{
	while (beg != end) {
		if (*beg == sought)
			return beg;
		++beg;
	}

	return end;
}

int main()
{
	vector<int> vec = {1, 2, 5, 8, 3};
	if (my_find(vec.begin(), vec.end(), 8) != vec.end())
	{
		cout << "vec find!" << endl;
	}

	list<int> lst = {1, 2, 5, 8, 3};
	if (my_find(lst.begin(), lst.end(), 10) == lst.end())
	{
		cout << "list not find!" << endl;
	}

	return 0;
}
