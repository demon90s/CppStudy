/*
    #include <type_traits>
    template<class T, T v>
    struct integral_constant;

    一个帮助模板，包含了一个类型T，以及对应的一个常量值v 。

    其成员都是 constexpr 的，在编译器可求值。

    它有一个成员 value ，返回 v 。
    也可以直接采取 () 运算，获取成员 value
*/

#include <type_traits>
#include <iostream>

int main()
{
    typedef std::integral_constant<int, 100> ScoreMax;

    std::cout << ScoreMax::value << std::endl;

    return 0;
}