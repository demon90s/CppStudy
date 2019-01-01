// example: 链接指示，extern "C"（758）

#include <iostream>

using namespace std;

extern "C" int strlen_custom(const char *str);

int main()
{
	cout << strlen_custom("Hello World") << endl;

	return 0;
}
