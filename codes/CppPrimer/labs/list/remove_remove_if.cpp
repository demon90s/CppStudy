/*
    lst.remove(val)
    lst.remove_if(pred)

    调用 erase 删除掉与给定值相等（==）或令一元谓词为真的每个元素。
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
    std::list<int> lst {3, 6, 9, 11, 22, 20, 21};

    std::cout << "before remove odd numbers:";
    std::cout << lst << std::endl;

    lst.remove_if([](int i) {
        return i % 2 != 0;
    });

    std::cout << "after remove odd numbers:";
    std::cout << lst << std::endl;
}

int main()
{
    Test1();
    return 0;
}