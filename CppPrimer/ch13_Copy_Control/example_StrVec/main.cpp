// example: 动态内存管理类（p464）

#include <iostream>

#include "StrVec.h"

using namespace std;

void func1()
{
	StrVec v;

	cout << "v.size(): " << v.size() << endl;
	cout << "v.capacity(): " << v.capacity() << endl;

	cout << "reserve 4 ..." << endl;
	v.reserve(4);
	cout << "v.size(): " << v.size() << endl;
	cout << "v.capacity(): " << v.capacity() << endl;

	cout << "push_back 2 string ..." << endl;
	v.push_back("a");
	v.push_back("b");
	cout << "v.size(): " << v.size() << endl;
	cout << "v.capacity(): " << v.capacity() << endl;

	cout << "print ..." << endl;
	for (auto p = v.begin(); p != v.end(); ++p)
		cout << *p << " ";
	cout << endl;

	cout << "resize to 0 ..." << endl;
	v.resize(0);
	cout << "v.size(): " << v.size() << endl;
	cout << "v.capacity(): " << v.capacity() << endl;

	cout << "resize to 100 ..." << endl;
	v.resize(100);
	cout << "v.size(): " << v.size() << endl;
	cout << "v.capacity(): " << v.capacity() << endl;
}

void func2()
{
	StrVec v{"a", "b", "Hello", "World"};

	for (auto p = v.begin(); p != v.end(); ++p)
		cout << *p << " ";
	cout << endl;

	cout << "v.size(): " << v.size() << endl;
	cout << "v.capacity(): " << v.capacity() << endl;
}

void func3()
{
	StrVec v1{"a", "b", "Hi"};
	StrVec v2{"a", "n", "Hi"};
	StrVec v3{"a", "n", "Hi"};
	StrVec v4{"a", "n", "Hi", "Hello"};

	if (v1 != v2)
		cout << "v1 != v2" << endl;

	if (v2 == v3)
		cout << "v2 == v3" << endl;

	if (v3 < v4)
		cout << "v3 < v4" << endl;
}

// 测试emplace_back，p623
void func4()
{
	StrVec v;
	v.emplace_back(10, 'c');
	v.emplace_back("Hello");

	for (auto p = v.begin(); p != v.end(); ++p)
		cout << *p << " ";
	cout << endl;
}

int main()
{
	func1();
	//func2();
	//func3();
	//func4();

	return 0;
}
