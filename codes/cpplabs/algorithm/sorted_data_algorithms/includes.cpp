/*
    bool includes(first1, last1, first2, last2);

    两个序列都要排序。
    若第二个序列是第一个序列的子序列，则返回 true
*/

#include <iostream>
#include <algorithm>
#include <vector>

void Test1()
{
    std::vector<int> v1 {1, 2, 3, 4, 5, 6, 7, 8};
    std::vector<int> v2 {3, 4, 5};

    bool is_sub_seq = includes(v1.begin(), v1.end(), v2.begin(), v2.end());

    std::cout << "is_sub_seq? " << (is_sub_seq ? "yes" : "no") << std::endl;
}

int main()
{
    Test1();

    return 0;
}