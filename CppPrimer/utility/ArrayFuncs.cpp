#include "ArrayFuncs.h"
#include <iostream>

namespace utility
{

void Test_ArrayFuncs()
{
	int array[] = {42, 10, 5, 100, 2, 10};

	std::cout << "array item count: " << ArrayItemCount(array) << std::endl;

	std::cout << "is 1024 valid index: " << IsValidArrayIndex(array, 1024) << std::endl;

	std::cout << "is 0 valid index: " << IsValidArrayIndex(array, 0) << std::endl;

	auto item = GetArrayItem(array, 0);
	if (item)
	{
		std::cout << "array[0]: " << *item << std::endl;
	}

	if (SetArrayItem(array, 0, 10))
	{
		std::cout << "array[0]: " << *item << std::endl;
	}
}

}
