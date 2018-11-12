/*
    functior 的用处，使用成员变量保存状态
    增加了函数调用的灵活性
*/

#include <iostream>
#include <vector>
#include <algorithm>

class Add {
public:
    Add(int v) : v_(v) {}
    void operator()(int &i) { i += v_; }

private:
    int v_;
};

int main(int argc, char const *argv[])
{
    // 给vec的每个元素加2
    std::vector<int> vec{1, 2, 3, 4};
    for_each(vec.begin(), vec.end(), Add(2));

    for (auto i : vec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
