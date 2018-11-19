#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef IMPL_BY_ARR
/*
    用数组实现队列
*/

#define INIT_COUNT 2

/*
    初始化队列
*/
Queue* init_queue()
{
    printf("init_queue, queue implement by array\n");

    Queue *queue = malloc(sizeof(Queue));
    if (queue == NULL) {
        printf("init_queue failure: no space left!\n");
        exit(1);
    }

    queue->queue = malloc(sizeof(ValueType) * INIT_COUNT);
    queue->value_max_count = INIT_COUNT;
    queue->value_count = 0;
}

/*
    销毁队列
*/
void destroy_queue(Queue *queue)
{
    free(queue->queue);
    free(queue);
}

/*
    向队列的末端加入一个数据。
*/
void queue_push(Queue *queue, ValueType v)
{
    ValueType *queue_tmp;

    if (queue->value_count >= queue->value_max_count) {
        queue_tmp = realloc(queue->queue, sizeof(ValueType) * queue->value_max_count * 2);
        if (queue_tmp == NULL) {
            printf("queue_push failure: No space left!");
            return;
        }
        queue->queue = queue_tmp;
        queue->value_max_count *= 2;
    }

    queue->queue[queue->value_count++] = v;
}

/*
    从队列的开始删除一个数据。
*/
void queue_pop(Queue *queue)
{
    if (queue_is_empty(queue)) {
        printf("queue_pop failure: queue is empty!\n");
        return;
    }

    queue->value_count--;
    memcpy(queue->queue, queue->queue + 1, sizeof(ValueType) * queue->value_count);
}

/*
    返回队列的第一个数据（不改变队列）。
*/
ValueType queue_first(Queue *queue)
{
    static ValueType v_for_ret;

    if (queue_is_empty(queue)) {
        printf("queue_first failure: queue is empty!\n");
        return v_for_ret;
    }

    return queue->queue[0];
}

/*
    返回队列的末尾数据（不改变队列）。
*/
ValueType queue_last(Queue *queue)
{
    static ValueType v_for_ret;

    if (queue_is_empty(queue)) {
        printf("queue_last failure: queue is empty!\n");
        return v_for_ret;
    }

    return queue->queue[queue->value_count - 1];
}

/*
    检查队列是否为空。
*/
Bool queue_is_empty(Queue *queue)
{
    return queue->value_count == 0;
}

#endif /* IMPL_BY_ARR */

#ifdef IMPL_BY_LIST

/*
    初始化队列
*/
Queue* init_queue()
{
    printf("init_queue, queue implement by list\n");

    Queue *queue = malloc(sizeof(Queue));
    queue->first = NULL;
    queue->last = NULL;

    return queue;
}

/*
    销毁队列
*/
void destroy_queue(Queue *queue)
{
    struct node *tmp;
    while (queue->first != queue->last) {
        tmp = queue->first->next;
        free(queue->first);
        queue->first = tmp;
    }

    if (queue->last)
        free(queue->last);

    return;
}

/*
    向队列的末端加入一个数据。
*/
void queue_push(Queue *queue, ValueType v)
{
    struct node *tmp = malloc(sizeof(ValueType));
    if (tmp == NULL) {
        printf("queue_push failure: No space left!\n");
        return;
    }
    tmp->v = v;
    tmp->next = NULL;

    if (queue->last == NULL) {
        queue->first = queue->last = tmp;
    }
    else {
        queue->last->next = tmp;
        queue->last = tmp;
    }
}

/*
    从队列的开始删除一个数据。
*/
void queue_pop(Queue *queue)
{
    struct node *tmp;
    if (queue_is_empty(queue)) {
        printf("queue_pop failure: queue is empty!\n");
        return;
    }

    tmp = queue->first->next;
    free(queue->first);
    queue->first = tmp;
}

/*
    返回队列的第一个数据（不改变队列）。
*/
ValueType queue_first(Queue *queue)
{
    static ValueType v_to_ret;
    if (queue_is_empty(queue)) {
        printf("queue_first failure: queue is empty!\n");
        return v_to_ret;
    }

    return queue->first->v;
}

/*
    返回队列的末尾数据（不改变队列）。
*/
ValueType queue_last(Queue *queue)
{
    static ValueType v_to_ret;
    if (queue_is_empty(queue)) {
        printf("queue_last failure: queue is empty!\n");
        return v_to_ret;
    }

    return queue->last->v;
}

/*
    检查队列是否为空。
*/
Bool queue_is_empty(Queue *queue)
{
    return queue->first == NULL;
}

#endif /* IMPL_BY_LIST */