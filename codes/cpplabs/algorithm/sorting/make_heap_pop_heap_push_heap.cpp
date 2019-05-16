/*
    最大堆，是一种二叉堆，根结点的键值是所有堆结点键值中最大者的堆。

    void make_heap(first, last);
    void make_heap(first, last, comp);

    在范围 [first, last) 中构造最大堆。

    void pop_heap(first, last);
    void pop_heap(first, last, comp);

    交换在位置 first 的值和在位置 last-1 的值，令范围 [first, last-1) 变成最大堆。

    void push_heap(first, last);
    void push_heap(first, last, comp);

    插入位于位置 last-1 的元素到范围 [first, last) 所定义的最大堆中。

    默认采用 operator< 比较元素，或可用可调用对象 comp 。
*/

#include <vector>
#include <algorithm>
#include <iostream>

void Test1()
{
    std::vector<int> v {3, 6, 1, 29, 1, 22};

    std::cout << "initially, v:";
    for (auto i : v)
        std::cout << " " << i;
    std::cout << std::endl;

    std::make_heap(v.begin(), v.end());
    std::cout << "after make_heap, v:";
    for (auto i : v)
        std::cout << " " << i;
    std::cout << std::endl;

    std::pop_heap(v.begin(), v.end());
    std::cout << "after pop_heap, v:";
    for (auto i : v)
        std::cout << " " << i;
    std::cout << std::endl;

    v.pop_back();
    std::cout << "after pop_back, v:";
    for (auto i : v)
        std::cout << " " << i;
    std::cout << std::endl;

    v.push_back(100);
    std::cout << "after push_back, v:";
    for (auto i : v)
        std::cout << " " << i;
    std::cout << std::endl;

    std::push_heap(v.begin(), v.end());
    std::cout << "after push_heap, v:";
    for (auto i : v)
        std::cout << " " << i;
    std::cout << std::endl;
}

int main()
{
    Test1();

    return 0;
}