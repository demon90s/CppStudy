/*
    编写下列函数：

    char* vstrcat(const char *first, ...);

    假设 vstrcat 函数最后一个参数必须是空指针（强制成 char* 类型）外，全部参数都是字符串。
    函数返回的指针指向动态分配的且含有参数拼接的字符串。如果没有足够的内存，那么 vstrcat 函数
    应该返回空指针。提示： vstrcat 函数必须遍历参数两次：一次用来确定返回字符串需要的内存数量，
    另一次用来把参数复制到字符串中。
*/

#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* vstrcat(const char *first, ...)
{
    size_t len;
    const char* p;
    char *str;
    va_list ap;

    /* allocate memory */
    {
        len = 0;
        p = first;
        va_start(ap, first);

        while (p != NULL) {
            len += strlen(p);
            p = va_arg(ap, const char*);
        }
        len += 1;

        str = malloc(sizeof(char) * len);
        if (!str) {
            return NULL;
            va_end(ap);
        }

        va_end(ap);
    }
    
    /* cat string */
    {
        len = 0;
        p = first;
        va_start(ap, first);

        while (p != NULL) {
            strcpy(str + len, p);
            len += strlen(p);
            p = va_arg(ap, const char*);
        }

        va_end(ap);
    }

    return str;
}

int main(int argc, char const *argv[])
{
    char *str = vstrcat("Hello", " World", "!!!", NULL);

    printf("%s\n", str);

    free(str);

    return 0;
}
