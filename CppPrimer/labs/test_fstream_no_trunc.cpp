// test: 使用fstream流操作文件，看看文件是否会被截断
// result: 不会被截断，且从开始位置读写

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	fstream fs("./data/some_words.txt");
	string line;

	while (getline(fs, line))
		cout << line << endl;

	return 0;
}
