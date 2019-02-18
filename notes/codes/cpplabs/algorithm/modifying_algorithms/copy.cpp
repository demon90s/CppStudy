/*
    std::copy std::copy_if

    OutputIt copy(first, last, d_first)

    复制[first, last)所定义的范围中的元素到始于d_first的另一范围。

    返回值：指向目标范围最后复制元素的下个元素的输出迭代器。
*/

#include <algorithm>
#include <vector>
#include <iostream>

void Test_copy()
{
    std::vector<int> vec {1, 2, 3, 4};
    std::vector<int> des; des.resize(vec.size());

    std::copy(vec.begin(), vec.end(), des.begin());

    for (auto i : des)
        std::cout << i << " ";
    std::cout << std::endl;
}

void Test_copy_if()
{
    std::vector<int> vec {1, 2, 3, 4};
    std::vector<int> des; des.resize(vec.size());

    auto copy_end_it = std::copy_if(vec.begin(), vec.end(), des.begin(), [](int i) { return i % 2 == 0; });

    for (auto it = des.begin(); it != copy_end_it; ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

int main(int argc, char const *argv[])
{
    Test_copy();
    Test_copy_if();

    return 0;
}
