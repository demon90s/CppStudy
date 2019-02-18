/*
    std::to_string

    to_string(val) 返回数值 val 的 string 表示。
    val 可以是任何算数类型。
*/

#include <string>
#include <iostream>

void Test1()
{
    std::cout << std::to_string(42) << std::endl;
    std::cout << std::to_string(3.14) << std::endl;
}

int main()
{
    Test1();

    return 0;
}