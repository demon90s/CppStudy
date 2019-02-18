/*
 一致性初始化（ Uniform Initialization ）

 即面对何初始化动作，都可以使用大括号来初始化，若不设定初值，采用值初始化。

 对于“窄化”，使用大括号初始化将被拒绝。
*/

#include <vector>
#include <string>

void examples()
{
	int values[] {1, 2, 3};
	std::vector<int> v{1, 2, 3};
	std::vector<std::string> {"Berlin", "New York", "London"};

	int i{};	// i = 0
	int *p{};	// p = nullptr

	// 窄化
	int x{5.0};	// ERROR: narrowing, but on my computer, just warning
	char c{9999};	// narrowing
	
	(void)values;
	(void)i;
	(void)p;
	(void)x;
	(void)c;
}

int main()
{
	examples();

	return 0;
}
