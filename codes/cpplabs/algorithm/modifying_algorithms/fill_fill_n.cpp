/*
    void fill(first, last, value)
    赋值给定的 value 给 [first, end) 中的元素

    void fill_n(first, count, value)
    赋值给定的 value 给始于 first 的 count 个元素。
*/

#include <vector>
#include <algorithm>
#include <iostream>

void test_fill()
{
    std::vector<int> vec = {0, 0, 0, 0, 0};
    fill(vec.begin(), vec.end(), 9);
    for (auto i : vec) {
        std::cout << i << " ";
    }
    std::cout << "\n";
}

void test_fill_n()
{
    std::vector<int> vec = {0, 0, 0, 0, 0};
    fill_n(vec.begin(), 3, 9); // vec: 9 9 9 0 0
    for (auto i : vec) {
        std::cout << i << " ";
    }
    std::cout << "\n";
}

int main(int argc, char const *argv[])
{
    test_fill_n();
    
    return 0;
}
