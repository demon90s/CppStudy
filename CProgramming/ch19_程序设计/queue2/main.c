#include <stdio.h>
#include "queue.h"

int main(int argc, char const *argv[])
{
    int i;

    Queue *queue = init_queue();

    for (i = 0; i < 10; i++) {
        queue_push(queue, i);
    }

    printf("first of queue: %d\n", queue_first(queue));
    printf("last of queue: %d\n", queue_last(queue));

    queue_pop(queue);
    printf("after pop, first of queue: %d, last of queue: %d\n", queue_first(queue), queue_last(queue));

    printf("before pop all, queue is empty? %s\n", queue_is_empty(queue) ? "yes" : "no");
    while (!queue_is_empty(queue)) {
        queue_pop(queue);
    }
    printf("after pop all, queue is empty? %s\n", queue_is_empty(queue) ? "yes" : "no");

    destroy_queue(queue);

    return 0;
}
