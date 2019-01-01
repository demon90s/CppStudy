/*
    编写 printf 函数的简写版，要求新函数只有一种转换说明 %d ，并且在第一个参数后边的所有参数都
    必须是 int 类型的。
*/

#include <stdarg.h>
#include <stdio.h>

int my_printf(const char* format, ...)
{
    int num_write = 0;
    int tmp;
    const char* p;
    va_list ap;

    p = format;
    va_start(ap, format);
    while (*p != '\0') {
        if (*p == '%') {
            p++;
            if (*p == 'd') {
                tmp = va_arg(ap, int);
                char buffer[1024];
                sprintf(buffer, "%d", tmp);
                fputs(buffer, stdout);
            }
            else {
                fputc('?', stdout);
            }
        }
        else {
            fputc(*p, stdout);
        }
        p++;
    }

    va_end(ap);

    return num_write;
}

int main(int argc, char const *argv[])
{
    my_printf("numbers: %d %d %d\n", 100, 42, 88);
    return 0;
}
