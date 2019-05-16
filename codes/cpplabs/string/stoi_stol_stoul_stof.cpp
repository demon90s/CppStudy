/*
    stoi(s, p, b) - 返回类型 int
    stol(s, p, b) - 返回类型 long
    stoul(s, p, b) - 返回类型 unsigned long
    stof(s, p) - 返回类型 float

    返回s的起始子串（表示整数内容）的数值。
    p 是 size_t 类型的指针，保存s中地一个非数值字符的下标，默认为0 。
    b 表示转换基数，默认是10。 
*/

#include <string>
#include <iostream>

void Test1()
{
    int i = std::stoi("1010", 0, 2);
    std::cout << "1010(2) -> " << i << "(10)" << std::endl;

    std::cout << std::stoi("42") << std::endl;
}

int main()
{
    Test1();

    return 0;
}