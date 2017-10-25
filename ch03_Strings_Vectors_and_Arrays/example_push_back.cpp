// example: 向vector对象中添加元素（p90）
// 从标准输入中读取单词，将其作为vector对象的元素存储

#include <string>
#include <iostream>
#include <vector>

using std::cin;
using std::string;
using std::vector;

int main()
{
	string word;
	vector<string> text;
	while (cin >> word) {
		text.push_back(word);	// 把word添加到text后面
	}

	return 0;
}
