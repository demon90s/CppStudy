/*
    参考: EffectCpp 条款03
    bitwise const 指的是在类的const成员函数中, 不可以修改所有的成员.
    logic const 则表示, 可以在客户端侦测不到时, 在const成员函数中修改成员.
*/

class Foo {
public:
    Foo() : m_call_times(0), p(new int(0)) {}
    ~Foo() { delete p; }
    void Call() const {
        ++m_call_times;     // 客户端侦测不到的话, 那么就可以修改
        // do something else
    }

    void Call2() const {
        // 不修改任何成员, 看上去是 bitwise 的, 但却阻止不了某些事情发生...
        *p = 42; // 假如p绑定的对象由该类型负责..那么实际上不可以称为 bitwise , 但编译器无法检查到
    }

private:
    Foo(const Foo&);
    Foo& operator=(const Foo&);

    mutable int m_call_times;
    int *p;
};

int main()
{
    return 0;
}
