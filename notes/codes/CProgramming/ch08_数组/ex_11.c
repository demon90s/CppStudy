/*
 * 编写程序，要求此程序可以用来读取一个 5*5 的整数数组，然后显示出每行的求和结果和每列的
 * 求和结果。
 *
 * Enter row 1: 8 3 9 0 10
 * Enter row 2: 3 5 17 1 1
 * Enter row 3: 2 8 6 23 1
 * Enter row 4: 15 7 3 2 9
 * Enter row 5: 6 14 2 6 0
 *
 * Row totals: 30 27 40 36 28
 * Column totals: 34 37 37 32 21
 */

#include <stdio.h>

int main()
{
	int arr[5][5];
	int i, j;
	int sum;

	for (i = 0; i < 5; i++) {
		printf("Enter row %d: ", i + 1);
		for (j = 0; j < 5; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	printf("Row totals:");
	for (i = 0; i < 5; i++) {
		sum = 0;
		for (j = 0; j < 5; j++) {
			sum += arr[i][j];
		}
		printf(" %d", sum);
	}
	printf("\n");

	printf("Column totals:");
	for (j = 0; j < 5; j++) {
		sum = 0;
		for (i = 0; i < 5; ++i) {
			sum += arr[i][j];
		}
		printf(" %d", sum);
	}
	printf("\n");

	return 0;
}
