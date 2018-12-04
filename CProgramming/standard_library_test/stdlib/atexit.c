/*
    #include <stdlib.h>
    int atexit(void (*func)(void));

    注册一个回调函数 func ，在程序被 exit 或 main 函数返回时调用。

    成功返回0 ，失败返回非零值。
*/

#include <stdio.h>
#include <stdlib.h>

void bye()
{
    printf("bye~\n");
}

int main(int argc, char const *argv[])
{
    atexit(bye);
    
    return 0;
}
