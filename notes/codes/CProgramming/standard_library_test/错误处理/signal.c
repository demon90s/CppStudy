/*
    #include <signal.h>
    void (*signal(int sig, void (*func)(int)))(int);

    为信号 sig 安装一个信号处理函数 func ，在将来信号发生时调用。
    成功返回 func ，失败返回 SIG_ERR

    头提供了 两个预定义的处理函数：
    - SIG_DFL 按照默认的方式处理信号
    - SIG_IGN 忽略掉信号

    注意：信号由信号处理函数处理时，不可以被重复调用，如果此时又触发了信号，那么对
    该信号的处理要被重置为 SIG_DFL ,或以其他方式加锁。

*/

#ifdef __unix
#include <unistd.h>
#endif
#include <signal.h>
#include <stdio.h>

void handle_sigint(int sig)
{
    printf("catch signal %d, reset to default\n", sig);

    /* sleep for a while */
    #ifdef __unix
    sleep(3);
    #endif

    signal(SIGINT, SIG_DFL);
}

int main()
{
    signal(SIGINT, handle_sigint);

    while (1) {}

    return 0;
}