/*
    使用 strchr 函数编写如下函数:
    int numchar(const char *s, char ch);
    函数 numchar 返回字符 ch 在字符串中出现的次数。
*/

#include <stdio.h>
#include <string.h>

int numchar(const char *s, char ch)
{
    int num = 0;
    const char *p;

    p = strchr(s, ch);
    while (p != NULL) {
        ++num;
        p = strchr(p + 1, ch);
    }

    return num;
}

int main()
{
    const char *str = "hello world";
    char ch;

    printf("str is: %s\n", str);
    printf("Enter character you want to find: ");
    scanf(" %c", &ch);

    printf("number of %c is: %d\n", ch, numchar(str, ch));

    return 0;
}