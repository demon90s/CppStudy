/*
    lst.reverse()

    反转 lst 中元素的顺序
*/

#include <list>
#include <iostream>

template<typename T>
std::ostream& operator<<(std::ostream &os, std::list<T> lst)
{
    for (const auto &item : lst)
        std::cout << " " << item;
    return os;
}

void Test1()
{
    std::list<int> lst {1, 2, 3, 4, 5};

    std::cout << "before reverse:\n";
    std::cout << lst << std::endl;

    lst.reverse();

    std::cout << "after reverse:\n";
    std::cout << lst << std::endl;
}

int main()
{
    Test1();
    return 0;
}