/*
 * 练习5.14：编写一段程序，从标准输入中读取若干string对象并查找连续重复出现的单词。所谓连续重复出现的意思是：一个单词后面紧跟着这个单词本身。要求记录连续重复出现的最大次数以及对应的单词。如果这样的单词存在，输出重复出现的最大次数；如果不存在，输出一条信息说明任何单词都没有连续出现过。例如：如果输入是
 *
 * how now now now brown cow cow
 *
 * 那么输出应该表明单词now连续出现了3次。
 */

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;

int main()
{
	string cur_str, pre_str, max_repeat_count_str;
	int cur_repeat_count = 1, max_repeat_count = 1;

	while (cin >> cur_str) {
		if (pre_str == cur_str) {
			++cur_repeat_count;
			if (cur_repeat_count > max_repeat_count) {
				max_repeat_count = cur_repeat_count;
				max_repeat_count_str = cur_str;
			}
		}
		else {
			cur_repeat_count = 1;
		}

		pre_str = cur_str;
	}

	if (max_repeat_count > 1) {
		cout << max_repeat_count_str << " repeat " << max_repeat_count << " times" << endl;
	}
	else {
		cout << "No word repeat" << endl;
	}

	return 0;
}
