#include "../Chapter6.h"

int fact(int n)
{
	int ret = 1;
	for (; n > 1; --n)
		ret *= n;

	return ret;
}

