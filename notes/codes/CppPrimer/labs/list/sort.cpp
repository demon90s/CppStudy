/*
    lst.sort()
    lst.sort(comp)

    使用<或给定的比较操作排序元素。
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
    std::list<int> lst {9, 8, 7, 1, 2, 3};

    std::cout << "before sort:\n";
    std::cout << lst << std::endl;

    lst.sort();

    std::cout << "after sort:\n";
    std::cout << lst << std::endl;
}

int main()
{
    Test1();
    return 0;
}