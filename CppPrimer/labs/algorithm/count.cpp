/*
    count
    count(first, last, value)
    返回范围中等于 value 的个数。

    count_if
    count_if(first, last, unary_predicate_p)
    返回范围中满足谓词p的个数
*/

#include <algorithm>
#include <vector>
#include <iostream>

void Test_count()
{
    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 2, 2, 2};

    int n = std::count(vec.begin(), vec.end(), 2);

    std::cout << n << std::endl;
}

void Test_count_if()
{
    std::vector<int> vec = {1, 2, 3, 4, 5, 6};

    int n = std::count_if(vec.begin(), vec.end(), [](int i) { return i > 3; });

    std::cout << n << std::endl;
}

int main(int argc, char const *argv[])
{
    Test_count();
    Test_count_if();

    return 0;
}
