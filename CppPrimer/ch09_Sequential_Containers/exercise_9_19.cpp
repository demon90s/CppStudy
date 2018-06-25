// 练习9.19：重写上题的程序，用list替代lstue。列出程序要做出哪些改变。

// 只需要改一下容器的名字就可以了

#include <iostream>
#include <string>
#include <list>

using namespace std;

int main()
{
	list<string> str_lst;
	string word;

	while (cin >> word)
		str_lst.push_back(word);

	for (auto it = str_lst.cbegin(); it != str_lst.cend(); ++it)
		cout << *it << " ";
	cout << endl;

	return 0;
}
