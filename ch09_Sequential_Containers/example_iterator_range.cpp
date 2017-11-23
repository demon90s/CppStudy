// example: 迭代器范围iterator range（p296）

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> vec = {1, 2, 3, 4, 5};

	auto beg = vec.begin();
	auto end = vec.end();

	while (beg != end) {
		cout << *beg << endl; 	// 正确：范围非空，因此begin指向一个元素
		++beg;					// 移动迭代器，获取下一个元素
	}

	return 0;
}
