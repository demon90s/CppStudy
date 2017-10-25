// example: 在一条语句中混用解引用和递增运算符（p132）

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::cin;
using std::vector;

int main()
{
	vector<int> v = {1, 2, 3, -1, 4};

	auto pbeg = v.begin();
	// 输出元素直至遇到第一个负数为止
	while (pbeg != v.end() && *pbeg >= 0)
		cout << *pbeg++ << endl;	// 输出当前值，并将pbeg向前移动一个元素

	return 0;
}
