// example: weak_ptr的一个例子(p421)

#include <iostream>

#include "StrBlob.h"

using namespace std;

void func1()
{
	StrBlob a1 = {"hi", "bye", "now"};
	StrBlobPtr p(a1);
	*p = "okay";
	cout << p->size() << endl; // 4，okey长度是4
}

int main()
{
	func1();

	return 0;
}
