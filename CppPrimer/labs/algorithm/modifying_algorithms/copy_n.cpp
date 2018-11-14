/*
    copy_n
    若 count > 0 ，则准确复制来自始于 first 的范围的 count 个值到始于 result 的范围。

    copy_n(first, count, result)
*/

#include <algorithm>
#include <vector>
#include <iostream>
#include <iterator>

int main(int argc, char const *argv[])
{
    std::vector<int> vec {1, 2, 3, 4, 5};
    std::vector<int> des;

    std::copy_n(vec.begin(), 3, std::back_inserter(des));

    for (auto i : des)
        std::cout << i << " ";
    std::cout << std::endl;
    
    return 0;
}
