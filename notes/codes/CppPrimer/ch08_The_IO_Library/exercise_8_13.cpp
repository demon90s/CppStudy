// 练习8.13：重写本节的电话号码程序，从一个命名文件而非cin读取数据。

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

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
		cout << number << " ";

	cout << endl;
}

int main()
{
	string line, word;			// 分别保存输入的一行和的单词
	vector<PersonInfo> people;	// 保存来自输入的所有记录

	ifstream ifs("./data/person_numbers.txt");
	if (!ifs) return 1;

	// 逐行从输入读取数据，直至cin遇到文件尾（或其他错误）
	while (getline(ifs, line)) {
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
