/*
    int vprintf(const char *format, va_list vlist);
    
    用于编写包装函数，此函数带有可变实参列表，然后将它传递给 vprintf 。
*/

#include <stdarg.h>
#include <stdio.h>

void WrapPrint(const char* prefix, const char *format, ...)
{
    printf("%s ", prefix);

    va_list vlist;
    va_start(vlist, format);
    vprintf(format, vlist);
    va_end(vlist);

    printf("\n");
}

int main(int argc, char const *argv[])
{
    WrapPrint("Wow that's cool", "%s", "of course!");
    return 0;
}
