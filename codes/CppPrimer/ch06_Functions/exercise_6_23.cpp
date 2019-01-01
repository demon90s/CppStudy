/*
 * 练习6.23：参考本节介绍的几个print函数，根据理解编写你自己的版本。以此调用每个函数使其输入
 * 下面定义的i和j。
 *
 * int i = 0, j[2] = {0, 1};
 */

#include <iostream>

using std::cout;
using std::endl;
using std::cin;

// 使用标记指定数组长度
void print(const char *cp)
{
	if (cp)					// 若cp非空
		while (*cp)			// 只要指针所指字符非空字符
			cout << *cp++;	// 输出当前字符并将指针向前移动一个位置
}

// 使用标准库规范
void print(const int *beg, const int *end)
{
	// 输出beg到end之间（不含end）的所有元素
	while (beg != end)
		cout << *beg++ << " ";	// 输出当前元素并将指针向前移动一个位置
	cout << endl;
}

// 显示传递一个表示数组大小的形参
// const int ia[]等价于const int* ia
// size表示数组的大小，将它显式地传给函数用于控制对ia元素的访问
void print(const int ia[], size_t size)
{
	for (size_t i = 0; i != size; ++i) {
		cout << ia[i] << " ";
	}
	cout << endl;
}

int main()
{
	int i = 0, j[2] = {0, 1};
	print(std::begin(j), std::end(j));	// void print(const int *beg, const int *end)

	print(&i, 1);						// void print(const int ia[], size_t size)

	return 0;
}
