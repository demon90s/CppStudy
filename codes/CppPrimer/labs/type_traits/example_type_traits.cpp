/*
    #include <type_traits>

    所谓 type_trait ，即提供一种用来处理 type 属性的办法。

    type_traits 提供了许多类型判断工具（ type predicate ），可以产出一个 std::true_type 或 std::false_type 。它们都是一个 intergral_constant 。

    is_pointer<T> 用来检测T是否是一个 pointer type ，若是，返回一个类型为 true_type 的值，否则返回一个类型为 false_type 的值。
    true_type 和 false_value 的 value 成员分别是 true 和 false 。
*/

#include <iostream>
#include <type_traits>

template<typename T>
void foo(const T& val)
{
    if (std::is_pointer<T>::value) {
        std::cout << "foo() called for a pointer" << std::endl;
    }
    else {
        std::cout << "foo() called for a value" << std::endl;
    }
}

void test_foo()
{
    int n = 42;
    foo(n);
    foo(&n);
}

void test_is_same()
{
    std::cout << std::boolalpha;
    std::cout << std::is_same<int, long>() << std::endl;
}

int main()
{
    //test_foo();

    test_is_same();

    return 0;
}