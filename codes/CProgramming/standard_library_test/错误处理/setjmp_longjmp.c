/*
    #include <setjmp.h>
    int setjmp(jmp_buf env);
    void longjmo(jmp_buf env, int val);

    setjmp 标记程序中的一个位置，保存位置信息到 env ，随后使用 longjmp ，并利用此 env 跳转到该位置，
    随后再次调用 setjmp。
    setjmp 在第一次调用的时候（标记的时候），返回。后随后被跳转的时候，返回的是 val 。

    书中介绍，此函数主要用于错误的调试。
*/

#include <setjmp.h>
#include <stdio.h>

static jmp_buf env;

void f1();
void f2();

int main()
{
    int ret;

    ret = setjmp(env);
    printf("setjmp returned %d\n", ret);
    if (ret != 0) {
        printf("Program terminates: longjmp called\n");
        return 0;
    }
    f1();

    /* Never reach here */
    printf("Program terminates normally\n");

    return 0;
}

void f1()
{
    printf("f1 begins\n");
    f2();
    printf("f1 returns\n"); /* Never reach here */
}

void f2()
{
    printf("f2 begins\n");
    longjmp(env, 1);
    printf("f2 returns\n"); /* Never reach here */
}