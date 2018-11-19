#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PUBLIC /* empty */
#define PRIVATE static

struct node {
    ValueType v;
    struct node *next;
};

static struct node *first;
static struct node *last;

/*
    初始化队列
*/
PUBLIC void init_queue()
{
    printf("init_queue, queue implement by list\n");
    return;
}

/*
    销毁队列
*/
PUBLIC void destroy_queue()
{
    struct node *tmp;
    while (first != last) {
        tmp = first->next;
        free(first);
        first = tmp;
    }

    if (last)
        free(last);

    return;
}

/*
    向队列的末端加入一个数据。
*/
PUBLIC void queue_push(ValueType v)
{
    struct node *tmp = malloc(sizeof(ValueType));
    if (tmp == NULL) {
        printf("queue_push failure: No space left!\n");
        return;
    }
    tmp->v = v;
    tmp->next = NULL;

    if (last == NULL) {
        first = last = tmp;
    }
    else {
        last->next = tmp;
        last = tmp;
    }
}

/*
    从队列的开始删除一个数据。
*/
PUBLIC void queue_pop()
{
    struct node *tmp;
    if (queue_is_empty()) {
        printf("queue_pop failure: queue is empty!\n");
        return;
    }

    tmp = first->next;
    free(first);
    first = tmp;
}

/*
    返回队列的第一个数据（不改变队列）。
*/
PUBLIC ValueType queue_first()
{
    static ValueType v_to_ret;
    if (queue_is_empty()) {
        printf("queue_first failure: queue is empty!\n");
        return v_to_ret;
    }

    return first->v;
}

/*
    返回队列的末尾数据（不改变队列）。
*/
PUBLIC ValueType queue_last()
{
    static ValueType v_to_ret;
    if (queue_is_empty()) {
        printf("queue_last failure: queue is empty!\n");
        return v_to_ret;
    }

    return last->v;
}

/*
    检查队列是否为空。
*/
PUBLIC Bool queue_is_empty()
{
    return first == NULL;
}