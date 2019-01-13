/*
    std::string::compare

    s.compare(arg)
    比较s和 arg 所代表的字符串，大于 arg 返回正数，等于返回0，小于返回负数。
*/

#include <string>
#include <iostream>

void Test1()
{
    std::string s = "ABC";

    if (s.compare("ABD") < 0) {
        std::cout << "ABC < ABD" << std::endl;
    }
}

int main()
{
    Test1();
    return 0;
}