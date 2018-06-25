// example: 主函数main的返回值（p203）

#include <cstdlib>

int main()
{
	bool some_failure = true;
	if (some_failure)
		return EXIT_FAILURE;
	else
		return EXIT_SUCCESS;
}
