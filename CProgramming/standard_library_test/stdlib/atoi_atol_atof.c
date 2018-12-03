/*
    #include <stdlib.h>
    int atoi(const char *s);
    将 s 转换成 int

    long int atol(const char *s);
    将 s 转换成 long int

    double atoi(const char *s);
    将 s 转换成 double

    每个函数都会跳过空白字符，并且把后续字符作为数的一部分，在第一个不是数的部分的字符处停止。

    若转换的值超过了返回类型的范围，返回值未定义。若无法进行转换，返回0 。
*/

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    printf("%d\n", atoi("42"));
    printf("%f\n", atof("3.14"));
    printf("%ld\n", atol("88888"));
    
    return 0;
}
