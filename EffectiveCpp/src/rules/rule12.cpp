#include "rule12.h"

using namespace rule12;

extern void Rule12()
{
	Customer c1("c1");
	Customer c2(c1);
	c2 = c1;

	PriorityCustomer pc1("pc1", 1);
	PriorityCustomer pc2(pc1);
	pc2 = pc1;
}