/*
    mind; sorting 算法需要 random access iterator ，vector, deque 等支持

    void sort(first, last)
    升序排序序列，不保证相等元素的顺序，使用 operator< 排序

    void sort(first, last, comp)
    使用二元比较函数 comp 比较排序

    复杂度：O(N·log(N)) 次比较
*/

#include <algorithm>
#include <iostream>
#include <vector>

void Test1()
{
    int arr[] = {1, 30, 21, 8, 100};

    // 升序
    std::sort(std::begin(arr), std::end(arr));
    for (auto i : arr)
        std::cout << i << " ";
    std::cout << std::endl;

    // 降序
    std::sort(std::begin(arr), std::end(arr), [](int a, int b) { return a > b; });
    for (auto i : arr)
        std::cout << i << " ";
    std::cout << std::endl;
}

void Test2()
{
    struct Foo {
        const char* name;
        int power;
    };

    std::vector<Foo> foo_list = {
        {"Diwen", 88},
        {"Miemie", 100},
        {"Lee", 20}
    };

    // 降序
    std::sort(foo_list.begin(), foo_list.end(), [](const Foo& lhs, const Foo& rhs){
        return lhs.power > rhs.power;
    });

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