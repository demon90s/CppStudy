// 练习17.14：编写几个正则表达式，分别触发不同错误。运行你的程序，观察编译器
// 对每个错误的输出。

#include <iostream>
#include <regex>

using namespace std;

void error1()
{
	// 运行时错误，错误的正则表达式，构造时抛出异常
	regex r("[[:alnum:]");
}

void error2()
{
	regex r("cpp");
	//smatch results;	// 输入序列与match参数类型不匹配，编译报错
	cmatch results;		// OK
	
	if (regex_search("cc", results, r))
	{
	}
}

int main()
{
	error1();

	return 0;
}
