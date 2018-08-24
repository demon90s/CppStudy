#include "rule07.h"
#include <iostream>

extern void Rule07()
{
	{
		TimeKeeper *ptk = getTimerKeeper();

		// ...

		delete ptk;
	}
	
	std::cout << "bits of Point: " << sizeof(Point) * 8 << std::endl;
}