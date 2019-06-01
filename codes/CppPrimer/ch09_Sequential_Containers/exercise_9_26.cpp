// 使用下面代码定义的ia，将ia拷贝到一个vector和一个list中。使用
// 单迭代器版本的erase从list中删除奇数元素，从vector中删除偶数元素。

#include <iostream>
#include <vector>
#include <list>

using namespace std;

#define print_container(c)\
do {\
	cout << #c << ": ";\
	for (auto i : c)\
		cout << i << " ";\
	cout << endl;\
} while (0)

void EraseEvenFromVector(vector<int> &vec)
{
	auto it = vec.begin();
	while (it != vec.end()) {
		if (*it % 2 == 0)
			it = vec.erase(it);
		else
			++it;
	}
}

void EraseOddFromList(list<int> &lst)
{
	auto it = lst.begin();
	while (it != lst.end()) {
		if (*it % 2)
			it = lst.erase(it);
		else
			++it;
	}
}

int main()
{
	int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};

	vector<int> vec(begin(ia), end(ia));
	print_container(vec);

	list<int> lst(begin(ia), end(ia));
	print_container(lst);

	EraseEvenFromVector(vec);
	print_container(vec);

	EraseOddFromList(lst);
	print_container(lst);

	return 0;
}
