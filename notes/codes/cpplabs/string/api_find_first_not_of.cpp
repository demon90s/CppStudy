/*
    std::string::find_first_not_of

    s.find_first_not_of(args)
    在s中查找第一个不在 args 中的字符
*/

#include <string>
#include <iostream>

void Test1()
{
    std::string s = "ABCDEFGHIJK";

    auto pos = s.find_first_not_of("ABC");

    if (pos == std::string::npos) {
        std::cout << "not find" << std::endl;
    }
    else {
        std::cout << "got first not of: " << s[pos] << std::endl;
    }
}

int main()
{
    Test1();
    return 0;
}