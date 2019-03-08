/*
    errno
    这是一个全局的变量，存储一个错误代码，如果非0，表示上一次的某个函数调用有错误发生。

    虽然在程序刚开始的时候 errno 的值为0，但有可能在随后的函数调用中已经被改动了。库
    函数不会将 errno 清零，这是程序的责任。
*/

#include <math.h>
#include <stdio.h>
#include <errno.h>

int main()
{
    double d;
    double res;

    printf("Enter d: ");
    scanf("%lf", &d);

    res = sqrt(d);      /* 不能对负数做平方根 */
    if (errno != 0) {
        fprintf(stderr, "errno[%d], sqrt error, terminated.\n", errno);
        return 1;
    }
    else {
        printf("sqrt(%g) = %g\n", d, res);
    }

    return 0;
}