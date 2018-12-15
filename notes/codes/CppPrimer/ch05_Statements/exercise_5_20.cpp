/*
 * 练习5.20：编写一段程序，从标准输入中读取string对象的序列直到连续出
 * 现两个相同的单词或者所有单词都读完为止。使用while循环一次读取一个单
 * 词，当一个单词连续出现两次时使用break语句终止循环。输出连续重复出现
 * 的单词，或者输出一个消息说明没有任何单词是连续重复出现的。
 */

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;

int main()
{
	string cur_str, pre_str;
	bool is_repeat = false;

	while (cin >> cur_str) {
		if (pre_str == cur_str) {
			is_repeat = true;
			break;
		}

		pre_str = cur_str;
	}

	if (is_repeat)
		cout << cur_str << endl;
	else
		cout << "no word repeat" << endl;

	return 0;
}
