/*
    挑选最小值和最大值

    比较操作默认使用<，或可用 comp 操作。

    操作                            效果
    min(a, b)                       返回a,b之间的最小值
    min(a, b, comp)
    min(initlist)                   返回 initlist 中的最小值
    min(initlist, comp)

    max(a, b)                       返回a,b之间的最大值
    max(a, b, comp)
    max(initlist)                   返回 initlist 中的最大值
    max(initlist, comp)

    minmax(a, b)                    返回a,b之间的最大值和最小值的一个 pair ，first 是最小值， second 是最大值
    minmax(a, b, comp)
    minmax(initlist)                返回 initlist 中的最大值和最小值的一个 pair ，first 是最小值， second 是最大值
    minmax(initlist, comp)

    Note：
    接受两个值的版本返回的是 const 引用，而接受 initlist 的版本返回的是拷贝。
*/

#include <algorithm>
#include <iostream>

//--------------------------------------------------------------------
struct Foo {
    const char *name;
    int power;
};
bool Foo_Less(const Foo &lhs, const Foo &rhs)
{
    return lhs.power < rhs.power;
}

std::ostream& operator<<(std::ostream &os, const Foo &foo)
{
    os << foo.name << " " << foo.power;
    return os;
}
//--------------------------------------------------------------------

void Test_min()
{
    std::cout << "min of 42 and 100: " << std::min(42, 100) << std::endl;

    int a = 42, b = 100, c = 30;
    std::cout << "min of a,b,c: " << std::min({a, b, c}) << std::endl;

    Foo f1 {"Miemie", 1000}, f2 {"Diwen", 200};
    const Foo& min_foo = std::min(f1, f2, Foo_Less);
    std::cout << "min of foo: " << min_foo << std::endl;
}

void Test_max()
{
    std::cout << "max of 42 and 100: " << std::max(42, 100) << std::endl;

    int a = 42, b = 100, c = 30;
    std::cout << "max of a,b,c: " << std::max({a, b, c}) << std::endl;

    Foo f1 {"Miemie", 1000}, f2 {"Diwen", 200};
    const Foo& max_foo = std::max(f1, f2, Foo_Less);
    std::cout << "max of foo: " << max_foo << std::endl;
}

void Test_minmax()
{
    auto minmax_int = std::minmax({42, 10, 100, 30, 66});
    std::cout << "min: " << minmax_int.first << std::endl;
    std::cout << "max: " << minmax_int.second << std::endl;
}

int main()
{
    //Test_min();
    //Test_max();

    Test_minmax();

    return 0;
}