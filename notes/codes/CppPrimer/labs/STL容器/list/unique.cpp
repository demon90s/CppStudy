/*
    lst.unique()
    lst.unique(pred)

    调用 erase 删除同一个值的连续拷贝。第一个版本使用==; 第二个版本使用给定的二元谓词。

    Note:
    所谓同一个值的连续拷贝，举一个例子：
    1 1 2 2 3 4 5 3
    其中，1 1是同一个值的连续拷贝，2 2 也是，那么调用 unique 的结果应该是：
    1 2 3 4 5 3
*/

#include <iostream>
#include <list>

template<typename T>
std::ostream& operator<<(std::ostream &os, std::list<T> lst)
{
    for (const auto &item : lst)
        std::cout << " " << item;
    return os;
}

void Test1()
{
    std::list<int> lst {1, 1, 2, 2, 3, 4, 5, 3};

    std::cout << "before unique:\n";
    std::cout << lst << std::endl;

    lst.unique();

    std::cout << "after unique:\n";
    std::cout << lst << std::endl;
}

int main()
{
    Test1();
    return 0;
}