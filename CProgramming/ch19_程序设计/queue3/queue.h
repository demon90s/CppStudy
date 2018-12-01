#ifndef QUEUE_H
#define QUEUE_H

#define IMPL_BY_ARR

typedef int ValueType;

/* 数组定义的 Queue */
class Queue {
public:
    Queue();
    ~Queue();
    Queue(const Queue&) = delete;
    Queue& operator=(const Queue&) = delete;

    /*
    向队列的末端加入一个数据。
    */
    void push(ValueType v);

    /*
        从队列的开始删除一个数据。
    */
    void pop();

    /*
        返回队列的第一个数据（不改变队列）。
    */
    ValueType first();

    /*
        返回队列的末尾数据（不改变队列）。
    */
    ValueType last();

    /*
        检查队列是否为空。
    */
    bool is_empty();

private:
    int value_max_count;
    int value_count;
    ValueType *queue;
};

#endif // QUEUE_H