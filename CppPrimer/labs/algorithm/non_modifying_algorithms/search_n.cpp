/*
    search_n
    在范围中搜寻n个等同元素序列

    search_n(first, last, n, value)
    用 operator== 做比较

    search_n(first, last, n, value, binary_predicate)
    用二元谓词做比较

    返回范围中找到子序列的起始位置，若找不到，返回 last
*/

#include <algorithm>
#include <vector>
#include <iostream>

void Test1()
{
    std::vector<int> vec = {1, 1, 1, 0, 0, 0, 0};
    
    auto it = std::search_n(vec.begin(), vec.end(), 4, 0); // 子序列为连续四个零

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
