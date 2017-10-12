#include "utility.h"
#include <iostream>
#include <cstddef>

using std::cout;
using std::endl;

int main()
{
	// 测试求数组元素的数量
	{
		int arr[7 * 8] = {};
		ptrdiff_t sz = ARRAY_ITEM_NUM(arr);
		cout << "arr sz: " << sz << endl;
	}

	return 0;
}
