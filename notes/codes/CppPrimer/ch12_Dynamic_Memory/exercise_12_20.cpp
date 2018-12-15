// 练习12.20：编写程序，逐行读入一个输入文件，将内容存入一个StrBlob中，用
// 一个StrBlobPtr打印出StrBlob中的每个元素。

// g++ -g -Wall -std=c++11 exercise_12_20.cpp ./example_StrBlobPtr/StrBlobPtr.cpp -o exercise_12_20

#include <iostream>
#include <string>

#include "./example_StrBlobPtr/StrBlob.h"

using namespace std;

int main()
{
	StrBlob sb;
	string word;
	while (cin >> word)
	{
		sb.push_back(word);
	}

	auto beg = sb.begin();
	for (size_t i = 0; i < sb.size(); ++i)
	{
		cout << beg.deref() << endl;
		beg.incr();
	}

	return 0;
}
