/*
 * 练习3.2：编写一段程序从标准输入中一次读入一整行，然后修改该程序使其一次读入一个词。
 */

// ./exercise_3_02 < exercise_3_02.cpp

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
/*
int main()
{
	string line;
	while (getline(cin, line))
		cout << line << endl;

	return 0;
}*/

int main()
{
	string word;
	while (cin >> word)
		cout << word << endl;

	return 0;
}
