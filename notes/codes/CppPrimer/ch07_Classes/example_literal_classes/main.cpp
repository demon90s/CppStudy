// example: 字面值常量类（p267）
// 字面值常量类也是一种字面值类型，可以用于常量表达式

#include <iostream>
#include "Debug.h"

using namespace std;

int main()
{
	constexpr Debug io_sub(false, true, false);		// 调试IO
	if (io_sub.any()) {		// 等价于if(true)
		cerr << "print appropriate error message" << endl;
	}

	constexpr Debug prod(false);
	if (prod.any()) {		// 等价于if(false)
		cerr << "print an error message" << endl;
	}

	return 0;
}
