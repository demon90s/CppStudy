#ifndef QUEUE_H
#define QUEUE_H

typedef int ValueType;
typedef enum { TRUE, FALSE } Bool;

/*
    初始化队列
*/
void init_queue();

/*
    销毁队列
*/
void destroy_queue();

/*
    向队列的末端加入一个数据。
*/
void queue_push(ValueType v);

/*
    从队列的开始删除一个数据。
*/
void queue_pop();

/*
    返回队列的第一个数据（不改变队列）。
*/
ValueType queue_first();

/*
    返回队列的末尾数据（不改变队列）。
*/
ValueType queue_last();

/*
    检查队列是否为空。
*/
Bool queue_is_empty();

#endif // QUEUE_H