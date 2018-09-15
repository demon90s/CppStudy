/*
 * 在十字拼字游戏中，玩家利用小卡片组成单词，每个卡片包含字母和面值。面值根据字母的不同而
 * 不同，也就是说面值是基于字母变化的。（面值有：1-AEILNORSTU, 2-DG, 3-BCMP, 4-FHVWY, 5-K
 * , 8-JX, 10-QZ。）编写程序通过对字母对应的面值求和来计算单词的值：
 *
 * Enter a word: pitfall
 * Scrabble value: 12
 *
 * 编写的程序应该允许单词中混合出现大小写字母。提示：使用 toupper 库函数。
 */

#include <stdio.h>

int main()
{
	int ch;
	int value;

	printf("Enter a word: ");

	value = 0;
	while ((ch = getchar()) != '\n') {
		ch = toupper(ch);

		switch (ch) {
			case 'A':
			case 'E':
			case 'I':
			case 'L':
			case 'N':
			case 'O':
			case 'R':
			case 'S':
			case 'T':
			case 'U':
				value += 1;
				break;

			case 'D':
			case 'G':
				value += 2;
				break;

			case 'B':
			case 'C':
			case 'M':
			case 'P':
				value += 3;
				break;

			case 'F':
			case 'H':
			case 'V':
			case 'W':
			case 'Y':
				value += 4;
				break;

			case 'K':
				value += 5;
				break;

			case 'J':
			case 'X':
				value += 8;
				break;

			case 'Q':
			case 'Z':
				value += 10;
				break;
		}
	}

	printf("Scrabble value: %d\n", value);

	return 0;
}
