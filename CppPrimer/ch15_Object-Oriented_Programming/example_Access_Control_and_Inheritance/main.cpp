// exmaple: 访问控制与继承（p543）

#include <iostream>
#include "classes.hpp"

using namespace std;

#define USE_VAR(x) ((void)&(x))

int main()
{
	Pub_Derv d1;		// 继承自Base的成员是public的
	Priv_Derv d2;		// 继承自Base的成员是private的
	d1.pub_mem();		// 正确：pub_mem在派生类中是public的
	//d2.pub_mem();		// 错误：pub_mem在派生类中是private的

	USE_VAR(d2);

	return 0;
}
