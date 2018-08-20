#include "rule13.h"

using namespace rule13;

extern void Rule13()
{
	std::cout << "--------------------------bug\n";
	{
		bug();
	}
	
	std::cout << "--------------------------use_auto_ptr\n";
	{
		use_auto_ptr();
	}

	std::cout << "--------------------------use_shared_ptr\n";
	{
		use_shared_ptr();
	}

	std::cout << "--------------------------use_unique_ptr\n";
	{
		use_unique_ptr();
	}
}