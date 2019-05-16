/*
    allocator 用于将对象的内存的分配, 构造, 释放分开的方法.

    对象的创建包含了内存分配和构造的过程, 对象的销毁包括了析构和内存释放的过程

    new 和 delete 组合了这两个步骤, 有时候我们需要把这个步骤分开.
*/

/*
    // 操作
    allocator<T> a      // 创建一个用于创建类型T对象的 allocator

    a.allocate(n)       // 分配n个未初始化的内存, 返回其首地址
    a.deallocate(p, n)  // 释放掉p开始的内存, 其长度为n, 所有内存必须已被析构
    a.construct(p, args)// 在未构造的内存p上面用参数 args 执行对象的构造函数
    a.destroy(p)        // 对已构造的内存p上的对象执行析构函数
*/

#include <memory>   // for allocator
#include <string>
#include <iostream>

using namespace std;

int main()
{
    allocator<string> str_alloc;

    string* const head = str_alloc.allocate(10);            // 申请10个string的内存空间

    // 构造几个string
    string *p = head;
    str_alloc.construct(p++, "hello");
    str_alloc.construct(p++, 3, 'X');

    // 打印验证
    for (string *q = head; q != p; q++) {
        std::cout << *q << std::endl;
    }

    // 析构掉已构造的string
    while (p != head) {
        str_alloc.destroy(--p);
    }

    // 释放掉所有内存
    str_alloc.deallocate(head, 10);

    return 0;
}

