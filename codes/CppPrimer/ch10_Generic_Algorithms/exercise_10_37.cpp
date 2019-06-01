// 练习10.37：给定一个包含10个元素的vector，将位置3到7之间的元素按逆序拷贝
// 到一个list中。

#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main()
{
	vector<int> v;
	for (int i = 1; i <= 10; ++i)
		v.push_back(i);

	auto beg = v.crbegin() + 3;
	auto end = v.crbegin() + 8;

	list<int> lst(beg, end);
	for (auto i : lst)
		cout << i << " ";
	cout << endl;

	return 0;
}
