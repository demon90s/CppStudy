/*
    std::all_of(first, last, p): 检查一元谓词p是否对范围中的所有元素返回 true
    std::any_of(first, last, p): 检查一元谓词p是否对范围中的至少一个元素返回 true
    std::none_of(first, last, p): 检查一元谓词p是否不对范围中的任何元素返回 true
*/

#include <algorithm>
#include <vector>
#include <iostream>

int main(int argc, char const *argv[])
{
    std::vector<int> vec {1, 2, 3, 10, 20, 30};

    std::cout << "all element > 0 ? " << std::boolalpha << std::all_of(vec.begin(), vec.end(), [](int i) { return i > 0; }) << std::endl;
    std::cout << "any element == 0 ? " << std::boolalpha << std::any_of(vec.begin(), vec.end(), [](int i) { return i == 0; }) << std::endl;
    std::cout << "none element < 0 ? " << std::boolalpha << std::none_of(vec.begin(), vec.end(), [](int i) { return i < 0; }) << std::endl;

    return 0;
}
