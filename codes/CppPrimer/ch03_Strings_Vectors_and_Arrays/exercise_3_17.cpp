/*
 * 从cin读入一组词并把它们存入一个vector对象，然后设法把所有词都改写为大写形式。输出改变后的结果，每个词占一行。
 */

#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::cin;

int main()
{
	vector<string> svec;
	string word;

	while (cin >> word)
		svec.push_back(word);
	
	for (auto &w : svec) {
		for (auto &c : w) {
			c = toupper(c);
		}
	}

	for (const auto &w : svec)
		cout << w << endl;

	return 0;
}
