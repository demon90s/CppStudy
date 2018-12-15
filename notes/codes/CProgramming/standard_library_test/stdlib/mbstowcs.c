/*
 * #include <stdlib.h>
 * size_t mbstowcs(wchar_t *pwcs, const char *s, size_t n);
 *
 * 把多字节字符串 s 转换成宽字符序列 pwcs 。第三个参数限制了可以存储在数组中的宽字符的数量。
 * 当达到了上限 n 或者遇到空字符时， 函数停止，空字符会存储进去。函数返回修改的数组元素的数量（不包括空字符）。
 * 如果遇到无效的多字节字符， mbstowcs 返回-1 。
 *
 * mbstowcs 假设要转换的字符串以初始移位状态开始。
 */

#include <stdlib.h>
#include <stdio.h>
#include <wchar.h>
#include <locale.h>

#define WCHAR_STR_LEN 100

int main()
{
	setlocale(LC_ALL, "zh_CN.UTF-8");

	wchar_t pwcs[WCHAR_STR_LEN + 1];
	const char *s = "你好啊";
	size_t n;

	mblen(NULL, 0);
	n = mbstowcs(pwcs, s, WCHAR_STR_LEN);
	if (n > 0) {
		wprintf(L"translate %d characters, str: %ls\n", n, pwcs);
	}

	return 0;
}
