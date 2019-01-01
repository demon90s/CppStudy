/*
    #include <stdlib.h>
    int mbtowc(wchar_t *pwc, const char *s, size_t n);

    将 s 指向其首字节的多字节字符转换成宽字符，若 pwc 非空则写入 *pwd 。
    若 s 为空指针，则重置全局转换状态并确定是否使用迁移序列。

    n 代表 s 中能被检验的字节数限制。

    若 s 不是空指针，则返回多字节字符所含的字节数，若不是多字节字符，返回-1 ，
    若 s 指向空字符，则返回0 。
*/

#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <wchar.h>

int main(int argc, char const *argv[])
{
	setlocale(LC_ALL, "zh_CN.UTF-8");

	const char multi_bytes_str[] = "你好啊";
	const char *p = multi_bytes_str;
	wchar_t pwc;
	int n = 0;

	mbtowc(NULL, NULL, 0);
	while ((n = mbtowc(&pwc, p, MB_CUR_MAX)) > 0) {
		wprintf(L"multi_bytes: %d, character: %lc\n", n, pwc);
		p += n;
	}

    return 0;
}
