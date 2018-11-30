/*
    使用 isalpha 函数和 isalnum 函数编写一个函数，用来检查一个字符串是否符合C语言标识符语法
    （也就是说，它由字母、数字和下划线组成，并以字母或下划线开始）。
*/

#include <ctype.h>
#include <stdio.h>

int is_correct_identifier(const char *identifier)
{
    if (*identifier != '_' && !isalpha(*identifier)) {
        return 0;
    }

    while (*(++identifier) != '\0') {
        if (*identifier != '_' && !isalnum(*identifier)) {
            return 0;
        }
    }

    return 1;
}

int main()
{
    char identifier[128];
    printf("Enter a identifier: ");
    scanf("%s", identifier);

    printf("%s\n", is_correct_identifier(identifier) ? "correct" : "not correct");

    return 0;
}