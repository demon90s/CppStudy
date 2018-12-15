/*
    char *strchr(const char *s, int c);
    在字符串s中搜索字符c，返回找到的第一个字符的地址，如果找不到，返回空指针。

    char *strrchr(const char *s, int c);
    在字符串s中反向搜索字符c，返回从最后面找到的第一个字符的地址，如果找不到，返回空指针。

    void *memchr(const void *s, int c, size_t n);
    与 strchr 类似，但会在搜索了n个字符后停止，而不是遇到空字符。
*/

#include <stdio.h>
#include <string.h>

void test_strchr()
{
    char *p, str[] = "From follows function.";
    p = strchr(str, 'f');
    if (p != NULL) {
        printf("find, pos: %d\n", p - str);
    }
    else {
        printf("not find\n");
    }
}

void test_strrchr()
{
    char *p, str[] = "From follows function.";
    p = strrchr(str, 'f');
    if (p != NULL) {
        printf("find, pos: %d\n", p - str);
    }
    else {
        printf("not find\n");
    }
}

void test_memchr()
{
    char *p, str[5] = "Hello";
    p = memchr(str, 'o', sizeof(str));
    if (p != NULL) {
        printf("find, pos: %d\n", p - str);
    }
    else {
        printf("not find\n");
    }
}

int main(int argc, char const *argv[])
{
    test_strchr();
    test_strrchr();
    test_memchr();

    return 0;
}
