/*
 * 编写一个程序，要求用户输入一个两位的数，然后显示这个数的英文单词：
 *
 * Enter a two-digit number: 45
 * You entered the number forty-five
 *
 * 提示：把数分解为两个数字。用一个 switch 语句显示第一位数字对应的单词（"twenty"、"thirty"
 * 等），用第二个 switch 语句显示第二位数字对应的单词。不要忘记11~19的数有特殊的处理要求。
 */

#include <stdio.h>

int main()
{
	int n1, n2; /* n1 十位，n2 个位 */

	printf("Enter a two-digit number: ");
	scanf("%1d%1d", &n1, &n2);

	printf("You entered the number ");

	switch (n1) {
		case 0:
		case 1:
			break;

		case 2:
			printf("twenty"); break;
		case 3:
			printf("thirty"); break;
		case 4:
			printf("forty"); break;
		case 5:
			printf("fifty"); break;
		case 6:
			printf("sixty"); break;
		case 7:
			printf("seventy"); break;
		case 8:
			printf("eighty"); break;
		case 9:
			printf("ninety"); break;
	}

	switch (n2) {
		case 0:
			if (n1 == 1) printf("ten"); break;
		case 1:
			if (n1 == 1) printf("eleven"); else printf("-one"); break;
		case 2:
			if (n1 == 1) printf("twelve"); else printf("-two"); break;
		case 3:
			if (n1 == 1) printf("thirteen"); else printf("-three"); break;
		case 4:
			if (n1 == 1) printf("fourteen"); else printf("-four"); break;
		case 5:
			if (n1 == 1) printf("fifteen"); else printf("-five"); break;
		case 6:
			if (n1 == 1) printf("sixteen"); else printf("-six"); break;
		case 7:
			if (n1 == 1) printf("seventeen"); else printf("-seven"); break;
		case 8:
			if (n1 == 1) printf("eighteen"); else printf("-eight"); break;
		case 9:
			if (n1 == 1) printf("nineteen"); else printf("-nine"); break;
	}

	printf("\n");

	return 0;
}
