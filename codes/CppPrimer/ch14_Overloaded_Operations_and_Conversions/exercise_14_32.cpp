// 练习14.32：定义一个类令其有指向StrBlobPtr对象的指针，为这个类定义重载的箭头运算符。

// g++ -g -Wall -std=c++11 -o exercise_14_32 exercise_14_32.cpp ../ch12_Dynamic_Memory/example_StrBlobPtr/StrBlobPtr.cpp

#include <iostream>

#include "../ch12_Dynamic_Memory/example_StrBlobPtr/StrBlob.h"
#include "../ch12_Dynamic_Memory/example_StrBlobPtr/StrBlobPtr.h"

using namespace std;

class Foo
{
public:
	Foo(StrBlobPtr *p) : m_p(p) {}

	StrBlobPtr *operator->()
	{
		return m_p;
	}

private:
	StrBlobPtr *m_p;
};

int main()
{
	StrBlob b{"Hi", "Hello", "World"};
	StrBlobPtr bp(b);

	Foo foo(&bp);
	cout << foo->deref() << endl;

	return 0;
}
