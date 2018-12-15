/*
    void replace(first, last, old_value, new_value)
    以 new_value 替换范围 [first, last) 中所有等于 old_value 的元素

    void replace_if(first, last, p, new_value)
    以 new_value 替换范围 [first, last) 中所有谓词p对其返回 true 的元素

    it replace_copy(first, last, d_first, old_value, new_value)
    it replace_copy_if(first, last, d_first, p, new_value)
    负值来自范围 [first last) 的所有元素到始于 d_first 的范围，并以 new_value 替换所有满足特定判别标准的元素。
    - 替换所有等于 old_value 的元素
    - 替换所有谓词p对其满足 true 的元素

    返回最后复制元素后一元素的迭代器
*/

#include <vector>
#include <algorithm>
#include <iostream>

void test_replace()
{
    std::vector<int> vec = {0, 0, 0, 6, 6};
    std::replace(vec.begin(), vec.end(), 6, 9);
    for (auto i : vec) {
        std::cout << i << " ";
    }
    std::cout << '\n';
}

void test_replace_if()
{
    std::vector<int> vec = {0, 0, 0, 6, 6};
    std::replace_if(vec.begin(), vec.end(), [](int i) { return i == 6; }, 9 );
    for (auto i : vec) {
        std::cout << i << " ";
    }
    std::cout << '\n';
}

void test_replace_copy()
{
    std::vector<int> vec = {0, 0, 0, 6, 6};
    std::vector<int> vec2 = {1, 1, 1, 1, 1};

    std::replace_copy(vec.begin(), vec.end(), vec2.begin(), 6, 9);
    for (auto i : vec2) {
        std::cout << i << " ";
    }
    std::cout << '\n';
}

void test_replace_copy_if()
{
    std::vector<int> vec = {0, 0, 0, 6, 6};
    std::vector<int> vec2 = {1, 1, 1, 1, 1};

    std::replace_copy_if(vec.begin(), vec.end(), vec2.begin(), [](int i) { return i == 6; }, 9);
    for (auto i : vec2) {
        std::cout << i << " ";
    }
    std::cout << '\n';
}

int main(int argc, char const *argv[])
{
    test_replace();
    test_replace_if();
    test_replace_copy();
    test_replace_copy_if();
    
    return 0;
}
