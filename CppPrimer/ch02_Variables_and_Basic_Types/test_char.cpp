#include <iostream>

int main()
{
	// 测试char的实际表现类型（signed or unsigned）
	char a = -1;
	if (a < 0)
		std::cout << "On this compiler, char is signed" << std::endl;
	else
		std::cout << "On this compiler, char is unsigned" << std::endl;

	return 0;
}
