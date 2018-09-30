#include <stdio.h>

#define STACK_SIZE 100

/* external variables */
int contents[STACK_SIZE];
int top = 0;

void make_empty()
{
	top = 0;
}

int is_empty()
{
	return 0 == top;
}

int is_full()
{
	return STACK_SIZE == top;
}

void push(int i)
{
	if ( !is_full())
	{
		contents[top ++] = i;
	}
}

int pop()
{
	if ( !is_empty())
	{
		return contents[-- top];
	}

	return -1;
}

//-------------------------------------

int main()
{
	int i;

	for (i = 0; i < 10; ++ i)
	{
		push(i);
	}

	while ( !is_empty())
	{
		printf("%d\n", pop());
	}

	return 0;
}
