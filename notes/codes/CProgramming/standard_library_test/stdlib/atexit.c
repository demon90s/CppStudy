/*
    #include <stdlib.h>
    int atexit(void (*func)(void));

    注册一个回调函数 func ，在程序被 exit 或 main 函数返回时调用。

    成功返回0 ，失败返回非零值。

    可以注册多个，调用顺序是后注册的先调用。
*/

#include <stdio.h>
#include <stdlib.h>

void bye()
{
    printf("bye,");
}

void see_you()
{
    printf(" see you~\n");
}

int main(int argc, char const *argv[])
{
    atexit(see_you);
    atexit(bye);
    
    return 0;
}
