/*
    void partial_sort(first, middle, last);
    void partial_sort(first, middle, last, comp);

    重排元素，使得范围 [first, middle) 含有 [first, last) 中排序好的 middle - first 个元素。

    默认使用 operator< 比较元素，可以提供 comp 作比较函数。
    不保证相等元素的顺序，余下的范围中的元素顺序未指定。
*/

#include <vector>
#include <iostream>
#include <algorithm>

void Test1()
{
    std::vector<int> vec { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    // 对前五个元素执行降序排序
    std::partial_sort(vec.begin(), vec.begin() + 5, vec.end(), std::greater<int>());

    for (auto i : vec)
        std::cout << i << " ";
    std::cout << std::endl;
}

struct Foo {
    const char* name;
    int power;
};
bool operator<(const Foo &lhs, const Foo &rhs)
{
    return lhs.power > rhs.power;
}

void Test2()
{
    std::vector<Foo> foo_list = {
        {"Diwen", 88},
        {"Miemie", 100},
        {"Lee", 20},
        {"Bug", 1000},
        {"Noob", 1},
        {"Cow", 66}
    };

    // power 前三排序
    std::partial_sort(foo_list.begin(), foo_list.begin() + 3, foo_list.end());

    for (const auto &item : foo_list) {
        std::cout << item.name << " " << item.power << std::endl;
    }
}

int main()
{
    //Test1();
    Test2();
    return 0;
}