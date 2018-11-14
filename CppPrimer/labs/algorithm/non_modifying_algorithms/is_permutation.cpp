/*
    std::is_permutation
    若存在范围[first1, last1)中元素的排列，使得该范围等于[first2, last2)，则返回 true
*/

#include <algorithm>
#include <vector>
#include <iostream>

int main(int argc, char const *argv[])
{
    std::vector<int> v1 {1, 2, 3, 4, 5};
    std::vector<int> v2 {3, 5, 4, 1, 2};

    std::cout << "{3, 5, 4, 1, 2} is a permutation of {1, 2, 3, 4, 5}? "
            << std::boolalpha
            << std::is_permutation(v1.begin(), v1.end(), v2.begin()) << std::endl;

    std::vector<int> v3 {3, 5, 4, 1, 1};
    std::cout << "{3, 5, 4, 1, 1} is a permutation of {1, 2, 3, 4, 5}? "
            << std::boolalpha
            << std::is_permutation(v1.begin(), v1.end(), v3.begin()) << std::endl;

    return 0;
}
