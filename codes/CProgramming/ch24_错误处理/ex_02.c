/*
    (a) 编写一个名为 try_math_fnc 的“包装”函数，用来调用数学函数（假定有一个 double 类型的
        参数，并返回一个 double 类型的值），然后检测调用是否成功。下面是使用 try_math_fnc 函数的
        例子：

        y = try_math_fnc(sqrt, x, "Error in call of sqrt");

        如果调用 sqrt(x) 成功， try_math_fnc 返回 sqrt 函数计算的结果。如果调用失败， try_math_fnc
        需要调用 perror 显示消息 Error in call of sqrt ，然后调用 exit 函数终止程序。

    (b) 编写一个与 try_math_fnc 具有相同的效果的宏，但是要求使用函数的名字来构造出错消息：

        y = TRY_MATH_FNC(sqrt, x);

        如果调用 sqrt 失败，显示的出错消息应该是 "Error in call of sqrt"。提示：让 TRY_MATH_FNC
        调用 try_math_fnc 。
*/

#include <math.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

#define TRY_MATH_FNC(func, param)\
    try_math_fnc((func), (param), "Error in call of " #func)

typedef double (*pFnc)(double);

double try_math_fnc(pFnc func, double param, const char* error_desc)
{
    double res = func(param);
    if (errno != 0) {
        printf("%s\n", error_desc);
        exit(1);
    }

    return res;
}

int main()
{
    double d;
    printf("Enter d: ");
    scanf("%lf", &d);

    //printf("%f\n", try_math_fnc(sqrt, d, "Error in call of sqrt"));
    printf("%f\n", TRY_MATH_FNC(sqrt, d));
    return 0;
}