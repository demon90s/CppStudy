#include "stack.h"
#include <assert.h>

#define STACK_SIZE 100

/* external variables */
int contents[STACK_SIZE];
int top = 0;

void stack_make_empty()
{
	top = 0;
}

int stack_is_empty()
{
	return 0 == top;
}

PRIVATE int stack_is_full()
{
	return STACK_SIZE == top;
}

void stack_push(int i)
{
	assert(!stack_is_full());
	
	contents[top ++] = i;
}

int stack_pop()
{
	assert(!stack_is_empty());

	return contents[-- top];
}