/*
    isalnum(c)      c是否是字母或数字
    isalpha(c)      c是否是字母
    iscntrl(c)      c是否是控制字符
    isdigit(c)      c是否是十进制数字
    isgraph(c)      c是否是可显示字符（除空格外）
    islower(c)      c是否是小写字母
    isprint(c)      c是否是可显示字符（包括空格）
    ispunct(c)      c是否是标点符号
    isspace(c)      c是否是空白字符
    isupper(c)      c是否是大写字母
    isxdigit(c)     c是否是十六进制数字

    控制字符包括 \0x00 \0x1f \0x7f
*/

#include <stdio.h>
#include <ctype.h>

#define TEST(f) printf("%c\t", f(*p) ? 'x' : ' ');

int main(int argc, char const *argv[])
{
    const char *str = "azAZ0  !\t";
    const char* p;
    printf("char\talnum\tcntrl\tgraph\tprint\tspace\txdigit\talpha\tdigit\tlower\tupper\tpunct\n");

    for (p = str; *p != '\0'; p++) {
        if (!isgraph(*p))
            printf("0x%02x:\t", *p);
        else
            printf("%c:\t", *p);

        TEST(isalnum);
        TEST(iscntrl);
        TEST(isgraph);
        TEST(isprint);
        TEST(isspace);
        TEST(isxdigit);
        TEST(isalpha);
        TEST(isdigit);
        TEST(islower);
        TEST(isupper);
        TEST(ispunct);

        printf("\n");
    }

    return 0;
}
