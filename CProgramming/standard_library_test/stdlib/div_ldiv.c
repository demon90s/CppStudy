/*
    #include <stdlib.h>
    div_t div(int numer, int denom);
    ldev_t ldiv(long int numer, long int denom);

    获取 numer 除以 denom 的结果，结果类型是一个 div_t 结构，它有俩成员：
    - quot - 商
    - rem - 余数
*/

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int numer, denom;
    div_t res;

    printf("Enter numer/denom: ");
    scanf("%d/%d", &numer, &denom);

    res = div(numer, denom);

    printf("Quatient: %d, Remainder: %d\n", res.quot, res.rem);
    
    return 0;
}
