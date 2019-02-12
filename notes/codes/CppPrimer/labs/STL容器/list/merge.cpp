/*
    lst.merge(lst2);
    lsg.merge(lst2, comp);

    将来自 lst2 的元素合并入 lst 。lst 和 lst2 都必须是有序的。
    元素将从 lst2 中删除。在合并之后， lst2 变为空。
    
    第一个版本使用<运算符，第二个版本使用给定的比较操作。
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
    std::list<int> lst2 {10, 20, 30};

    std::cout << "before merge: \n";
    std::cout << "lst:" << lst << std::endl;
    std::cout << "lst2:" << lst2 << std::endl;

    lst.merge(lst2);

    std::cout << "after merge: \n";
    std::cout << "lst:" << lst << std::endl;
    std::cout << "lst2:" << lst2 << std::endl;
}

int main()
{
    Test1();
    return 0;
}