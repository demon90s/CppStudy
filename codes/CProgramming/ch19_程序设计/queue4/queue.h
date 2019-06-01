#ifndef QUEUE_H
#define QUEUE_H

#include <cstdlib>
#include <cstdio>
#include <cstring>

#define IMPL_BY_ARR
#define INIT_COUNT 2

/* 数组定义的 Queue */
template<typename ValueType>
class Queue {
public:
    Queue() : value_max_count(0), value_count(0), queue(nullptr)
    {
		queue = new ValueType[INIT_COUNT]();
        if (queue == NULL) {
            printf("init_queue failure: no space left!\n");
            exit(1);
        }
        value_max_count = INIT_COUNT;
        value_count = 0;
    }

    ~Queue()
    {
		delete[] queue;
    }

    /*
        向队列的末端加入一个数据。
    */
    void push(ValueType v)
    {
        ValueType *tmp;

        if (value_count >= value_max_count) {
            tmp = new ValueType[value_max_count * 2]();
			if (!tmp) {
				printf("push failure: No space left!\n");
				return;
			}
			for (int i = 0; i < value_max_count; ++i) {
				*(tmp + i) = *(queue + i);
			}

			delete[] queue;
            queue = tmp;
            value_max_count *= 2;
        }

        *(queue + value_count) = v;
		value_count++;
    }

    /*
        从队列的开始删除一个数据。
    */
    void pop()
    {
        if (is_empty()) {
            printf("pop failure: queue is empty!\n");
            return;
        }

		for (int i = 0; i < value_count - 1; ++i)
		{
			*(queue + i) = *(queue + i + 1);
		}
		value_count--;
    }

    /*
        返回队列的第一个数据（不改变队列）。
    */
    ValueType first()
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
    ValueType last()
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
    bool is_empty()
    {
        return value_count == 0;
    }

private:
    int value_max_count;
    int value_count;
    ValueType *queue;
};

#endif // QUEUE_H