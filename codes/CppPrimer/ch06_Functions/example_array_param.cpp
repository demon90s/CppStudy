// example: 数组形参（p193）
 
/*
 * 定义若干print函数，功能是打印数组内容，稍微做了微调
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

// 数组引用形参
void print(int (&arr)[10])
{
	for (auto elem : arr)
		cout << elem << " ";
	cout << endl;
}

int main()
{
	print("Hello World\n");				// void print(const char *cp)

	int j[2] = {0, 1};
	print(std::begin(j), std::end(j));	// void print(const int *beg, const int *end)

	print(j, 2);						// void print(const int ia[], size_t size)

	int k[10] = {1, 2, 3, 4};			// void print(int (&arr)[10])
	print(k);

	return 0;
}
