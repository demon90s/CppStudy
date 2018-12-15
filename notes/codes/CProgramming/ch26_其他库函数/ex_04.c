/*
    解释说明下列语句的含义。假设 value 是 long int 型的变量， p 是 char* 型的变量。

    value = strtol(p, &p, 10);
*/

/*
    把 p 所指向的字符串转译成 long int ，如果消耗掉了所有的字符，那么 p 最终指向空字符。
*/

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    long int value;
    char *p = "12345";

    value = strtol(p, &p, 10);
    if (*p == '\0') {
        printf("%ld\n", value);
    }

    return 0;
}
