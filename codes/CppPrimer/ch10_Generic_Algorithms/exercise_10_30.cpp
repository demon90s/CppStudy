// 练习10.30：使用流迭代器、sort和copy从标准输入读取一个整数序列，将其排序，
// 并将结果写到标准输出。

#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	istream_iterator<int> in_iter(cin), in_eof;
	ostream_iterator<int> out_iter(cout, " ");
	vector<int> v(in_iter, in_eof);

	sort(v.begin(), v.end());
	copy(v.begin(), v.end(), out_iter);
	cout << endl;	

	return 0;
}
