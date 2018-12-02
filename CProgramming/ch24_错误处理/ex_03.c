/*
    给 SIGINT 编写一个信号处理函数，用来记录它被调用了多少次。要求处理函数必须忽略前两次发生
    的信号，并在第三次发生时终止程序（通过调用 exit ）。
*/

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void handle_sigint(int sig)
{
    static int call_times = 0;

    call_times++;
    printf("catch sigint %d times\n", call_times);

    if (call_times >= 3) {
        exit(1);
    }
}

int main()
{
    signal(SIGINT, handle_sigint);
    while (1) {}

    return 0;
}