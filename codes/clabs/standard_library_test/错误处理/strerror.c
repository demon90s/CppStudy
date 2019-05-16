/*
    #include <string.h>
    char* strerror(int errno);

    根据 errno 返回其错误描述。
*/

#include <stdio.h>
#include <math.h>
#include <errno.h>
#include <string.h>

int main()
{
    double d;
    double res;

    printf("Enter d: ");
    scanf("%lf", &d);

    res = sqrt(d);      /* 不能对负数做平方根 */
    if (errno != 0) {
        fprintf(stderr, "sqrt error: %s\n", strerror(errno));
        return 1;
    }
    else {
        printf("sqrt(%g) = %g\n", d, res);
    }

    return 0;
}