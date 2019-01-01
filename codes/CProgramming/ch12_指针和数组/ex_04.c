/*
 * (a) 编写程序，用来读取一条消息，然后反向显示出这条消息。程序的输出格式如下：
 *
 * Enter a message: Don't get mad, get even.
 * Reversal is: .neve teg ,dam teg t'noD
 *
 * 提示：读消息一次读取一个字符（用 getchar 函数），并且把这些字符存储在数组中，档数组满了或
 * 者读到字符'\n'时停止读操作。
 *
 * (b) 修改上述程序，用指针来代替整数来跟踪数组中的当前位置。
 */

#include <stdio.h>

#define LEN 30

void solution_a()
{
	char str[LEN + 1] = {0};
	int ch;
	int i, count;

	printf("Enter a message: ");
	count = 0;
	while (count < LEN && (ch = getchar()) != '\n') {
		str[count++] = (char)ch;
	}

	printf("Reversal is: ");
	for (i = count - 1; i >= 0; i--) {
		putchar(str[i]);
	}
	printf("\n");
}

void solution_b()
{
	char str[LEN + 1] = {0};
	int ch;
	char *p;

	printf("Enter a message: ");
	p = str;
	while (p != str + LEN && (ch = getchar()) != '\n') {
		*p++ = (char)ch;
	}

	printf("Reversal is: ");
	while (p != str) {
		putchar(*--p);
	}
	printf("\n");
}

int main()
{
	//solution_a();
	solution_b();

	return 0;
}
