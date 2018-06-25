// example: 从容器内部删除一个元素（p312）

#include <iostream>
#include <list>

using namespace std;

int main()
{
	// 循环删除一个list中的所有奇数元素

	list<int> lst = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	auto it = lst.begin();
	while (it != lst.end()) {
		if (*it % 2)
			it = lst.erase(it);
		else
			++it;
	}

	for (auto i : lst)
		cout << i << " ";
	cout << endl;

	return 0;
}
