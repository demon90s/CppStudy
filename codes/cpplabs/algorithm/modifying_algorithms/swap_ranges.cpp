/*
    std::swap_ranges

    在范围[first1, last1)和始于 first2 的另一范围间交换元素。

    swap_ranges(first1, last1, first2)
*/

#include <algorithm>
#include <vector>
#include <iostream>

int main(int argc, char const *argv[])
{
    std::vector<int> v1 {1, 2, 3, 4};
    std::vector<int> v2 {10, 20, 30, 40};

    std::swap_ranges(v1.begin(), v1.end(), v2.begin());

    std::cout << "v1:";
    for (auto i : v1)
        std::cout << " " << i;
    std::cout << std::endl;
    
    std::cout << "v2:";
    for (auto i : v2)
        std::cout << " " << i;
    std::cout << std::endl;

    return 0;
}
