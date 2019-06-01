/*
 * 练习6.44：将6.2.2节（第189页）的isShorter函数改写成内联函数。
 */

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;

// 比较两个string对象的长度
inline
bool isShorter(const string &s1, const string &s2)
{
	return s1.size() < s2.size();
}

int main()
{
	cout << isShorter("Hello", "Hi") << endl;

	return 0;
}
