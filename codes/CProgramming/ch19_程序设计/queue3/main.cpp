#include <stdio.h>
#include "queue.h"

int main(int argc, char const *argv[])
{
    int i;

    Queue queue;

    for (i = 0; i < 10; i++) {
        queue.push(i);
    }

    printf("first of queue: %d\n", queue.first());
    printf("last of queue: %d\n", queue.last());

    queue.pop();
    printf("after pop, first of queue: %d, last of queue: %d\n", queue.first(), queue.last());

    printf("before pop all, queue is empty? %s\n", queue.is_empty() ? "yes" : "no");
    while (!queue.is_empty()) {
        queue.pop();
    }
    printf("after pop all, queue is empty? %s\n", queue.is_empty() ? "yes" : "no");

    return 0;
}
