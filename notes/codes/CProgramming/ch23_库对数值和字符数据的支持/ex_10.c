/*
    使用一个 strstr 函数调用来替换下面 if 语句中的测试条件：

    if (strcmp(str, "foo") == 0 || strcmp(str, "bar") == 0 ||
        strcmp(str, "baz") == 0) ...

    提示：将字符串子面量合并到一个字符串中，并使用一个特殊的字符分割它们。你的解决方案是否对
    str 的内容有所依赖呢？
*/

/*
    有所依赖， str 不可以使用分割的字符。
*/

#include <stdio.h>
#include <string.h>

void old()
{
    char str[128];
    printf("Enter str: ");
    scanf("%s", str);

    if (strcmp(str, "foo") == 0 || strcmp(str, "bar") == 0 ||
        strcmp(str, "baz") == 0) {
        printf("yes, compare\n");
    }
    else {
        printf("not compare\n");
    }
}

void new()
{
    char str[128];
    printf("Enter str: ");
    scanf("%s", str);
    const char *compare = "foo:bar:baz";

    if (strstr(compare, str) != NULL) {
        printf("yes, compare\n");
    }
    else {
        printf("not compare\n");
    }
}

int main()
{
    new();
    
    return 0;
}