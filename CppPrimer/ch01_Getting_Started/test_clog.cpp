// $ 以下命令说明clog关联到标准错误
// $ ./test_clog 2> /dev/null
// $ ./test_clog > /dev/null
// $ ./test_clog

#include <iostream>

int main()
{
	std::clog << "This is a log message" << std::endl;

	return 0;
}
