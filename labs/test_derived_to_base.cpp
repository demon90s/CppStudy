// 测试：派生类向基类转换的可访问性

#include <iostream>

using namespace std;

#define USE_VAR(x) ((void)&(x))

class Base
{
protected:
	int prot_mem;
};

class Pub_Derived : public Base
{
	// 合法，无论以什么方式继承，派生类的成员和友元都能使用派生类向基类的转换
	void Convert()
	{
		Base *base_pointer = nullptr;
		Pub_Derived pub_derived;
		base_pointer = &pub_derived;
		USE_VAR(base_pointer);
	}
};

class Prot_Derived : protected Base
{
	// 合法，无论以什么方式继承，派生类的成员和友元都能使用派生类向基类的转换
	void Convert()
	{
		Base *base_pointer = nullptr;
		Prot_Derived prot_derived;
		base_pointer = &prot_derived;
		USE_VAR(base_pointer);
	}
};

class Priv_Derived : private Base
{
	// 合法，无论以什么方式继承，派生类的成员和友元都能使用派生类向基类的转换
	void Convert()
	{
		Base *base_pointer = nullptr;
		Priv_Derived priv_derived;
		base_pointer = &priv_derived;
		USE_VAR(base_pointer);
	}
};

int main()
{
	Base *base_pointer = nullptr;

	Pub_Derived pub_derived;
	base_pointer = &pub_derived; // 合法

	Prot_Derived prot_derived;
	//base_pointer = &prot_derived; // 错误，只有公有继承，用户代码才能使用派生类向基类的转换
	
	Priv_Derived priv_derived;
	//base_pointer = &priv_derived; // 错误，有公有继承，用户代码才能使用派生类向基类的转换

	USE_VAR(base_pointer);
	USE_VAR(prot_derived);
	USE_VAR(priv_derived);

	return 0;
}
