/*
    private destructor 可以避免对象分配在栈上
*/

#include <iostream>

class Foo {
public:
    void Free() {
        delete this;
    }
private:
    ~Foo() {
        std::cout << "~Foo()\n";
    }
};

int main()
{
    Foo *f = new Foo;
    f->Free();

    return 0;
}
