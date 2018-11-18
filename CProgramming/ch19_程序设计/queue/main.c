#include <stdio.h>
#include "queue.h"

int main(int argc, char const *argv[])
{
    int i;

    init_queue();

    for (i = 0; i < 10; i++) {
        queue_push(i);
    }

    printf("first of queue: %d\n", queue_first());
    printf("last of queue: %d\n", queue_last());

    queue_pop();
    printf("after pop, first of queue: %d, last of queue: %d\n", queue_first(), queue_last());

    printf("before pop all, queue is empty? %s\n", queue_is_empty() ? "yes" : "no");
    while (!queue_is_empty()) {
        queue_pop();
    }
    printf("after pop all, queue is empty? %s\n", queue_is_empty() ? "yes" : "no");

    destroy_queue();

    return 0;
}
