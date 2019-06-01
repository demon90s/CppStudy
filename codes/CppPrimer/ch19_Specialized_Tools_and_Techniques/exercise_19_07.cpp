// 练习19.7：编写与上一个练习类似的转换，这一次将Query_base对象转换为
// AndQuery的引用。重复上面的测试过程，确保转换能正常工作。

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

		try {
			AndQuery &derived_ref = dynamic_cast<AndQuery&>(*base_ptr);
			if (typeid(derived_ref) == typeid(cmp_obj))
			{
				std::cout << "Query_base& -> AndQuery& succ" << std::endl;
			}
			else
			{
				std::cout << "Query_base& -> AndQuery& failed" << std::endl;
			}	
		} catch (std::bad_cast e) {
			std::cout << "Query_base& -> AndQuery& failed: " << e.what() << std::endl;
		}
	}

	{
		Query_base cmp_obj;

		try {
			Query_base &ref = dynamic_cast<Query_base&>(*base_ptr);	
			if (typeid(ref) == typeid(cmp_obj))
			{
				std::cout << "Query_base& -> Query_base& succ" << std::endl;
			}
			else
			{
				std::cout << "Query_base& -> Query_base& failed" << std::endl;
			}	
		} catch (std::bad_cast e) {
			std::cout << "Query_base& -> Query_base& failed: " << e.what() << std::endl;
		}
	}

	delete base_ptr;

	return 0;
}
