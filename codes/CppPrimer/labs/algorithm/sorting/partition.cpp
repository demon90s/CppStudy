/*
    bidit partition(first, last, unary)

    重新排序 [first, last) 中的元素，使得对于谓词 unary 为 true 的元素在前面一部分，而为 false 的位于后面一部分。

    返回排序后前一部分最后一个元素的后一个位置的迭代器。
*/

#include <algorithm>
#include <vector>
#include <iostream>

void Test1()
{
    std::vector<int> vec { 6, 3, 1, 7, 2, 10 };

    // 大于5的放前面一部分
    auto it = std::partition(vec.begin(), vec.end(), [](int i){ return i > 5; });

    // test return value
    std::cout << std::distance(vec.begin(), it) << " " << *it << std::endl;

    for (auto i : vec)
        std::cout << i << " ";
    std::cout << std::endl;
}

void Test2()
{
    struct Foo {
        const char *name;
        int power;
    };

    std::vector<Foo> vec {
        {"MieMie", 1000},
        {"Diwen", 200},
        {"Lee", 122},
        {"Dog", 30},
        {"Bug", 2000}
    };

    // power 大于等于1000的排在前面
    std::partition(vec.begin(), vec.end(), [](const Foo &item) { return item.power >= 1000; });

    for (const auto &item : vec)
        std::cout << item.name << " " << item.power << std::endl;
}

int main()
{
    //Test1();
    Test2();

    return 0;
}