/*
    #include <limits>
    numeric_limit

    该模板类型提供数值类型的极值，极值是与平台相关的。

    numeric_limit 提供了多个特化的版本，为内建类型提供极值。

    numeric_limit 所有成员都是 constexpr 的，因此可以为编译器表达式使用。

    你可以对任何类型进行询问，无论它是否定义了极值。

    成员举例：
    is_specialized              是否特化版本，默认为 false ，意思是对于 T 类型，没有所谓极值。
    max()                       最大值
    min()                       最小值
*/

#include <iostream>
#include <limits>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    // use textual representation for bool
    cout << boolalpha;

    // print maximum of integral types
    cout << "max(short): " << numeric_limits<short>::max() << endl;
    cout << "max(int): " << numeric_limits<int>::max() << endl;
    cout << "max(long): " << numeric_limits<long>::max() << endl;
    cout << endl;

    // print maximum of floating-point types
    cout << "max(float): " << numeric_limits<float>::max() << endl;
    cout << "max(double): " << numeric_limits<double>::max() << endl;
    cout << endl;

    // print whether numeric limits for type string exist
    cout << "is_specialized(string): " << numeric_limits<string>::is_specialized << endl;

    struct Foo {};
    cout << "is_specialized(Foo): " << numeric_limits<Foo>::is_specialized << endl;

    return 0;
}
