/*
    拷贝初始化

    即调用类型的拷贝构造函数来初始化对象，有时候还会使用移动构造函数。

    何时发生（参考p441）？

    1. 使用=定义变量
    2. 将一个对象作为实参传递给一个非引用类型的形参
    3. 用花括号列表初始化一个数组中的元素或一个聚合类中的成员
    4. 某些类类型还会对它们所分配的对象使用拷贝初始化，如 vector::push
*/

#include <iostream>
#include <vector>

class Foo {
public:
    Foo(int v) : m_v(v) {}
    Foo(const Foo& f) : m_v(f.m_v) {
        std::cout << "copy constructor called" << std::endl;
    }

private:
    int m_v;
};

Foo static_foo(42);

void Case1()
{
    Foo foo = static_foo;
    (void)foo;
}

void Case2()
{
    auto test_func = [](Foo foo) {};

    test_func(static_foo);
}

void Case3()
{
    Foo foo_list[] = {static_foo};
    (void)foo_list;
}

void Case4()
{
    std::vector<Foo> foo_vec;

    foo_vec.push_back(static_foo);
}

int main()
{
    //Case1();
    //Case2();
    //Case3();
    Case4();

    return 0;
}