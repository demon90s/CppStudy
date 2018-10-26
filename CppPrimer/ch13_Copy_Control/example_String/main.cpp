// example: 自定义String简化版本（p470练习13.44）

#include <iostream>
#include <vector>

#include "String.h"

using namespace std;

void func1()
{
	String v;

	cout << "v.size(): " << v.size() << endl;
	cout << "v.capacity(): " << v.capacity() << endl;

	cout << "reserve 4 ..." << endl;
	v.reserve(4);
	cout << "v.size(): " << v.size() << endl;
	cout << "v.capacity(): " << v.capacity() << endl;

	cout << "push_back 2 char ..." << endl;
	v.push_back('a');
	v.push_back('b');
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

	cout << "resize to 97 ..." << endl;
	v.resize(97);
	cout << "v.size(): " << v.size() << endl;
	cout << "v.capacity(): " << v.capacity() << endl;
}

void func2()
{
	String v{'a', 'b', 'c', 'd'};

	for (auto p = v.begin(); p != v.end(); ++p)
		cout << *p << " ";
	cout << endl;

	cout << "v.size(): " << v.size() << endl;
	cout << "v.capacity(): " << v.capacity() << endl;
}

void func3()
{
	String v;
	cout << v << endl;

	v = "Hello world";
	cout << v << endl;
}

void func4()
{
	vector<String> v;
	v.push_back("Hello World");
	cout << "v.capacity(): " << v.capacity() << endl;

	v.push_back("Hi");
	cout << "v.capacity(): " << v.capacity() << endl;

	v.push_back("WoW");
	cout << "v.capacity(): " << v.capacity() << endl;

}

void func5()
{
	String s1 = "Hello";
	String s2 = "Hillo";
	String s3 = "Hillo";
	String s4 = "Him";

	if (s1 != s2)
		cout << "s1 != s2" << endl;

	if (s2 == s3)
		cout << "s2 == s3" << endl;

	if (s3 < s4)
		cout << "s3 < s4" << endl;
}

int main()
{
	func1();
	//func2();
	//func3();
	//func4();
	//func5();

	return 0;
}
