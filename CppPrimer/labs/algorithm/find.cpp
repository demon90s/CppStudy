/*
    find
    线性搜索范围中满足判别标准的首个元素

    find(first, last, value)
    搜索等于 value 的元素

    find_if(first, last, unary_predicate)
    搜索谓词对其返回 true 的元素

    find_if_not(first, last, unary_predicate)
    搜索谓词对其返回 false 的元素

    返回首个满足条件的迭代器，找不到则返回 last
*/

#include <algorithm>
#include <vector>
#include <iostream>

void Test_find()
{
    std::vector<int> vec = {10, 2, 100, 42, 500};

    auto it = std::find(vec.begin(), vec.end(), 555);
    if (it != vec.end()) {
        std::cout << "found" << std::endl;
    }
    else {
        std::cout << "not find" << std::endl;
    }
}

void Test_find_if()
{
    struct Foo {
        int id;
        int power;
    };

    std::vector<Foo> vec = {
      {1, 70},
      {2, 60},
      {3, 88},
      {4, 78}  
    };

    auto it = std::find_if(vec.begin(), vec.end(), [](const Foo &foo) {
        return foo.power > 80;
    });

    if (it != vec.end()) {
        std::cout << "find id: " << it->id << std::endl;
    }
    else {
        std::cout << "not find" << std::endl;
    }
}

void Test_find_if_not()
{
    struct Foo {
        int id;
        int power;
    };

    std::vector<Foo> vec = {
      {1, 70},
      {2, 60},
      {3, 88},
      {4, 78}  
    };

    auto it = std::find_if_not(vec.begin(), vec.end(), [](const Foo &foo) {
        return foo.power >= 70;
    });

    if (it != vec.end()) {
        std::cout << "find id: " << it->id << std::endl;
    }
    else {
        std::cout << "not find" << std::endl;
    }
}

int main(int argc, char const *argv[])
{
    //Test_find();
    //Test_find_if();
    Test_find_if_not();

    return 0;
}
