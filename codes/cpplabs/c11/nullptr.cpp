/*
    nullptr 用于取代 0 或者 NULL 表示一个指针指向所谓的 no value 。

    nullptr 被自动转换成各种 pointer 类型，但不会被转换成任何整数类型。
    
    它拥有类型 std::nullptr_t ，定义于 <cstddef>
*/

#include <iostream>

void func(int)
{
    std::cout << "func(int)" << std::endl;
}

void func(void*)
{
    std::cout << "func(void*)" << std::endl;
}

int main()
{
    //func(NULL);     // ambiguous error
    func(nullptr);  // call func(void*)

    return 0;
}