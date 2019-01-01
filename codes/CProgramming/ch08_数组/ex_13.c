/*
 * 描述见书本。
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	char matrix[10][10];
	int i, j, x, y;
	int tmp, hit[4];
	char word;
	int find;

	for (i = 0; i < 10; i++)
		for (j = 0; j < 10; j++)
			matrix[i][j] = '.';

	srand(time(NULL));

	word = 'A';
	x = y = 0;
	
	matrix[x][y] = word;
	while (word != 'Z') {
		for (i = 0; i < 4; i++) hit[i] = 0;

		find = 0;

		do {
			i = x;
			j = y;
			tmp = rand() % 4;
			hit[tmp] = 1;
			switch (tmp) {
				case 0 : j--; break;
				case 1 : j++; break;
				case 2 : i--; break;
				case 3 : i++; break;
			}

			if (i >= 0 && i < 10 && j >= 0 && j < 10 && matrix[i][j] == '.') {
				find = 1;
				break;
			}

			if (hit[0] && hit[1] && hit[2] && hit[3]) {
				break;
			}

		} while (1);

		if (!find) break;

		++word;
		matrix[i][j] = word;

		x = i;
		y = j;
	}
	
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			putchar(matrix[i][j]);
			putchar(' ');
		}
		putchar(10);
	}
	

	return 0;
}
