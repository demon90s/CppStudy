// 练习10.36：使用find在一个int的list中查找最后一个值为0的元素。

#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main()
{
	list<int> lst{1, 0, 3, 0, 9};

	auto it = find(lst.crbegin(), lst.crend(), 0);

	if (it == lst.crend())
		cout << "no find" << endl;
	else {
		auto normal_it = it.base();
		if (normal_it != lst.end())
			cout << "find, next is: " << *it.base() << endl;
		else
			cout << "find, it is last number" << endl;
	}

	return 0;
}
