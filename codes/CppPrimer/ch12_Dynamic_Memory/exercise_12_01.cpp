// 练习12.1：在此代码的结尾，b1和b2各包含多少个元素？

#include <iostream>

#include "example_StrBlob/StrBlob.h"

using namespace std;

int main()
{
	StrBlob b1;
	{
		StrBlob b2 = {"a", "an", "the"};
		b1 = b2;
		b2.push_back("about");
		
		// b1和b2共享底层数据，都包含4个元素
		cout << "b1 size: " << b1.size() << endl;
		cout << "b2 size: " << b2.size() << endl;
	}

	return 0;
}
