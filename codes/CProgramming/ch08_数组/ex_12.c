/*
 * 修改练习11，要求修改后的程序可以提示每个学生5门测验的成绩，一共有5个学生，然后计算每个学
 * 生的5门测验的总分和平均分，还要列出每门测验的平均分、高分和低分。
 */

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
	float avg[5];
	int min[5], max[5];

	for (i = 0; i < 5; i++) {
		printf("Enter score of student%d: ", i + 1);
		for (j = 0; j < 5; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	for (i = 0; i < 5; i++) {
		sum = 0;
		for (j = 0; j < 5; j++)
			sum += arr[i][j];

		printf("student%d total score: %d, average score: %.2f\n", i + i, sum, sum / 5.0);
	}

	for (j = 0; j < 5; j++) {
		i = 0;
		sum = 0;
		min[j] = max[j] = arr[i][j];
		for (; i < 5; ++i) {
			sum += arr[i][j];

			if (min[j] > arr[i][j]) min[j] = arr[i][j];
			if (max[j] < arr[i][j]) max[j] = arr[i][j];
		}
	
		avg[j] = sum / 5.0;
	}

	printf("Avg score:");
	for (i = 0; i < 5; i++) printf(" %.2f", avg[i]);
	printf("\n");

	printf("Min score:");
	for (i = 0; i < 5; i++) printf(" %d", min[i]);
	printf("\n");

	printf("Max score:");
	for (i = 0; i < 5; i++) printf(" %d", max[i]);
	printf("\n");

	return 0;
}
