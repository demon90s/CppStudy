// 练习15.18：假设给定了第543页和第544页的类，同时已知每个对象的类型如注释所示，判断下面的哪些赋值语句是合法的。解释那些不合法的语句为什么不被允许：

/*
Base *p = &d1;	// d1的类型是Pub_Derv，合法
p = &d2;		// d2的类型是Priv_Derv，非法，非公有继承
p = &d3;		// d3的类型是Prot_Derv，非法，非公有继承
p = &dd1;		// dd1的类型是Derived_from_Public，合法
p = &dd2;		// dd2的类型是Derived_from_Private，非法，非公有继承
p = &dd3;		// dd3的类型是Derived_from_Protected，非法，非公有继承
*/

#include <iostream>
#include "./example_Access_Control_and_Inheritance/classes.hpp"

#define USE_VAR(x) ((void)&(x))

int main()
{
	Pub_Derv d1;
	Priv_Derv d2;
	Prot_Derv d3;
	Derived_from_Public dd1;
	Derived_from_Private dd2;
	Derived_from_Protected dd3;

	Base *p = &d1;
	//p = &d2;
	//p = &d3;
	p = &dd1;
	//p = &dd2;
	//p = &dd3;
	


	// ignore warning
	USE_VAR(d2);
	USE_VAR(d3);
	USE_VAR(dd2);
	USE_VAR(dd3);
	USE_VAR(p);

	return 0;
}
