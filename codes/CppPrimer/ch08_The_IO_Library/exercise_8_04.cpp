/*
 * 练习8.4：编写函数，以读模式打开一个文件，将其内容都入到一个string的vector中，
 * 将每一行作为一个独立的元素存于vector中。
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void read_func(const string &file, vector<string> &line_vec)
{
	ifstream in(file);
	if (!in) return;

	string line;
	while (getline(in, line))
		line_vec.push_back(line);

	in.close();
}

int main()
{
	vector<string> line_vec;
	read_func("./exercise_8_04.cpp", line_vec);

	// 输出验证
	for (auto &l : line_vec)
		cout << l << endl;

	return 0;
}
