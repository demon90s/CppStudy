#include "rule08.h"
#include <vector>

extern void Rule08()
{
	// Widget的析构函数抛出了异常，外部没办法捕获
	/*try
	{
		std::vector<Widget> v;
		v.resize(1);
	}
	catch (std::runtime_error e)
	{
		std::cout << "receive runtime_error: " << e.what() << std::endl;
	}*/

	{
		DBConn dbc(DBConnection::create());

		try
		{
			dbc.close();
		}
		catch (std::runtime_error e)
		{
			std::cout << "dbc.close: " << e.what() << std::endl;
			std::abort();
		}
	}
}