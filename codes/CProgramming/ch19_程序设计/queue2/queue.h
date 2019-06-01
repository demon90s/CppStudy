#ifndef QUEUE_H
#define QUEUE_H

/* #define IMPL_BY_ARR */
#define IMPL_BY_LIST

typedef int ValueType;
typedef enum { TRUE, FALSE } Bool;

/* 数组定义的 Queue */
#ifdef IMPL_BY_ARR
struct queue {
    int value_max_count;
    int value_count;
    ValueType *queue;
};
#endif

/* 链表定义的 Queue */
#ifdef IMPL_BY_LIST
struct node {
    ValueType v;
    struct node *next;
};

struct queue {
    struct node *first;
    struct node *last;
};
#endif

typedef struct queue Queue;

/*
    初始化队列
*/
Queue* init_queue();

/*
    销毁队列
*/
void destroy_queue(Queue *queue);

/*
    向队列的末端加入一个数据。
*/
void queue_push(Queue *queue, ValueType v);

/*
    从队列的开始删除一个数据。
*/
void queue_pop(Queue *queue);

/*
    返回队列的第一个数据（不改变队列）。
*/
ValueType queue_first(Queue *queue);

/*
    返回队列的末尾数据（不改变队列）。
*/
ValueType queue_last(Queue *queue);

/*
    检查队列是否为空。
*/
Bool queue_is_empty(Queue *queue);

#endif // QUEUE_H