/*
 * 练习5.21：修改5.5.1节（第171页）练习题的程序，使其找到的是重复单词必须以大写字母开头。
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
		if (islower(cur_str[0])) {
			continue;
		}

		if (pre_str == cur_str) {
			is_repeat = true;
			break;
		}
		else {
			pre_str = cur_str;
		}
	}

	if (is_repeat)
		cout << cur_str << endl;
	else
		cout << "no word repeat" << endl;

	return 0;
}
