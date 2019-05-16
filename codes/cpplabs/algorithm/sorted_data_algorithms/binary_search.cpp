/*
    必须要求序列以排序。

    bool binary_search(first, last, value);
    bool binary_search(first, last, value, comp);

    检查等价于 value 的元素是否出现于范围 [first, last) 中。

    默认版本使用 operator< 比较元素，或使用比较函数 comp 。
*/

#include <iostream>
#include <vector>
#include <algorithm>

void Test1()
{
    std::vector<int> v {3, 5, 7, 10, 20};

    bool exist = binary_search(v.begin(), v.end(), 6);

    std::cout << "6 exist? " << (exist ? "yes" : "no") << std::endl;
}

struct Foo {
    int id;
    const char *name;
};
bool operator<(const Foo &lhs, const Foo &rhs)
{
    return lhs.id < rhs.id;
}

void Test2()
{
    std::vector<Foo> foo_list = {
      { 1, "Diwen" },
      { 2, "Lee" },
      { 3, "Miemie" }  
    };

    std::sort(foo_list.begin(), foo_list.end());

    Foo foo {3, "None"};
    bool exist = binary_search(foo_list.begin(), foo_list.end(), foo);

    std::cout << "id 3 exist? " << (exist ? "yes" : "no") << std::endl;
}

int main()
{
    //Test1();
    Test2();

    return 0;
}