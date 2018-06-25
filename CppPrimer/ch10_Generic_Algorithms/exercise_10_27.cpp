//  练习10.27：除了unique（参见10.2.3节，第343页）之外，标准库还定义了名为
//  unique_copy的函数，它接受第三个迭代器，表示拷贝不重复元素的目的位置。编写
//  一个程序，使用unique_copy将一个vector中不重复的元素拷贝到一个初始为空的list中。

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> v{1, 5, 3, 4, 3, 9, 5};
	list<int> lst;

	sort(v.begin(), v.end());
	unique_copy(v.begin(), v.end(), back_inserter(lst));

	for_each(lst.begin(), lst.end(), [](int i) { cout << i << " "; });
	cout << endl;

	return 0;
}
