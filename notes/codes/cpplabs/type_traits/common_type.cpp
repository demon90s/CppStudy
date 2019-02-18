/*
    common_type

    共通类型，一个可以“用来对付两个不同类型的值”的类型，前提是的确存在这么一个共通类型。

    比如 int 和 long 的共通类型是 long
    string 和 const char* 的共通类型是 string
*/

#include <type_traits>
#include <typeinfo>
#include <iostream>

template<typename T1, typename T2>
typename std::common_type<T1, T2>::type
min(const T1 &x, const T2 &y)
{
    if (x < y) return x;
    else return y;
}

int main(int argc, char const *argv[])
{
    int n = 42;
    long m = 100;

    auto min_number = min(m, n);
    std::cout << min_number << " with type " << typeid(min_number).name() << std::endl;
    
    return 0;
}
