// 条款05：了解C++默默编写并调用哪些函数

#ifndef __RULE05_H__
#define __RULE05_H__

#include <string>

extern void Rule05();

// class Empty {}; 几乎等价于下面的写法（当函数需要被调用时编译器会创建）

class Empty {};

class EmptyCustom {
public:
	EmptyCustom() {}								// default构造函数
	EmptyCustom(const EmptyCustom&) {}				// copy构造函数
	~EmptyCustom() {}								// 析构函数，只有当base class声明为虚时才是虚的
	EmptyCustom& operator=(const EmptyCustom&)		// copy assignment操作符
	{ /* ... */return *this; }
};

// 编译器为产出Empty成员函数
inline void Empty_Gen()
{
	Empty et1;							// default构造函数、析构函数
	Empty et2(et1);						// copy构造函数
	et2 = et1;							// copy assignment操作符
}

// 编译器可能会拒绝为class产出operator=（包含了没有赋值操作的引用类型和const类型）
template<class T>
class NamedObject {
public:
	NamedObject(std::string &_namedValue, const T& _objectValue) : 
		namedValue(_namedValue), objectValue(_objectValue) {}
private:
	std::string &namedValue;
	const T objectValue;
};

inline void NoCopyAssign()
{
	static std::string name = "Default NamedObject";
	NamedObject<int> no1(name, 0);
	NamedObject<int> no2(name, 0);
	
	//no2 = no1; 无法赋值，函数已删除
}

#endif // __RULE05_H__