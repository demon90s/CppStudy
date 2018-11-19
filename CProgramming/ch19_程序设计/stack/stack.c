#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#ifdef IMPL_BY_ARR
Stack* stack_init()
{
	printf("stack_init with array impl\n");
	Stack *stack = malloc(sizeof(Stack));
	assert(stack != NULL);
	stack->top = 0;
	stack->size = 2;	/* init size */
	stack->values = malloc(sizeof(ValueType) * stack->size);
	assert(stack->values != NULL);
	return stack;
}

void stack_destroy(Stack *stack)
{
	free(stack->values);
	free(stack);
}

void stack_make_empty(Stack *stack)
{
	stack->top = 0;
}

int stack_is_empty(Stack *stack)
{
	return 0 == stack->top;
}

void stack_push(Stack *stack, ValueType i)
{
	ValueType *tmp;
	if (stack->top == stack->size) {
		tmp = realloc(stack->values, sizeof(ValueType) * stack->size * 2);
		if (tmp == NULL) {
			printf("stack_push failure: No space left\n");
			return;
		}
		stack->values = tmp;
	}
	stack->values[stack->top++] = i;
}

ValueType stack_pop(Stack *stack)
{
	assert(!stack_is_empty(stack));
	return stack->values[--stack->top];
}
#endif /* IMPL_BY_ARR */

#ifdef IMPL_BY_LIST
Stack* stack_init()
{
	printf("stack_init with list impl\n");
	Stack *stack = malloc(sizeof(Stack));
	assert(stack != NULL);
	stack->header = NULL;
	return stack;
}

void stack_destroy(Stack *stack)
{
	struct node *tmp_node;
	while (stack->header) {
		tmp_node = stack->header->next;
		free(stack->header);
		stack->header = tmp_node;
	}
	free(stack);
}

void stack_make_empty(Stack *stack)
{
	struct node *tmp_node;
	while (stack->header) {
		tmp_node = stack->header->next;
		free(stack->header);
		stack->header = tmp_node;
	}
}

int stack_is_empty(Stack *stack)
{
	return stack->header == NULL;
}

void stack_push(Stack *stack, ValueType v)
{
	struct node *tmp_node = malloc(sizeof(ValueType));
	tmp_node->value = v;
	tmp_node->next = stack->header;
	stack->header = tmp_node;
}

ValueType stack_pop(Stack *stack)
{
	struct node *tmp_node;
	ValueType ret;
	assert(!stack_is_empty(stack));
	
	tmp_node = stack->header;
	ret = stack->header->value;
	stack->header = stack->header->next;
	free(tmp_node);

	return ret;
}

#endif /* IMPL_BY_LIST */