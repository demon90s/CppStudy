// 练习19.6：编写一条表达式将Query_base指针动态转换为AndQuery指针（参见15.9.1节，第564页）。
// 分别使用AndQuery的对象以及其他类型的对象测试转换是否有效。打印一条表示类型转换是否成功
// 的信息，确保实际输出的结果与期望的一致。

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
	Query_base *base_ptr = new Query_base;

	{
		AndQuery cmp_obj;
		AndQuery *derived_ptr = dynamic_cast<AndQuery*>(base_ptr);	
		if (derived_ptr && typeid(*derived_ptr) == typeid(cmp_obj))
		{
			std::cout << "Query_base* -> AndQuery* succ" << std::endl;
		}
		else
		{
			std::cout << "Query_base* -> AndQuery* failed" << std::endl;
		}	
	}

	{
		Query_base cmp_obj;
		Query_base *ptr = dynamic_cast<Query_base*>(base_ptr);	
		if (ptr && typeid(*ptr) == typeid(cmp_obj))
		{
			std::cout << "Query_base* -> Query_base* succ" << std::endl;
		}
		else
		{
			std::cout << "Query_base* -> Query_base* failed" << std::endl;
		}	
	}

	delete base_ptr;

	return 0;
}
