/*
 * 练习3.32：将上一题刚刚创建的数据拷贝给另外一个数组。利用vector重写程序，实现类似的功能。
 */

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main()
{
	vector<int> vec1;
	for (int i = 0; i < 10; ++i)
		vec1.push_back(i);

	vector<int> vec2(vec1);
	for (auto i : vec2)
		cout << i << " ";
	cout << endl;

	return 0;
}
