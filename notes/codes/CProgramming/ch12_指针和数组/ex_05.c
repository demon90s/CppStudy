/*
 * (a) 编写程序，用来读一条消息，然后检查这条消息是否是回文（信息中从左到右的字母和从右到左
 * 的字母完全一样）：
 *
 * Enter a message: He lived as a devil, eh?
 * Palindrome
 *
 * Enter a message: Madam, I am Adam.
 * Not a palindrome
 *
 * 忽略所有不是字母的字符。用整型变量来跟踪数组内的位置。
 * (b) 修改上述程序，使用指针来代替整数跟踪数组的位置。
 */

#include <stdio.h>
#include <ctype.h>

#define LEN 30

void solution_a()
{
	char str[LEN + 1] = {0};
	int i, j, count;
	int ch;

	printf("Enter a message: ");
	count = 0;
	while (count < LEN && (ch = getchar()) != '\n') {
		str[count++] = (char)ch;
	}

	i = 0;
	j = count - 1;

	while (i < j) {
		if (!isalpha(str[i])) { i++; continue; }
		if (!isalpha(str[j])) { j--; continue; }

		if (toupper(str[i]) != toupper(str[j])) {
			printf("Not a palindrome\n");
			return;
		}

		i++;
		j--;
	}

	printf("Palindrome\n");
}

void solution_b()
{
	char str[LEN + 1] = {0};
	int ch;
	char *p, *q;

	printf("Enter a message: ");
	p = str;
	while (p != str + LEN && (ch = getchar()) != '\n') {
		*p++ = (char)ch;
	}

	q = p - 1;
	p = str;

	while (p < q) {
		if (!isalpha(*p)) { p++; continue; }
		if (!isalpha(*q)) { q--; continue; }

		if (toupper(*p) != toupper(*q)) {
			printf("Not a palindrome\n");
			return;
		}

		p++;
		q--;
	}

	printf("Palindrome\n");
}

int main()
{
	//solution_a();
	solution_b();

	return 0;
}
