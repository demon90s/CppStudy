/*
 * 图书用国际标准图书编号（ ISBN ）进行标识，如0-393-30375-6。编号中的第一个数字说明编写书籍
 * 所用的语言（例如，0表示英语，3表示德语）。接下来的一组数字表示出版社（例如，393是 W.W.Norton
 * 出版社的编号），而随后的数字则是出版社设定的，用来识别图书（例如，30375是 Stephen Jay Gould
 * 的 The Flamingo's Smile 一书的编号）。最后，结尾数字是“校验数字”，它用来验证前面数字的准确性。
 * 编写一个程序来分解用户录入的 ISBN 信息，格式如下：
 * Enter ISBN: 0-393-30375-6
 * Language: 0
 * Publisher: 393
 * Book Number: 30375
 * Check digit: 6
 */

#include <stdio.h>

int main()
{
	int language, publisher, book_number, check_digit;

	printf("Enter ISBN: ");
	scanf("%d-%d-%d-%d", &language, &publisher, &book_number, &check_digit);

	printf("Language: %d\n", language);
	printf("Publisher: %d\n", publisher);
	printf("Book Number: %d\n", book_number);
	printf("Check digit: %d\n", check_digit);
	
	return 0;
}
