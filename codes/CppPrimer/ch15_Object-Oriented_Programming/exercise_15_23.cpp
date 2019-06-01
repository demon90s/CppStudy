// 练习15.23：假设第550页的D1类需要覆盖它继承而来的fcn函数，你应该如何对其
// 进行修改？如果你修改之后fcn匹配了Base中的定义，则该节的那些调用语句将如
// 何解析？

#include <iostream>

#define USE_VAR(x) ((void)&(x))

using namespace std;

class Base {
public:
	virtual int fcn() { cout << "Base::fcn()" << endl; return 0; }
};

class D1 : public Base {
public:
	// 隐藏基类的fcn，这个fcn不是虚函数
	// D1继承了Base::fcn()的定义
	int fcn(int) { cout << "D1::fcn(int)" << endl; return 0; }			// 形参列表与Base中的fcn不一致
	virtual void f2() { cout << "D1::f2()" << endl; }					// 是一个新的虚函数，在Base中不存在

	int fcn() override { cout << "D1::fcn()" << endl; return 0; };		// 练习
};

class D2 : public D1 {
public:
	int fcn(int) { cout << "D2::fcn(int)" << endl; return 0; }			// 是一个非虚函数，隐藏了D1::fcn(int);
	int fcn() { cout << "D2::fcn()" << endl; return 0; }				// 覆盖了Base的虚函数fcn
	void f2() { cout << "D2::f2()" << endl; }							// 覆盖了D1的虚函数f2
};

int main()
{
	Base bobj; D1 d1obj; D2 d2obj;

	Base *bp1 = &bobj, *bp2 = &d1obj, *bp3 = &d2obj;
	bp1->fcn();		// 虚调用，将在运行时调用Base::fcn
	bp2->fcn();		// 虚调用，将在运行时调用D1::fcn
	bp3->fcn();		// 虚调用，将在运行时调用D2::fcn

	D1 *d1p = &d1obj; D2 *d2p = &d2obj;
	//bp2->f2();	// 错误：Base没有名为f2的成员
	d1p->f2();		// 虚调用，将在运行时调用D1::f2()	
	d2p->f2();		// 虚调用，将在运行时调用D2::f2()

	Base *p1 = &d2obj; D1 *p2 = &d2obj; D2 *p3 = &d2obj;
	//p1->fcn(42);	// 错误：Base中没有接受一个int的fcn
	p2->fcn(42);	// 静态绑定，调用D1::fcn(int)
	p3->fcn(42);	// 静态绑定，调用D2::fcn(int)

	// ignore for warning
	USE_VAR(p1);

	return 0;
}
