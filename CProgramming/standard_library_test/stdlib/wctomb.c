/*
 *  #include <stdlib.h>
 *	int wctomb(char *s, wchar_t wc);
 *
 *	转换宽字符 wc 为多字节编码，存储到 s 。存储字节数不多于 MB_CUR_MAX 。
 *	若 s 是空指针，则将此函数重设全局转换状态并确定是否使用迁移序列。
 *
 *	不会附加空字符到 s 。
 *
 *	如果有效， wctomb 返回字符中字节的数量；如果无效，返回-1 。
 *	如果要求转换空的宽字符，则返回1 。
 */

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <wchar.h>
#include <locale.h>

/* 是否可以把宽字符的字符串转换为有效的多字节字符 */
int wccheck(wchar_t *wcs)
{
	char buf[MB_LEN_MAX];
	int n;

	for (wctomb(NULL, 0); ; ++wcs)
		if ((n = wctomb(buf, *wcs)) <= 0)
			return -1;	/* invalid character */
		else if (buf[n - 1] == '\0')
			return 0;	/* all characters are valid */
}

void test1()
{
	setlocale(LC_ALL, "zh_CN.UTF-8");
	
	wchar_t* wcs = L"水";
	wchar_t* wcs2 = L"Hello";

	wprintf(L"can convert '%Ls' to multi-byte string? %Ls\n", wcs, wccheck(wcs) == 0 ? L"yes" : L"no");

	wprintf(L"can convert '%Ls' to multi-byte string? %Ls\n", wcs2, wccheck(wcs2) == 0 ? L"yes" : L"no");
}

void test2()
{
	setlocale(LC_ALL, "zh_CN.UTF-8");

	char buff[MB_CUR_MAX];
	int n;

	wctomb(NULL, 0);
	n = wctomb(buff, L'水');
	if (n > 0) {
		buff[n] = '\0';
		printf("multi_bytes: %d, character: %s\n", n, buff);
	}
}

int main()
{
	//test1();

	test2();

	return 0;
}
