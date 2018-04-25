// 练习15.19：假设543页和544页的每个类都有如下形式的成员函数u：
/*
void memfcn(Base &b) { b = *this; }

对于每个类，分别判断上面的函数是否合法。

Base: 合法

Sneaky: 合法，但只会拷贝其基类部分

Pal: 非法，不存在类型转换规则

Pub_Derv: 合法

Priv_Derv: 合法

Derived_from_Public: 合法

Derived_from_Private: 非法，Base::Base is inaccessible
*/

#include <iostream>

class Base {
	// 添加friend声明，其他成员与之前的版本一致
	friend class Pal;				// Pal在访问Base的派生类时不具有特殊性
public:
	void pub_mem() {}				// public成员

protected:
	int prot_mem;					// protected成员

private:
	char priv_mem;					// private成员

	void memfcn(Base &b) { b = *this; }
};

class Sneaky : public Base {
	friend void clobber(Sneaky&);	// 能访问Sneaky::prot_mem
	friend void clobber(Base&);		// 不能访问Base::prot_mem
	int j;							// j默认是private
	void memfcn(Base &b) { b = *this; }
};

class Pal {
public:
	int f(Base b) { return b.prot_mem; }	// 正确：Pal是Base的友元
	//int f2(Sneaky s) { return s.j; }		// 错误：Pal不是Sneaky的友元

	// 对基类的访问权限由基类本身控制，即使对于派生类的基类部分也是如此
	int f3(Sneaky s) { return s.prot_mem; }	// 正确：Pal是Base的友元
	//void memfcn(Base &b) { b = *this; }
};

class Pub_Derv : public Base {
	// 正确：派生类能访问protected成员
	int f() { return prot_mem; }
	
	// 错误：private成员对于派生类来说是不可访问的
	//char g() { return priv_mem; }
	void memfcn(Base &b) { b = *this; }
};

class Priv_Derv : private Base {
	// private不影响派生类的访问权限
	int f1() const { return prot_mem; }
	void memfcn(Base &b) { b = *this; }
};

struct Derived_from_Public : public Pub_Derv {
	// 正确：Base::prot_mem在Pub_Derv中仍然是protected的
	int use_base() { return prot_mem; }
	void memfcn(Base &b) { b = *this; }
};

struct Derive_from_Private : public Priv_Derv {
	// 错误：Base::prot_mem在Priv_Derv中是private的
	//int use_base() { return prot_mem; }

	//void memfcn(Base &b) { b = *this; }
};

// 正确：clobber能访问Sneaky对象的private和protected成员
void clobber(Sneaky &s) { s.j = s.prot_mem = 0; }

// 错误：clobber不能访问Base的protected成员
//void clobber(Base &b) { b.prot_mem = 0; }

int main()
{
	return 0;
}
