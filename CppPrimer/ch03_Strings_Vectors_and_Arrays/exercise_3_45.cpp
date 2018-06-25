/*
 * 练习3.43：再一次改写程序，这次使用auto关键字。
 */

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
	constexpr size_t ROW = 3;
	constexpr size_t COL = 4;
	int a[ROW][COL] =
	{
		{0, 1, 2, 3},
		{4, 5, 6, 7},
		{8, 9, 10, 11}
	};

	for (auto p = a; p != a + ROW; ++p) {
		for (auto q = *p; q != *p + COL; ++q) {
			cout << *q << " ";
		}
		cout << endl;
	}

	return 0;
}
