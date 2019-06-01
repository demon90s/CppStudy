#include <stdarg.h>
#include <stdio.h>

int max_int(int n, ...)
{
    va_list ap;
    int i, current, largest;

    va_start(ap, n);
    largest = va_arg(ap, int);

    for (i = 1; i < n; i++) {
        current = va_arg(ap, int);
        if (current > largest)
            largest = current;
    }

    va_end(ap);
    return largest;
}

int main()
{
    printf("%d\n", max_int(3, 10, 5, 20));

    return 0;
}