/*
 * 如果需要一个宏，使它展开后包含当前行号和文件名。换而言之，我们会写：
 * const char *str = LINE_FILE;
 * 扩展后为
 * const char *str = "Line 10 of file foo.c";
 *
 * 其中 foo.c 是包含程序的文件，10是调用 LINE_FILE 行的行号。
 */

#include <stdio.h>

#define LINE_FILE line_file(__LINE__)

const char *line_file(int line)
{
	static char buff[100];

	sprintf(buff, "Line %d of file %s", line, __FILE__);
	return buff;
}

int main()
{
	const char *str = LINE_FILE;
	printf("%s\n", str);

	return 0;
}
