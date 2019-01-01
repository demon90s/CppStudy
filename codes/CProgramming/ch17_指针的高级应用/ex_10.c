/*
    15.2 节描述的文件 stack.c 提供了在栈中进行整数排序的函数。在那一节中，栈是用数组实现的。请修改程序
    stack.c 从而使栈现在可以作为链表来存储。使用单独一个指向链表首节点的指针变量（栈
    “顶”）来替换变量 contents 和变量 top 。在 stack.c 中编写的函数要使用此指针。删除函数
    is_full , 用返回 TRUE (如果创建的节点可以获得内存)或 FALSE (如果创建的节点无法获得内存)
    的函数 push 来代替。 
*/

#include <stdlib.h>
#include <stdio.h>

typedef enum { TRUE, FALSE } Bool;

struct node {
    int value;
    struct node *next;
};

int is_empty(struct node *stack)
{
	return stack == NULL;
}

Bool push(struct node **stack, int i)
{
	struct node *node = malloc(sizeof(struct node));
    if (node == NULL) {
        return FALSE;
    }

    node->value = i;
    node->next = *stack;

    *stack = node;

    return TRUE;
}

int pop(struct node **stack)
{
	struct node *node;
    int v;

    node = *stack;
    *stack = node->next;

    v = node->value;
    free(node);

	return v;
}

void make_empty(struct node **stack)
{
    while (*stack) {
        pop(stack);
    }
}

//-------------------------------------

int main()
{
	int i;
    struct node *stack = NULL;

	for (i = 0; i < 10; ++ i)
	{
		push(&stack, i);
	}

    /* make_empty(&stack); */

	while ( !is_empty(stack))
	{
		printf("%d ", pop(&stack));
	}

	return 0;
}
