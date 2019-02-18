// test: 测试右值

#include <iostream>

using namespace std;

int func()
{
	return 10; // 函数返回一个值是右值
}

int main()
{
	//func() = 5; // error: lvalue required as left operand of assignment
	
	const int &a = func();
	//int &b = func(); // error: invalid initialization of non-const reference of type ‘int&’ from an rvalue of type ‘int’

	const int &c = 5;
	//int &d = 5; // same as b，5 is a rvalue

	cout << a << endl;
	cout << c << endl;

	return 0;
}
