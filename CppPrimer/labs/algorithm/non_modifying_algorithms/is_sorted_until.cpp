/*
    std::is_sorted_until

    检查范围[first1, last)，并寻找始于 first 且其中元素已以升序排序的最大范围。

    is_sorted_until(first, last)
    用 operator< 比较元素

    is_sorted_until(first, last, comp)
    用二元比较函数 comp 比较元素

    返回值：始于 first 且其中元素已以升序排序的最大范围。即满足范围[first, it)已排序的最后迭代器it。
*/

#include <algorithm>
#include <vector>
#include <iostream>

void Test1()
{
    std::vector<int> vec {1, 2, 3, 0, 5};

    auto it = std::is_sorted_until(vec.begin(), vec.end());
    std::cout << "last unsorted pos: " << std::distance(vec.begin(), it) << std::endl;
}

int main(int argc, char const *argv[])
{
    Test1();

    return 0;
}
