/*
    编写一个 memset 函数的调用，将一个空字符结尾的字符串s的最后n个字符替换为'!'字符。
*/

#include <stdio.h>
#include <string.h>

int main()
{
    char str[] = "hello world";
    int n;

    printf("str is: %s\n", str);
    printf("Enter n: ");
    scanf("%d", &n);

    if (n <= 0 || n > strlen(str)) {
        printf("n's valid range: [%d, %d]\n", 1, strlen(str));
        return 1;
    }

    memset(str + strlen(str) - n, '!', n);
    printf("str now is: %s\n", str);

    return 0;
}