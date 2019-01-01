/*
 * 请确定你用的编译器支持哪种地区。
 */

/*
 * 至少是支持简体中文（中国）的。
 */

#include <stdio.h>
#include <locale.h>
#include <wchar.h>

void test1()
{
	setlocale(LC_ALL, "zh_CN.UTF-8");

	wprintf(L"你好啊，中国\n");
}

int main()
{
	test1();

	return 0;
}
