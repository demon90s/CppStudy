/*
    std::find_first_of
    在范围中搜索另一个范围中的任何元素

    find_first_of(first, last, s_first, s_last)
    用 operator== 比较元素

    find_first_of(first, last, s_first, s_last, binary_predicate)
    用二元谓词比较元素
    
    返回 [first, last) 中等于来自范围 [s_first, s_last) 中一个元素的首个元素，找不到返回 last 。

    复杂度：至多做 S*N 次比较，其中 S=distance(s_first, s_last) ， N=distance(first, last)
*/

#include <algorithm>
#include <vector>
#include <iostream>

void Test1()
{
    std::vector<int> vec {1, 2, 3, 4, 5, 6};
    std::vector<int> sub {5, 3};

    auto it = std::find_first_of(vec.begin(), vec.end(), sub.begin(), sub.end());
    if (it == vec.end()) {
        std::cout << "not find" << std::endl;
    }
    else {
        std::cout << "first find pos: " << std::distance(vec.begin(), it) << std::endl;
    }
}

int main(int argc, char const *argv[])
{
    Test1();
    return 0;
}
