#include <iostream>

#include "raobjlist.h"

int main()
{
	RAObjList<int> obj_list;

	for (int i = 0; i < 10; ++ i)
	{
		obj_list.Insert(i);
		//std::cout << idx << std::endl;
	}

	obj_list.Erase(5);

	for (RAObjList<int>::Iterator it = obj_list.Beg(); it != obj_list.End(); ++ it)
	{
		std::cout << *it << std::endl;
	}

	return 0;
}
