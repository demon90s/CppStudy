/*
    使用包装函数的例子 vfprintf
*/

#include <stdarg.h>
#include <stdio.h>

int errorf(const char *format, ...)
{
    static int num_errors = 0;
    int n;
    va_list ap;

    num_errors++;
    fprintf(stderr, "*** Error %d: ", num_errors);
    va_start(ap, format);
    n = vfprintf(stderr, format, ap);
    va_end(ap);

    fprintf(stderr, "\n");
    return n;
}

int main(int argc, char const *argv[])
{
    errorf("Wow crush!");
    errorf("No No No");
    errorf("Oh dear...");

    return 0;
}
