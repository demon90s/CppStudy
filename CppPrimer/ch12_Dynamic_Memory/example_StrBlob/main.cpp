// example: 使用智能指针共享底层数据(p405)

#include <iostream>

#include "StrBlob.h"

using namespace std;

int main()
{
	StrBlob b1({"a", "b", "c"});
	StrBlob b2({"a", "b", "c"});
	StrBlob b3({"b"});

	if (b1 == b2)
		cout << "b1 == b2" << endl;

	if (b2 < b3)
		cout << "b2 < b3" << endl;
	
	return 0;
}
