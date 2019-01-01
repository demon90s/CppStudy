/*
 * 8.2节有一个代码段是用两个嵌套的for循环初始化数组 ident ，此数组是用作恒等矩阵。请重新编写
 * 这段代码，采用一个指针来逐步访问数组中的元素，且每次一个元素。提示：因为不能用 row 和 col
 * 来索引变量，所以不会容易知道哪里存储1。但是，可以利用数组的第一个元素必须是1这个事实，
 * 接着N个元素都必须是0，再接下来的元素是1，以此类推。用变量来跟踪连续0的数量，并把此变量存储
 * 起来。当计数达到N时，就是存储1的时候了。
 */

#include <stdio.h>

#define N 10

void print(float ident[][N], int count)
{
	int row, col;

	for (row = 0; row < count; row++) {
		for (col = 0; col < N; col++)
			printf("%.1f ", ident[row][col]);
		printf("\n");
	}
}

void book_version()
{
	float ident[N][N];
	int row, col;

	for (row = 0; row < N; row++)
		for (col = 0; col < N; col++)
			if (row == col)
				ident[row][col] = 1.0;
			else
				ident[row][col] = 0.0;

	print(ident, N);
}

void ex_version()
{
	float ident[N][N];
	float *p;
	int cnt_zero;

	cnt_zero = 0;
	for (p = &ident[0][0]; p <= &ident[N-1][N-1]; p++) {
		if (cnt_zero == 0) *p = 1.0;
		else *p = 0.0;

		cnt_zero++;
		if (cnt_zero > N) cnt_zero = 0;
	}

	print(ident, N);
}

int main()
{
	//book_version();
	ex_version();

	return 0;
}
