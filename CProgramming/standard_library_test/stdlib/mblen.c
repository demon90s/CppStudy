/*
    #incude <stdlib.h>
    int mblen(const char* s, size_t n);
    确定 s 指向其首字节的多字节字符的字节大小。 n 代表 s 中能被检测的字节数限制，通常取值为 MB_CUR_MAX 。
    若 s 是空指针，则重置全局转换状态并确定是否使用迁移序列。

    如果 s 所指的首字节不是合法的多字节字符，返回-1。如果是空字符，返回0 。

    注意：
    每次调用 mblen ，都会更新其内部的全局转换状态。
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <limits.h>

/* 检测 s 是否是有效的多字节字符串 */
int mbcheck(const char *s)
{
    int n;

    for (mblen(NULL, 0); ; s += n)
        if ((n = mblen(s, MB_CUR_MAX)) <= 0)
            return n;
}

int main()
{
	/* 对于多字节的中文测试，需要设置成以下的本地环境 */
	setlocale(LC_ALL, "zh_CN.UTF-8");

    printf("Is 'Hello' multibyte string? %s\n", mbcheck("Hello") == 0 ? "yes" : "no");

    printf("Is '你好啊' multibyte string? %s\n", mbcheck("你好啊") == 0 ? "yes" : "no");

    return 0;
}
