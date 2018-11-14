/*
    std::is_partitioned

    若范围中所有满足条件的元素都出现在所有不满足条件的元素前则返回 true 。范围为空也返回 true 。

    is_partitioned(first, last, unary_pre)
*/

#include <algorithm>
#include <vector>
#include <iostream>

int main(int argc, char const *argv[])
{
    std::vector<int> vec {1, 2, 3, 100, 101, 102};

    std::cout << "is vec partitioned by 50: " << std::boolalpha << std::is_partitioned(vec.begin(), vec.end(), [](int i) { return i < 50; })
            << std::endl;;

    return 0;
}
