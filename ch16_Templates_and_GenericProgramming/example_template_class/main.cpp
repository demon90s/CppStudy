// example: 类模板（p583）

#include <iostream>
#include "Blob.h"

using namespace std;

void func1()
{
	Blob<int> ia;
	Blob<int> ia2 = {0, 1, 2, 3, 4};
}

int main()
{
	return 0;
}
