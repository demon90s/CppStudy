#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

int main()
{
	string str("some string");
	// 每行输出str中的一个字符
	for (auto c : str)
		cout << c << endl;

	return 0;
}
