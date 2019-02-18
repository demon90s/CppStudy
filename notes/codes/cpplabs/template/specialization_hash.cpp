/*
    特例化 struct hash<T>
    一个特例化的 hash 类型必须定义：
    - 一个重载的调用运算符，接受一个对象类型，返回一个 size_t
    - 两个类型成员：result_type 和 argument_type ，分别表示调用运算符的返回类型和参数类型。
    - 默认构造函数和拷贝赋值运算符，可隐式定义
*/

#include <iostream>
#include <string>
#include <unordered_set>

// 为这个类型定义 hash 特例化
class Foo {
public:
    std::string str;
    int a;
    double d;
};

bool operator==(const Foo &lhs, const Foo &rhs)
{
    return lhs.str == rhs.str &&
        lhs.a == rhs.a &&
        lhs.d == rhs.d;
}

// 打开命名空间 std ，以便特例化 std::hash
namespace std {
template<>
struct hash<Foo>
{
    typedef size_t result_type;
    typedef Foo argument_type;
    size_t operator()(const Foo& foo) const;
};

size_t
hash<Foo>::operator()(const Foo& foo) const
{
    return hash<string>()(foo.str) ^
        hash<int>()(foo.a) ^
        hash<double>()(foo.d);
}

}

int main()
{
    // 定义了 hash 的特化版本和 operator== 后，就可以把自定义类型放入 unordered_set 了
    std::unordered_set<Foo> foo_unordered_set;
    (void)foo_unordered_set;

    return 0;
}