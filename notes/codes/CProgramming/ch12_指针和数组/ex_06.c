/*
 * 用指针变量 top_ptr 代替整型变量 top 来重新编写栈函数 make_empty、is_empty 和
 * is_full（10.2节）。
 */

#include <stdio.h>

#define STACK_SIZE 100

/* external variables */
int contents[STACK_SIZE];
int *top_ptr = contents;

void make_empty()
{
	top_ptr = contents;
}

int is_empty()
{
	return contents == top_ptr;
}

int is_full()
{
	return contents + STACK_SIZE == top_ptr;
}

void push(int i)
{
	if ( !is_full())
	{
		*top_ptr++ = i;
	}
}

int pop()
{
	if ( !is_empty())
	{
		return *--top_ptr;
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
