// 练习17.37：用未格式化版本的getline逐行读取一个文件。测试你的程序，给它一个
// 文件，既包含空行又包含长度超过你传递给getline的字符数组大小的行。

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream ifs("../data/little_story.txt");
	if (!ifs)
	{
		cerr << "open file failed" << endl;
		return -1;
	}

	char buffer[40] = {0};
	while (ifs.getline(buffer, sizeof(buffer), '\n')) // 如果buffer长度不够，并还未遇到分隔符，那么流会处于failbit状态
	{
		cout << buffer << endl;
	}

	return 0;
}
