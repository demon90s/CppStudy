// example: 使用预处理变量输出错误信息（p216）

#include <iostream>

using std::cerr;
using std::endl;

void error_msg(const char *msg)
{
	cerr << "Error: " << __FILE__
	     << " : in function " << __func__
		 << " at line " << __LINE__ << endl
		 << "    Compiled on " << __DATE__
		 << " at " << __TIME__ << endl
		 << "    error_msg: " << msg << endl;
}

int main()
{
	error_msg("something wrong");

	return 0;
}
