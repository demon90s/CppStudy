// 练习17.21：使用本节中定义的valid函数重写8.3.2节（第289页）中的电话号码程序。

// ./exercise_17_21 < ../data/person_numbers.txt

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <regex>

using namespace std;

bool valid(const smatch &m)
{
	// 在一个合法的电话号码中，区号要么是完整括号包围的，要么完全没有括号。
	// 如果区号前有一个左括号
	if (m[1].matched)
	{
		// 则区号后必须有一个右括号，之后紧跟剩余号码或一个空格
		return m[3].matched && (m[4].matched == 0 || m[4].str() == " ");
	}
	else
	{
		// 否则，区号后不能有右括号
		// 另外两个组成部分间的分隔符必须匹配
		return !m[3].matched && m[4].str() == m[6].str();
	}

	return false;
}


// 检查电话号码是否合法
bool CheckPhoneNumber(const string &phone_number)
{
	string phone = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})";

	/*
	 * e.g. (555)1234567
	 *      ^^  ^^  ^
	 *      12  35  7
	 *
	 * 1. (\\()? 表示区号部分可选的左括号
	 * 2. (\\d{3}) 表示区号
	 * 3. (\\))? 表示区号部分可选的右括号
	 * 4. ([-. ])? 表示区号部分可选的分隔符
	 * 5. (\\d{3}) 表示号码的下三位数字
	 * 6. ([-. ])? 表示可选的分隔符
	 * 7. (\\d{4}) 表示号码的最后四位数字
	 */

	regex r(phone);	// regex对象，用于查找我们的模式
	smatch m;

	// 对每个匹配的电话号码
	for (sregex_iterator it(phone_number.begin(), phone_number.end(), r), end_it; it != end_it; ++it)
	{
		// 检查号码格式是否合法
		return valid(*it);
	}

	return false;
}


// 保存一个人的电话号码
struct PersonInfo {
	string name;
	vector<string> phones;
};

// 输出记录
void print(const PersonInfo &info)
{
	cout << info.name << " ";
	for (const auto &number : info.phones)
		cout << number << "(" << (CheckPhoneNumber(number) ? "valid" : "invalid") << ")" << " ";

	cout << endl;
}

int main()
{
	string line, word;			// 分别保存输入的一行和的单词
	vector<PersonInfo> people;	// 保存来自输入的所有记录

	// 逐行从输入读取数据，直至cin遇到文件尾（或其他错误）
	while (getline(cin, line)) {
		PersonInfo info;		// 创建一个保存此记录的对象
		istringstream record(line);	// 将记录绑定到刚读入的行
		record >> info.name;	// 读取名字
		while (record >> word)	// 读取电话号码
			info.phones.push_back(word);	// 保存它们
		people.push_back(info);	// 将此记录追加到people末尾
	}

	// 输出验证
	for (const auto &person_info : people)
		print(person_info);

	return 0;
}
