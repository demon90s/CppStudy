/*
    strcasecmp(const char *s1, const char *s2);

    比较字符串, 逻辑和 strcmp 一样, 只不过忽略掉大小写
*/

#include <stdio.h>
#include <string.h>

int main()
{
    const char *str = "hello";

    if (0 == strcasecmp(str, "hello"))
        printf("'hello' == 'hello'\n");

    if (0 == strcasecmp(str, "heLLo"))
        printf("'hello' == 'heLLo'\n");

    return 0;
}