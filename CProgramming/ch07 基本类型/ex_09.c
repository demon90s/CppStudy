/*
 * 编写程序可以把字母格式的电话号码翻译成数值格式：
 *
 * Enter phone number: CALLATT
 * 2255288
 *
 * （万一没有电话在身边，后面有字母在键盘上的对应关系：2=ABC, 3=DEF, 4=GHI, 5=JKL, 6=MNO,
 * 7=PRS, 8=TUV, 9=WXY。）如果原始的电话号码包含非字母的字符（例如，数字或标点符号），那
 * 么保留下来不做变化：
 *
 * Enter phone number: 1-900-COL-LECT
 * 1-800-265-5328
 */

#include <stdio.h>

int main()
{
	int n;

	printf("Enter phone number: ");

	while ((n = getchar()) != '\n') {
		if (!isalpha(n)) {
			putchar(n);
			continue;
		}

		n = toupper(n);
		if (n == 'A' || n == 'B' || n == 'C') putchar('2');
		else if (n == 'D' || n == 'E' || n == 'F') putchar('3');
		else if (n == 'G' || n == 'H' || n == 'I') putchar('4');
		else if (n == 'J' || n == 'K' || n == 'L') putchar('5');
		else if (n == 'M' || n == 'N' || n == 'O') putchar('6');
		else if (n == 'P' || n == 'R' || n == 'S') putchar('7');
		else if (n == 'T' || n == 'U' || n == 'V') putchar('8');
		else if (n == 'W' || n == 'X' || n == 'Y') putchar('9');
	}

	putchar(10);

	return 0;
}
