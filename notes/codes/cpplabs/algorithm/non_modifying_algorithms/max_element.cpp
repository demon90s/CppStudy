/*
    max_element
    寻找范围中最大的元素

    max_element(first, last)
    使用 operator< 比较元素

    max_element(fist, last, comp)
    使用二元比较函数 comp 比较元素

    返回范围中最大的元素的迭代器，若有多个最大的元素，返回首个这种元素的迭代器。范围为空返回 last 。
*/

#include <algorithm>
#include <vector>
#include <iostream>

void Test1()
{
    std::vector<int> vec {1, 2, 99, 33, 0};

    std::vector<int>::iterator max_it = std::max_element(vec.begin(), vec.end());
    if (max_it != vec.end())
    {
        std::cout << "max_element: " << *max_it << std::endl;
    }
    else
    {
        std::cout << "range is empty" << std::endl;
    }
}

void Test2()
{
    struct Foo {
        int number;
        float power;
    };

    Foo foo_list[] = {
        {1, 80.4f},
        {2, 60.22f},
        {3, 90.0f},
        {4, 70.89f}
    };

    auto max_it = std::max_element(std::begin(foo_list), std::end(foo_list), [](const Foo &lhs, const Foo &rhs) {
        return lhs.power < rhs.power;
    });

    if (max_it != std::end(foo_list))
    {
        std::cout << "max_element: " << max_it->number << std::endl;
    }
    else
    {
        std::cout << "range is empty" << std::endl;
    }
}

int main(int argc, char const *argv[])
{
    Test1();
    Test2();
    return 0;
}
