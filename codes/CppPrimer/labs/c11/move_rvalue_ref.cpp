/*
    c++ 的重要特性： move semantic

    用以避免非必要的拷贝和临时对象。

    具体的 move 动作不是由 rvalue ref 对象决定的，而是函数。

    临时的对象可以被当作右值引用传入对应的函数。
    或者使用 std::move 显示地让一个变量被当作一个右值引用。

    使用 rvalue ref 的契约是：这是个不再被需要的对象，函数可以偷其内容（或资源）。

    如果 class 未提供 move 语义，只提供惯常的 copy 构造函数和 copy assignment 操作服， rvalue reference 可以调用它们。
    因此， std::move() 意味着“调用 move 语义，否则调用 copy 语义”。

    **返回 rvalue reference **
    这是没有必要的，对于下面的代码：
    X foo() { X x;  return x; }
    编译器可以执行所谓的 return value optimization(RVO)。编译器可以选择地略去 copy 版本。
*/

#include <vector>
#include <iostream>

class Foo {
public:
    Foo() : m_value(0) {}
    Foo(int v) : m_value(new int(v)) {}
    ~Foo() { if (m_value) delete m_value; }
    
    Foo(const Foo &v) {
        m_value = new int(*v.m_value);
        std::cout << "copy constructor called" << std::endl;
    }

    Foo(Foo &&v) {
        m_value = v.m_value;
        v.m_value = nullptr;
        std::cout << "move constructor called" << std::endl;
    }

    Foo& operator=(const Foo &v) {
        Foo tmp(v);
        delete m_value;
        m_value = new int(*tmp.m_value);
        return *this;
    }

    Foo& operator=(Foo &&v) {
        if (this != &v) {
            m_value = v.m_value;
            v.m_value = nullptr;
        }
        return *this;
    }

private:
    int *m_value;
};

void Copy()
{
    std::vector<Foo> coll;

    Foo foo;
    coll.push_back(foo); // copy
}

void Move()
{
    std::vector<Foo> coll;
    coll.reserve(10);

    // 临时对象，自动地选择 move constructor
    coll.push_back({42});

    // 显示地使用 std::move 令变量类型转成 rvalue ref
    Foo foo;
    coll.push_back(std::move(foo)); // move constructor
}

int main()
{
    //Copy();
    Move();
    return 0;
}