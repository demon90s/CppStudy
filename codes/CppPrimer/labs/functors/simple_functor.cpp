#include <iostream>
#include <string>

/*
    简单的函数对象，即重载了调用运算符（operator()）的类型
*/

class Foo {
public:
    void operator()(std::string str) {
        std::cout << "Calling functor Foo with parameter " << str << std::endl;
    }
};

int main(int argc, char const *argv[])
{
    Foo foo;
    foo("Hello");

    return 0;
}
