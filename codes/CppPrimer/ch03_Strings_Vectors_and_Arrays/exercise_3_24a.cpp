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

	if (ivec.begin() == ivec.end())
		return 0;

	for (auto it = ivec.cbegin() + 1; it != ivec.cend(); ++it)
		cout << *it + *(it - 1) << endl;

	return 0;
}
