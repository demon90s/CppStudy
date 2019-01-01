/*
    void generate(first, last, g)
    以给定的函数对象g所生成的值赋值范围 [first, last) 中的元素。

    void generate_n(first, count, g)
    赋值给定函数对象g所生成的值始于 first 的范围的首 count 个元素。
*/

#include <vector>
#include <algorithm>
#include <iostream>

void test_generate()
{
    std::vector<int> vec = {0, 0, 0, 0, 0};
    std::generate(vec.begin(), vec.end(), rand);
    for (auto i : vec) {
        std::cout << i << " ";
    }
    std::cout << '\n';
}

void test_generate_n()
{
    std::vector<int> vec = {0, 0, 0, 0, 0};
    std::generate_n(vec.begin(), 3, rand);
    for (auto i : vec) {
        std::cout << i << " ";
    }
    std::cout << '\n';
}

int main(int argc, char const *argv[])
{
    test_generate();
    test_generate_n();
        
    return 0;
}
