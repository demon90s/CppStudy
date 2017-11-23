/*
 * 练习8.11：本节的程序在外层while循环中定义了istringstream对象。如果
 * record对象定义在循环之外，你需要对程序进行怎样的修改？重写程序，将
 * record的定义移到while循环之外，验证你设想的修改方法是否正确。
 */

// ./exercise_8_11 < data/person_numbers.txt

#include <iostream>
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

	istringstream record;	
	// 逐行从输入读取数据，直至cin遇到文件尾（或其他错误）
	while (getline(cin, line)) {
		PersonInfo info;		// 创建一个保存此记录的对象
		record.str(line);		// 将记录绑定到刚读入的行
		record >> info.name;	// 读取名字
		while (record >> word)	// 读取电话号码
			info.phones.push_back(word);	// 保存它们
		people.push_back(info);	// 将此记录追加到people末尾

		// 如果不复位条件状态位，那么将不能继续读取
		record.clear();
	}

	// 输出验证
	for (const auto &person_info : people)
		print(person_info);

	return 0;
}
