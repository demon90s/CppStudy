/*
 * 练习8.5：重写上面的程序，将每个单词作为一个独立的元素进行存储。
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void read_func(const string &file, vector<string> &word_vec)
{
	ifstream in(file);
	if (!in) return;

	string word;
	while (in >> word)
		word_vec.push_back(word);

	in.close();
}

int main()
{
	vector<string> word_vec;
	read_func("./exercise_8_04.cpp", word_vec);

	// 输出验证
	for (auto &w : word_vec)
		cout << w << endl;

	return 0;
}
