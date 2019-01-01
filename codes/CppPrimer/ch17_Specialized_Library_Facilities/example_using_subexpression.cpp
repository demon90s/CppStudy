// example: 使用子表达式（p653）

#include <iostream>
#include <regex>

using namespace std;

int main()
{
	std::string filename("foo.cpp");

	// r有两个子表达式：第一个是点之前表示文件名的部分，第二个表示文件扩展名
	regex r("([[:alnum:]]+)\\.(cpp|cxx|cc)$", regex::icase);

	smatch results;

	if (regex_search(filename, results, r))
	{
		cout << results.str(1) << endl;// 打印第一个子表达式
	}

	return 0;
}
