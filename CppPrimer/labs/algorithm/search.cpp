/*
    search
    搜索子序列首次出现

    search(first, last, s_first, s_last)
    使用 operator== 比较

    search(first, last, s_first, s_last, binary_predicate)
    使用二元谓词比较

    返回子序列在原序列中的起始迭代器，若找不到，返回 last
    若 [s_first, s_last) 为空，返回 first
*/

#include <algorithm>
#include <vector>
#include <iostream>

void Test1()
{
    std::vector<int> vec = {0, 1, 2, 3, 4, 5};
    std::vector<int> sub = {2, 3, 4};

    auto it = std::search(vec.begin(), vec.end(), sub.begin(), sub.end());
    if (it != vec.end()) {
        std::cout << "find" << std::endl;
    }
    else {
        std::cout << "not find" << std::endl;
    }
}

int main(int argc, char const *argv[])
{
    Test1();
    
    return 0;
}
