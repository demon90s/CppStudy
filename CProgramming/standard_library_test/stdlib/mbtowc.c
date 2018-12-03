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

// 打印多字节字符串到宽面向的 stdout
// 等价于 wprintf(L"%s\n", ptr);
void print_mb(const char *ptr)
{
    mbtowc(NULL, 0, 0); // 重置初始转换状态
    const char *end = ptr + strlen(ptr);
    int ret;
    for (wchar_t wc; (ret = mbtowc(&wc, ptr, end-ptr)) > 0; ptr += ret) {
        wprintf(L"%lc", wc);
    }
    wprintf(L"\n");
}

int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, "en_US.utf8");

    // UTF-8 窄多字节编码
    print_mb(u8"z\u00df\u6c34\U0001F34C");
    
    return 0;
}
