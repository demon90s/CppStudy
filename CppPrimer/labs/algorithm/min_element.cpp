/*
    min_element
    寻找范围中最小的元素

    min_element(first, last)
    使用 operator< 比较元素

    min_element(fist, last, comp)
    使用二元比较函数 comp 比较元素

    返回范围中最小的元素的迭代器，若有多个最小的元素，返回首个这种元素的迭代器。范围为空返回 last 。
*/

#include <algorithm>
#include <vector>
#include <iostream>

void Test1()
{
    std::vector<int> vec {1, 2, 99, 33, 0};

    std::vector<int>::iterator min_it = std::min_element(vec.begin(), vec.end());
    if (min_it != vec.end())
    {
        std::cout << "min_element: " << *min_it << std::endl;
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

    auto min_it = std::min_element(std::begin(foo_list), std::end(foo_list), [](const Foo &lhs, const Foo &rhs) {
        return lhs.power < rhs.power;
    });

    if (min_it != std::end(foo_list))
    {
        std::cout << "min_element: " << min_it->number << std::endl;
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
