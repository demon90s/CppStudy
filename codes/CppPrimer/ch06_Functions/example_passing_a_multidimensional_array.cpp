// example: 传递多维数组给形参（p195）

#include <iostream>

using std::cout;
using std::endl;
using std::cin;

void print(int (*matrix)[10], int rowSize)
{
	for (int i = 0; i < rowSize; ++i) {
		for (int j = 0; j < 10; ++j) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	int matrix[2][10] = 
	{
		{1, 2, 3},
		{4, 5, 6}
	};

	print(matrix, 2);

	return 0;
}
