/*
    minmax_element
    寻找范围中最小和最大的元素

    minmax_element(first, last)
    用 operator< 比较元素

    minmax_element(first, last, comp)
    用二元比较函数 comp 比较元素

    返回一个 pair ，first 是首个最小元素的迭代器， second 是首个最大元素的迭代器。若范围为空，返回 std::make_pair(first, first)
*/

#include <algorithm>
#include <vector>
#include <iostream>

int main(int argc, char const *argv[])
{
    std::vector<int> vec {2, 100, 20, 19, -100, 1};

    auto minmax_pair = std::minmax_element(vec.begin(), vec.end());

    std::cout << "min element: " << *minmax_pair.first << std::endl;
    std::cout << "max element: " << *minmax_pair.second << std::endl;

    return 0;
}