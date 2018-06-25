// 练习17.33：修改11.3.6节（第392页）中的单词转换程序，允许对一个给定单词有多种
// 转换方式，每次随机选择一种进行实际转换。

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <stdexcept>
#include <sstream>
#include <vector>
#include <cstring>
#include <random>

using namespace std;

// 格式：k okay?:ok?
// 即用符号:进行分隔

void ParseParam(const char *str, std::vector<std::string> &result, const char *delim)
{
	char *temp = (char*)malloc(strlen(str) + 1);
	
	strncpy(temp, str, strlen(str) + 1);
	result.clear();

	char *token = strtok(temp, delim);
	while (token)
	{
		result.push_back(token);
		token = strtok(NULL, delim);
	}

	free(temp);
}

map<string, std::vector<string>> buildMap(ifstream &map_file)
{
	map<string, std::vector<string>> trans_map;	// 保存转换规则
	string key;		// 要转换的单词
	string value;	// 替换后的内容

	// 读取第一个单词存入key中，行中剩余内容存入value
	while (map_file >> key && getline(map_file, value))
	{
		char buffer[1024] = {0};
		strncpy(buffer, value.substr(1).c_str(), sizeof(buffer)); // substr(1)用于跳过前导空格
		std::vector<std::string> result;

		ParseParam(buffer, result, ":");
		if (result.empty())
		{
			throw runtime_error("no rule for " + key);
		}

		trans_map[key] = result;
	}

	return trans_map;
}

// 获取替换文本序列中的一个文本
const string& Random(const std::vector<std::string> &trans_word)
{
	if (trans_word.empty())
	{
		throw runtime_error("trans_word is empty");
	}

	static default_random_engine e(time(0));

	return trans_word[e() % trans_word.size()];
}

const string& transform(const string &s, const map<string, std::vector<string>> &m)
{
	// 实际的转换工作；此部分是程序的核心
	auto map_it = m.find(s);

	// 如果单词在转换规则中map中
	if (map_it != m.cend())
		return Random(map_it->second);	// 使用替换短语
	else
		return s;				// 否则返回原string
}

void word_transform(ifstream &map_file, ifstream &input)
{
	auto trans_map = buildMap(map_file);	// 保存转换规则
	string text;							// 保存输入中的每一行
	while (getline(input, text)) {			// 读取一行输入
		istringstream stream(text);			// 读取每个单词
		string word;
		bool firstword = true;				// 控制是否打印空格
		while (stream >> word) {
			if (firstword)
				firstword = false;
			else
				cout << " ";				// 在单词间打印一个空格
			// transform返回它的第一个参数或其转换之后的形式
			cout << transform(word, trans_map); // 打印输出
		}
		cout << endl;						// 完成一行的转换
	}
}

int main()
{
	ifstream rule_ifs("data/trans_rules.txt");
	ifstream input_ifs("data/test_rules.txt");
	if (!rule_ifs || !input_ifs)
	{
		cerr << "fail open fail" << endl;
		return 1;
	}

	word_transform(rule_ifs, input_ifs);

	return 0;
}
