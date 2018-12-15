/*
    find_end
    搜索子序列最后一次出现

    find_end(first, end, s_first, s_end)
    使用 operator== 比较

    find_end(first, end, s_first, s_end, binary_predicate)
    使用二元谓词比较

    返回子序列最后一次出现的开端迭代器，如果找不到，返回 last
*/

#include <algorithm>
#include <vector>
#include <iostream>

void Test1()
{
    std::vector<int> vec {1, 2, 3, 5, 5, 5, 1, 2, 3};
    std::vector<int> sub {1, 2, 3};

    auto it = find_end(vec.begin(), vec.end(), sub.begin(), sub.end());
    if (it != vec.end()) {
        std::cout << "find, pos is: " << it - vec.begin() << std::endl;
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
