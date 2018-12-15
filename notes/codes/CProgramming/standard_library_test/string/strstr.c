/*
    strstr
    char *strstr(const char *s, const char *substr);
    在字符串s中搜索子串 substr ，如果找到，返回子串在s中的地址，否则返回空指针。
*/

#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char *p, str[] = "Hello World";
    p = strstr(str, "World");
    if (p != NULL) {
        printf("find, pos: %d\n", p - str);
    }
    else {
        printf("not find\n");
    }

    return 0;
}
