/*
 * 修改6.3节的程序 square2.c 以便它在每24次平方后暂停并且显示下列信息：
 * Press Enter to continue...
 */

/* Prints a table of squares using a for statement */

#include <stdio.h>

int main()
{
	int i, n;
	int ch;

	printf("This program prints a table of squares.\n");
	printf("Enter number of entries in table: ");
	scanf("%d", &n);
	getchar(); /* skip enter character */

	for (i = 1; i <= n; ++i) {
		printf("%10d%10d\n", i, i * i);

		if (i % 24 == 0) {
			do {
				printf("Press Enter to continue...");
				ch = getchar();
			} while (ch != 10) ;
		}
	}

	return 0;
}
