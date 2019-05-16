/*
    char* strpbrk(const char *s, const char *accept);
    从字符串s中查询accept中任意一个字符匹配的首个字符，返回其地址，找不到返回空指针。
    不会匹配空字符。
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* 分割字符串 */
void split(const char *str, const char *delim)
{
    const char *p = str;
    char *q = strpbrk(str, delim);
    char *buffer = malloc(strlen(str) + 1);

    while (q != NULL) {
        memset(buffer, 0, sizeof(buffer));
        memcpy(buffer, p, q - p);

        if (strlen(buffer) > 0)
            printf("%s\n", buffer);

        p = q + 1;
        q = strpbrk(p, delim);
    }

    if (p - str < strlen(str))
    {
        memset(buffer, 0, sizeof(buffer));
        memcpy(buffer, p, strlen(str) - (p - str));

        if (strlen(buffer) > 0)
            printf("%s\n", buffer);
    }

    free(buffer);
}
void test_split()
{
    split("abc:wow:hahaha:yes", ":");
}

void test1()
{
    char *p, str[] = "From follows function.";
    p = strpbrk(str, "xyF");

    if (p != NULL) {
        printf("find, pos: %ld, char: %c\n", p - str, *p);
    }
    else {
        printf("not find\n");
    }
}

int main(int argc, char const *argv[])
{
    //test1();
    test_split();
    
    return 0;
}
