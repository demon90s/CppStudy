/*
    请编写名为 strdup 的函数，此函数使用动态存储分配来产生字符串的副本。例如，调用
    p = strdup(str);
    将为和 str 长度相同的字符串分配内存空间，并且把字符串 str 的内容复制给新字符串，然后返回指向
    新字符串的指针。如果分配内存失败，那么函数 strdup 返回空指针。
*/

#include <stdio.h>
#include <stdlib.h>

char* strdup(const char* str);

int main(int argc, char const *argv[])
{
    char *str = strdup("Hello World");

    printf("%s\n", str);

    free(str);
    
    return 0;
}

char* strdup(const char* str)
{
    char *ret, *p;
    const char *q;
    int str_len = 0;

    q = str;
    while (*str++ != '\0') {
        str_len++;
    }

    ret = (char*)malloc(1 + str_len * sizeof(char));
    if (ret != NULL) {
        p = ret;
        while ((*p++ = *q++));
    }
    return ret;
}