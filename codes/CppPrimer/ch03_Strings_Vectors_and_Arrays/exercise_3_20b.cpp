/*
 * 练习3.20：读入一组整数并把它们存入一个vector对象，将每对相邻整数的和输出出来。改写你的程序，这次要求先输出第1个和最后一个元素的和，接着输出第2个和倒数第2个元素的和，以此类推。
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

	using idx = decltype(ivec.size());
	idx beg_i = 0;
	idx end_i = ivec.size() - 1;

	while (beg_i < end_i) {
		cout << ivec[beg_i] + ivec[end_i] << endl;
		++beg_i;
		--end_i;
	}

	return 0;
}
