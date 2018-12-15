// 练习18.29：已知有如下所示的继承关系：
// PS: 该程序会报warning

#include <iostream>
using namespace std;

class Class {
public:
	Class() { cout << "Class()" << endl; }
};

class Base : public Class {
public:
	Base() { cout << "Base()" << endl; }
};

class D1 : virtual public Base {
public:
	D1() { cout << "D1()" << endl; }
};

class D2 : virtual public Base {
public:
	D2() { cout << "D2()" << endl; }
};

class MI : public D1, public D2 {
public:
	MI() { cout << "MI()" << endl; }
};

class Final : public MI, public Class {
public:
	Final() { cout << "Final()" << endl; }
};

// (a) 当作用于一个Final对象时，构造函数和析构函数的执行次序分别是什么？
// Class -> Base -> D1 -> D2 -> MI -> Class -> Final

// (b) 在一个Final对象中有几个Base部分？几个Class部分？
// 一个Base部分，两个Class部分

// (c) 下面哪些赋值运算符将造成编译错误？
void func()
{
	Final f;

	Base *pb = 0;
	Class *pc = 0;
	MI *pmi = 0;
	D2 *pd2 = 0;
 
	// (c) (a)
	//pb = new Class(); // 错误，不能把基类指针转换成派生类指针
	// (c) (b)
	//pc = new Final();	// 错误，‘Class’ is an ambiguous base of ‘Final’
	
	// (c) (c)
	//pmi = pb; // 错误，能把基类指针转换成派生类指针
	
	// (c) (d)
	pd2 = pmi; // 正确

	if (pb) { delete pb; pb = 0; }
	if (pc) { delete pc; pc = 0; }
	if (pmi) { delete pmi; pmi = 0; }
	if (pd2) { delete pd2; pd2 = 0; }
}

int main()
{
	func();

	return 0;
}
