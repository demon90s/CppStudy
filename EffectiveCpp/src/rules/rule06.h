// 条款06：若不想使用编译器自动生成的函数，就该明确拒绝
#ifndef __RULE06_H__
#define __RULE06_H__

extern void Rule06();

// 常用的方法：将成员声明成私有且不定义
class HomeForSale
{
public:
	HomeForSale() {}

private:
	HomeForSale(const HomeForSale&);
	HomeForSale& operator=(const HomeForSale&);
};

// 另一种方法：单独定义一个不可拷贝的empty base class，令其他类继承
class Uncopyable
{
protected:
	Uncopyable() {}			// 允许derived对象构造和析构
	~Uncopyable() {}

private:
	Uncopyable(const Uncopyable&);		// 阻止copying
	Uncopyable& operator=(const Uncopyable&);
};

class HomeForSale2 : public Uncopyable
{
public:
	HomeForSale2() {}
	~HomeForSale2() {}
};

#endif // __RULE06_H__