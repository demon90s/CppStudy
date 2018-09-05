#include "rule09.h"

extern void Rule09()
{
	{
		using namespace bug;
		BuyTransaction b; // 不会调用派生类的logTransaction，因其还未构造
	}

	{
		using namespace correct;
		BuyTransaction b;
	}
}