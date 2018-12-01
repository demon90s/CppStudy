#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INIT_COUNT 2

Queue::Queue() : value_max_count(0), value_count(0), queue(nullptr)
{
    queue = (ValueType*)malloc(sizeof(ValueType) * INIT_COUNT);
    if (queue == NULL) {
        printf("init_queue failure: no space left!\n");
        exit(1);
    }
    value_max_count = INIT_COUNT;
    value_count = 0;
}

Queue::~Queue()
{
    free(queue);
}

/*
    向队列的末端加入一个数据。
*/
void Queue::push(ValueType v)
{
    ValueType *tmp;

    if (value_count >= value_max_count) {
        tmp = (ValueType*)realloc(queue, sizeof(ValueType) * value_max_count * 2);
        if (tmp == NULL) {
            printf("push failure: No space left!");
            return;
        }
        queue = tmp;
        value_max_count *= 2;
    }

    queue[value_count++] = v;
}

/*
    从队列的开始删除一个数据。
*/
void Queue::pop()
{
    if (is_empty()) {
        printf("pop failure: queue is empty!\n");
        return;
    }

    value_count--;
    memcpy(queue, queue + 1, sizeof(ValueType) * value_count);
}

/*
    返回队列的第一个数据（不改变队列）。
*/
ValueType Queue::first()
{
    static ValueType v_for_ret;

    if (is_empty()) {
        printf("first failure: queue is empty!\n");
        return v_for_ret;
    }

    return queue[0];
}

/*
    返回队列的末尾数据（不改变队列）。
*/
ValueType Queue::last()
{
    static ValueType v_for_ret;

    if (is_empty()) {
        printf("last failure: queue is empty!\n");
        return v_for_ret;
    }

    return queue[value_count - 1];
}

/*
    检查队列是否为空。
*/
bool Queue::is_empty()
{
    return value_count == 0;
}