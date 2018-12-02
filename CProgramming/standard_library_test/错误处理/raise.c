/*
    #include <signal.h>
    int raise(int sig);
    产生一个信号 sig 。
    返回0代表成功，否则失败。
*/

#include <signal.h>
#include <stdio.h>

void handle_sigint()
{
    printf("Catch sigint, abort\n");
    raise(SIGABRT);
}

int main()
{
    signal(SIGINT, handle_sigint);

    while (1);

    return 0;
}