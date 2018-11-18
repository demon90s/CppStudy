#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    用数组实现队列
*/

#define INIT_COUNT 2

static int value_max_count = INIT_COUNT;
static int value_count = 0;
static ValueType *queue;

/*
    初始化队列
*/
void init_queue()
{
    printf("init_queue, queue implement by array\n");
    queue = malloc(sizeof(ValueType) * value_max_count);
}

/*
    销毁队列
*/
void destroy_queue()
{
    free(queue);
}

/*
    向队列的末端加入一个数据。
*/
void queue_push(ValueType v)
{
    ValueType *queue_tmp;

    if (value_count >= value_max_count) {
        queue_tmp = realloc(queue, sizeof(ValueType) * value_max_count * 2);
        if (queue_tmp == NULL) {
            printf("queue_push failure: No space left!");
            return;
        }
        queue = queue_tmp;
        value_max_count *= 2;
    }

    queue[value_count++] = v;
}

/*
    从队列的开始删除一个数据。
*/
void queue_pop()
{
    if (queue_is_empty()) {
        printf("queue_pop failure: queue is empty!\n");
        return;
    }

    value_count--;
    memcpy(queue, queue + 1, sizeof(ValueType) * value_count);
}

/*
    返回队列的第一个数据（不改变队列）。
*/
ValueType queue_first()
{
    static ValueType v_for_ret;

    if (queue_is_empty()) {
        printf("queue_first failure: queue is empty!\n");
        return v_for_ret;
    }

    return queue[0];
}

/*
    返回队列的末尾数据（不改变队列）。
*/
ValueType queue_last()
{
static ValueType v_for_ret;

    if (queue_is_empty()) {
        printf("queue_last failure: queue is empty!\n");
        return v_for_ret;
    }

    return queue[value_count - 1];
}

/*
    检查队列是否为空。
*/
Bool queue_is_empty()
{
    return value_count == 0;
}