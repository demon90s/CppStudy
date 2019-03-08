/*
    void perror(const char *s)
    根据 errno 输出一段错误信息到 stderr ，信息内容是：
    "s: 错误描述\n"
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

    res = sqrt(d);  /* 不能对负数做平方根 */
    if (errno != 0) {
        perror("sqrt error, terminated");
        return 1;
    }
    else {
        printf("sqrt(%g) = %g\n", d, res);
    }

    return 0;
}