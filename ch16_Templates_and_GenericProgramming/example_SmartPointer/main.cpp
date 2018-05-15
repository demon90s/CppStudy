// example: 自己实现智能指针（p600, 练习16.28）

#include <iostream>
#include "SharedPtr.h"
#include "UniquePtr.h"

using namespace std;

class Boo
{
public:
	~Boo() { cout << "~Boo()" << endl; }
	void Print() const { cout << "I am Boo" << endl; }
};

void Test_SharedPtr()
{
	{
		SharedPtr<int> sp;
	}

	{
		SharedPtr<int> sp(new int(5));
		cout << *sp << endl;
	}

	{
		SharedPtr<int> sp(new int(5), [](int *p) { 
		 cout << "Delete int" << endl; delete p;});
	}

	{
		SharedPtr<int> sp(new int(5));
		SharedPtr<int> sp2 = sp;
		*sp2 = 10;
		cout << *sp << endl;
	}

	{
		SharedPtr<int> sp(new int(5));

		sp = sp; // 检测自赋值

		SharedPtr<int> sp2;
		sp2 = sp;
		*sp2 = 10;
		cout << *sp << endl;
	}

	{
		SharedPtr<Boo> sp(new Boo());
		SharedPtr<Boo> sp2 = sp;
		sp2->Print();
		// delete only once
	}
}

void Test_UniquePtr()
{
	{
		UniquePtr<int> sp;
	}

	{
		UniquePtr<int> sp(new int(5));
		cout << *sp << endl;
	}

	{
		UniquePtr<int, std::function<void(int*)>> sp(new int(5), [](int *p) {
			cout << "Delete int" << endl;
			delete p;
		});
	}

	{
		// can not copy
		UniquePtr<int> sp(new int(5));
		//UniquePtr<int> sp2 = sp;
	}

	{
		UniquePtr<Boo> sp(new Boo());
		sp->Print();
	}
}

int main()
{
	//Test_SharedPtr();
	Test_UniquePtr();

	return 0;
}
