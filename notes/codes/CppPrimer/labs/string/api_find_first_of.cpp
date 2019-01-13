/*
    std::string::find_first_of

    s.find_first_of(args)
    在s中查找 args 中任何一个字符第一次出现的位置
*/

#include <string>
#include <iostream>

void Test1()
{
    std::string s = "ABCDEFGHIJK";

    auto pos = s.find_first_of("EGI");
    if (pos == std::string::npos) {
        std::cout << "not find" << std::endl;
    }
    else {
        std::cout << "find, pos: " << pos << std::endl;
    }
}

// 找出 string 中所有的数字
void Test2()
{
    std::string s = "a1b2c3ddd987";
    std::string numbers = {"0123456789"};

    std::string::size_type pos = 0;
    while ((pos = s.find_first_of(numbers, pos)) != std::string::npos) {
        std::cout << "found number at index: " << pos 
            << " element is " << s[pos] 
            << std::endl;

        ++pos;
    }
}

int main()
{
    //Test1();
    Test2();

    return 0;
}