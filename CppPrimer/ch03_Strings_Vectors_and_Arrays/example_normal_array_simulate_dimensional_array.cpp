// example: 一维数组模拟二维数组

#include <iostream>

using namespace std;

constexpr int ROW = 4;
constexpr int COL = 4;

// 这样子也可以模拟一个二维数组
int a[ROW * COL];

// 根据传入的行列数得到真实的下标
int get_idx(int r, int c)
{
	return r * COL + c;
}

// 初始化（遍历）的方法
void init_func()
{
	int tmp = 1;
	for (int i = 0; i < ROW; ++i)
		for (int j = 0; j < COL; ++j) {
			int idx = get_idx(i, j);
			a[idx] = tmp++;
		}
}

// 输出（遍历）一行的方法
void print_row(int r)
{
	if (r < 0 || r >= ROW) return;

	int start_idx = r * COL;
	int end_idx = start_idx + COL;

	for (int i = start_idx; i < end_idx; ++i)
		cout << a[i] << " ";

	cout << endl;
}

// 清空（另一种遍历）的方法
void clear_arr()
{
	for (int i = 0; i < ROW * COL; ++i)
		a[i] = 0;
}

int main()
{
	init_func();

	print_row(3);

	return 0;
}
