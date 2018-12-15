// 练习19.8：编写一条typeid表达式检查两个Query_base对象是否指向同一种类型。
// 再检查该类型是否是AndQuery。

#include <iostream>
#include <typeinfo>

class Query_base
{
public:
	virtual ~Query_base() {}
};

class AndQuery : public Query_base
{
};

int main()
{
	AndQuery aq1, aq2;
	Query_base *p1 = &aq1, *p2 = &aq2;

	if (typeid(*p1) == typeid(*p2))
		std::cout << "same type" << std::endl;

	if (typeid(*p1) == typeid(AndQuery))
		std::cout << "type is AndQuery" << std::endl;

	return 0;
}
