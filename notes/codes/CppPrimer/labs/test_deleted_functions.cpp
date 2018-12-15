// test: 测试删除的函数（p449）

#include <iostream>

using namespace std;

class Foo
{
public:
	//Foo& Instance() { static Foo foo; return foo; } // error

	~Foo() = delete;
};

class Goo
{
public:
	Goo& Instance() { static Goo goo; return goo; } // work fine

private:
	~Goo() {}
};

int main()
{
	//Foo f1; // error: use of deleted function ‘Foo::~Foo()’
	
	//static Foo f2; // error: use of deleted function ‘Foo::~Foo()’
	
	Foo *f3 = new Foo(); // work fine
	f3 = f3; // ignore warning
	//delete f3; // error: use of deleted function ‘Foo::~Foo()’

	return 0;
}
