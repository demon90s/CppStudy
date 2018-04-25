#ifndef __CLASSES_HPP__
#define __CLASSES_HPP__

class Base {
	// 添加friend声明，其他成员与之前的版本一致
	friend class Pal;				// Pal在访问Base的派生类时不具有特殊性
public:
	void pub_mem() {}				// public成员

protected:
	int prot_mem;					// protected成员

private:
	char priv_mem;					// private成员
};

class Sneaky : public Base {
	friend void clobber(Sneaky&);	// 能访问Sneaky::prot_mem
	friend void clobber(Base&);		// 不能访问Base::prot_mem
	int j;							// j默认是private
};

class Pal {
public:
	int f(Base b) { return b.prot_mem; }	// 正确：Pal是Base的友元
	//int f2(Sneaky s) { return s.j; }		// 错误：Pal不是Sneaky的友元

	// 对基类的访问权限由基类本身控制，即使对于派生类的基类部分也是如此
	int f3(Sneaky s) { return s.prot_mem; }	// 正确：Pal是Base的友元
};

class Pub_Derv : public Base {
	// 正确：派生类能访问protected成员
	int f() { return prot_mem; }
	
	// 错误：private成员对于派生类来说是不可访问的
	//char g() { return priv_mem; }
};

class Priv_Derv : private Base {
	// private不影响派生类的访问权限
	int f1() const { return prot_mem; }
};

class Prot_Derv : protected Base {
	// private不影响派生类的访问权限
	int f1() const { return prot_mem; }
};

struct Derived_from_Public : public Pub_Derv {
	// 正确：Base::prot_mem在Pub_Derv中仍然是protected的
	int use_base() { return prot_mem; }
};

struct Derived_from_Private : public Priv_Derv {
	// 错误：Base::prot_mem在Priv_Derv中是private的
	//int use_base() { return prot_mem; }
};

struct Derived_from_Protected : public Prot_Derv {
	// 正确：Base::prot_mem在Prot_Derv中仍然是protected的
	int use_base() { return prot_mem; }
};

// 正确：clobber能访问Sneaky对象的private和protected成员
void clobber(Sneaky &s) { s.j = s.prot_mem = 0; }

// 错误：clobber不能访问Base的protected成员
//void clobber(Base &b) { b.prot_mem = 0; }

#endif // __CLASSES_HPP__
