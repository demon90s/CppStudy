/*
 * 练习3.43：编写3个不同版本的程序，令其均能输出ia的元素。版本1使用范围for语句管理迭代过程；版本2和版本3都使用普通的for语句，其中版本2要求用下标运算符，版本3要求用指针。此外，在所有3个版本的程序中都要直接写出数据类型，而不能使用类型别名、auto关键字或decltype关键字。
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

	for (size_t i = 0; i < ROW; ++i) {
		for (size_t j = 0; j < COL; ++j) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
