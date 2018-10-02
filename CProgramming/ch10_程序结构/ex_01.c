/*
 * 修改栈示例使它存储字符而不是整数。接下来，增加 main 函数，用来要求用户输入一串圆括号或大
 * 括号，然后指出它们是否正确嵌套：
 *
 * Enter parenteses and/or braces: {{}{}}
 * Parenteses/braces are nested property
 *
 * 提示略。
 */

#include <stdio.h>

#define STACK_SIZE 100
#define true 1
#define false 0

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
	int c, tmp;
	int check_succ;
	
	printf("Enter parenteses and/or braces: ");
	
	check_succ = true;
	while ((c = getchar()) != '\n') {
		if (c == '{' || c == '(') {
			push(c);
			continue;
		}
		else if (c == '}' || c == ')') {
			tmp = pop(c);
			if (c == '}' && tmp != '{') {
				check_succ = false;
				break;
			}
			else if (c == ')' && tmp != '(') {
				check_succ = false;
				break;
			}
		}
		else {
			check_succ = false;
			break;
		}
	}

	if (!is_empty()) check_succ = false;

	if (check_succ) {
		printf("Parenteses/braces are nested property");
	}
	else {
		printf("Parenteses/braces are not nested property");
	}

	return 0;
}
