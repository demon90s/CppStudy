/*
    std::adjacent_find
    在范围[first, last) 中搜索两个相继等同的元素。

    adjacent_find(first, last)
    用 operator== 比较元素

    adjacent_find(first, last, binary_predicate)
    用二元谓词比较元素
    
    返回指向首对等同元素的首个元素的迭代器，即首个满足 `*it == *(it + 1)` 或 `pred(*it, *(it + 1)) == true` 的迭代器 it
    若找不到，返回 last 。
*/

#include <algorithm>
#include <vector>
#include <iostream>
#include <functional>

void Test1()
{
    std::vector<int> vec {0, 1, 2, 3, 40, 40, 41, 41, 5};

    auto it = std::adjacent_find(vec.begin(), vec.end());
    if (it == vec.end()) {
        std::cout << "no matching adjacent elements\n";
    }
    else {
        std::cout << "the first adjacent pair of equal elements at: "
                << std::distance(vec.begin(), it) << std::endl;
    }
}

void Test2()
{
    std::vector<int> vec {0, 1, 2, 3, 40, 40, 41, 41, 5};

    auto it = std::adjacent_find(vec.begin(), vec.end(), std::greater<int>());
    if (it == vec.end()) {
        std::cout << "The entire vector is sorted in ascending order\n";
    }
    else {
        std::cout << "The last element in the non-decreasing subsequence is at: "
                << std::distance(vec.begin(), it) << std::endl;
    }
}

int main(int argc, char const *argv[])
{
    Test1();
    Test2();
    return 0;
}
