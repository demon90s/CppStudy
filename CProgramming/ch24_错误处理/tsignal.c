/* Tests signals */

#include <signal.h>
#include <stdio.h>

void handler(int sig);
void raise_sig(void);

int main()
{
    void (*orig_handler)(int);

    printf("Installing handler for signal %d\n", SIGILL);
    orig_handler = signal(SIGILL, handler);
    raise_sig();

    printf("Changing handler to SIG_IGN\n");
    signal(SIGILL, SIG_IGN);
    raise_sig();

    printf("Restoring original handler\n");
    signal(SIGILL, orig_handler);
    raise_sig();

    /* Never reach here */
    printf("Program terminates normally\n");

    return 0;
}

void handler(int sig)
{
    printf("Handler called for signal %d\n", sig);
}

void raise_sig(void)
{
    raise(SIGILL);
}