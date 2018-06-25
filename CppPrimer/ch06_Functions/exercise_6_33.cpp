/*
 * 练习6.33：编写一个递归函数，输出vector对象的内容。
 */

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::cin;
using std::vector;

using Iter = vector<int>::iterator;

void print_vec(Iter beg, Iter end)
{
	if (beg != end) {
		cout << *beg << endl;
		print_vec(beg + 1, end);
	}

}

int main()
{
	vector<int> ivec{1, 2, 3, 4, 5};

	print_vec(ivec.begin(), ivec.end());

	return 0;
}
