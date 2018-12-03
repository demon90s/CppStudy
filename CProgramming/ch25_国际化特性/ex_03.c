/*
 * 用于 kanji （日文中的汉字）的 Shift-JIS 编码要求每个字符是单字节或者双字节的。如果字符的第
 * 一个字节位于 0x81 和 0x9f 之间，或者位于 0xe0 和 0xef 之间，那么就需要第二个字节。（把任何其
 * 他字节看成是整个字符。）第二个字节必须在 0x40 和 0x7e 之间，或者在 0x80 和 0xfc 之间。（所有
 * 的范围都包含边界值。）对于下面的每个字符串，当传递其作为参数时，请指出25.2节的 mbcheck 函数
 * 将返回的值。
 *
 * ... 略
 */

/*
 * a: -1
 * b: -1
 * c: -1
 * d: -1
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <limits.h>

int mbcheck(const char *s)
{
    int n;

    for (mblen(NULL, 0); ; s += n)
        if ((n = mblen(s, MB_CUR_MAX)) <= 0)
            return n;
}

int main()
{
	printf("a: %d\n", mbcheck("\x05\x87\x80\x36\xed\xaa"));
	printf("b: %d\n", mbcheck("\x20\xe4\x50\x88\x3f"));
	printf("c: %d\n", mbcheck("\xde\xad\xbe\xef"));
	printf("d: %d\n", mbcheck("\x8a\x60\x92\x74\x41"));

	return 0;
}
