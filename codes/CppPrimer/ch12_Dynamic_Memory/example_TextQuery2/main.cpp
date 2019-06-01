// 练习19.20：将QueryResult类型嵌套在TextQuery中。

#include <fstream>
#include <iostream>
#include <string>

#include "TextQuery.h"
#include "QueryResult.h"

using namespace std;

void runQueries(ifstream &infile)
{
	// infile是一个ifstream，指向我们要处理的文件
	TextQuery tq(infile); // 保存文件并建立查询map

	// 与用户交互，提示用户输入要查询的单词，完成查询并打印结果
	while (true)
	{
		cout << "Enter word to look for, or q to quit: ";
		string s;
		// 若遇到了文件尾或用户输入了q时循环终止
		if (!(cin >> s) || s == "q") break;

		// 指向查询并打印结果
		print(cout, tq.query(s)) << endl;
	}
}

int main()
{
	ifstream infile("../../data/some_words.txt");
	if (!infile)
	{
		cout << "Cant open file" << endl;
		return 1;
	}

	runQueries(infile);

	return 0;
}
