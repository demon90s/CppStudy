/*
 * 练习3.43：改写上一个练习中的程序，使用类型别名来代替循环控制变量的类型。
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

	using int_arr = int[COL];
	for (int_arr *p = a; p != a + ROW; ++p) {
		for (int *q = *p; q != *p + COL; ++q) {
			cout << *q << " ";
		}
		cout << endl;
	}

	return 0;
}
