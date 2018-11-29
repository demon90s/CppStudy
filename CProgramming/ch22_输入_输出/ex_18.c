/*
    (a) 请编写自己版本的 fgets 函数，使此函数的操作尽可能和实际的 fgets 函数相同。特别是一定要
        确保函数具有正确的返回值。为了避免和标准库发生冲突，请不要把自己编写的函数也命名为 fgets 。

    (b) 请编写自己版本的 fputs 函数，规则和要求和 (a) 一样。
*/

#include <stdio.h>

char* my_fgets(char* s, int n, FILE *stream)
{
    int ch;
    int count_read = 0;

    if (n <= 1) {
        s[0] = '\0';
        return s;
    }
    
    if (ferror(stream) || feof(stream))
            return NULL;

    do {
        ch = fgetc(stream);
        if (ferror(stream) || feof(stream))
            break;

        s[count_read++] = ch;
    } while (ch != '\n' && count_read < n - 1);

    s[count_read] = '\0';

    return s;
}

int my_fputs(const char *str, FILE *stream)
{
    if (!str || ferror(stream) || feof(stream)) return -1;

    printf("%s", str);
    return 1;
}

int main(int argc, char const *argv[])
{
    char buffer[8];
    while (my_fgets(buffer, 8, stdin)) {
        my_fputs(buffer, stdout);
    }

    return 0;
}
