// test: 测试unique_ptr

#include <iostream>
#include <memory>

using namespace std;

struct Foo
{
public:
	Foo() {}
	~Foo() { cout << "Foo release" << endl; }
};

int main()
{
	unique_ptr<Foo[]> up(new Foo[3]);
	//up.release();

	cout << "main return" << endl;
	return 0;
}
