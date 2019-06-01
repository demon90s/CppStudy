/*
 * 练习3.14：编写一段程序，用cin读入一组整数并把它们存入一个vector对象。
 */

#include <iostream>
#include <vector>

using std::cin;
using std::vector;

int main()
{
	int a = 0;
	vector<int> ivec;
	while (cin >> a) {
		ivec.push_back(a);
	}

	return 0;
}
