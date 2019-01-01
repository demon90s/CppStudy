/*
    重新编写 max_int 函数，要求不再把传递整数作为第一个参数，我们必须采用0作为最后一个
    参数。提示： max_int 函数必须至少有一个“正常”的参数，所以不能把参数n移走，相反假设它是
    要比较的数之一。
*/

#include <stdarg.h>
#include <stdio.h>

int max_int(int n, ...)
{
    va_list ap;
    int i, current = n, largest;

    va_start(ap, n);
    largest = current;
    while (current != 0) {
        current = va_arg(ap, int);
        if (current > largest)
            largest = current;
    }

    va_end(ap);
    return largest;
}

int main(int argc, char const *argv[])
{
    printf("max of {1, 2, 42, 10, 9}: %d\n", max_int(1, 2, 42, 10, 9, 0));
    
    return 0;
}
