/*
 * 练习3.24：请使用迭代器重做3.3.3节（第94页）的最后一个练习。
 */

#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
	vector<int> ivec;
	int a = 0;
	while (cin >> a)
		ivec.push_back(a);

	if (ivec.empty())
		return 0;

	auto beg = ivec.cbegin();
	auto end = ivec.cend() - 1;

	while (beg < end) {
		cout << *beg + *end << endl;
		++beg;
		--end;
	}

	return 0;
}
