/*
    char* strpbrk(const char *s, const char *accept);
    从字符串s中查询accept中任意一个字符匹配的首个字符，返回其地址，找不到返回空指针。
    不会匹配空字符。
*/

#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char *p, str[] = "From follows function.";
    p = strpbrk(str, "xyF");

    if (p != NULL) {
        printf("find, pos: %d, char: %c\n", p - str, *p);
    }
    else {
        printf("not find\n");
    }
    
    return 0;
}
