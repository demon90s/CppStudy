#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

int main()
{
    int i;
    Stack *stack = stack_init();

    for (i = 0; i < 10; i++)
        stack_push(stack, i);

    /* stack_make_empty(stack); */
    while (!stack_is_empty(stack)) {
        printf("pop: %d\n", stack_pop(stack));
    }

    stack_destroy(stack);

    return 0;
}