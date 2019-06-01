/*
    在23.5节中阐述了如何反复调用 strchr 函数在字符串中找到所有出现的指定字符。那么能否通过反复
    调用 strrchr 函数反向找到所有出现的指定字符呢？
*/

/*
    可以。
*/

#include <stdio.h>
#include <string.h>

int main()
{
    char str[] = "hello world, opps";
    char *p;
    char ch;

    printf("str is: %s\n", str);
    printf("Enter character you want to find: ");
    scanf(" %c", &ch);

    printf("find pos:");
    do {
        p = strrchr(str, ch);
        if (!p) break;

        printf(" %d", p - str);
        str[p - str] = '\0';

    } while (1);
    printf("\n");

    return 0;
}