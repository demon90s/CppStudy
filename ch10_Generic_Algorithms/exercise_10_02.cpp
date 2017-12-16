// 练习10.2：重做上一题，但读取string序列存入list中。

#include <iostream>
#include <list>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	list<string> slist;
	string word;
	while (cin >> word)
		slist.push_back(word);

	string v = "hi";
	cout << count(slist.begin(), slist.end(), v) << endl;

	return 0;
}
