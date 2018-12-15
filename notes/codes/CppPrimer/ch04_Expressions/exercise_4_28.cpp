/*
 * 4.28：编写一段程序，输出每一种内置类型所占空间的大小。
 */

#include <iostream>

using std::cout;
using std::endl;
using std::cin;

#define PRINT_BUILTIN_TYPES_SIZE(type) \
do { \
	cout << #type << " size is: "; \
	cout << sizeof(type) << endl; \
} while(0) \

int main()
{
	PRINT_BUILTIN_TYPES_SIZE(char);
	PRINT_BUILTIN_TYPES_SIZE(short);
	PRINT_BUILTIN_TYPES_SIZE(int);
	PRINT_BUILTIN_TYPES_SIZE(long);
	PRINT_BUILTIN_TYPES_SIZE(long long);
	PRINT_BUILTIN_TYPES_SIZE(bool);
	PRINT_BUILTIN_TYPES_SIZE(float);
	PRINT_BUILTIN_TYPES_SIZE(double);
	PRINT_BUILTIN_TYPES_SIZE(long double);
	PRINT_BUILTIN_TYPES_SIZE(void*);

	return 0;
}
