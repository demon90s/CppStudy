// 练习10.31：修改前一题的程序，使其只打印不重复的元素。你的程序应使用
// unique_copy（参见10.4.1节，第359页）。

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
	unique_copy(v.begin(), v.end(), out_iter);
	cout << endl;	

	return 0;
}
