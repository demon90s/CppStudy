/*
    std::string::find_last_of

    s.find_last_of(args)
    在s中查找 args 中任何一个字符最后一次出现的位置
*/

#include <string>
#include <iostream>

void Test1()
{
    std::string s = "ABCDEFGHIJK";

    auto pos = s.find_last_of("EGI");
    if (pos == std::string::npos) {
        std::cout << "not find" << std::endl;
    }
    else {
        std::cout << "find, pos: " << pos << std::endl;
    }
}

int main()
{
    Test1();
    return 0;
}