// example: 使用insert的返回值（p308）

#include <iostream>
#include <string>
#include <list>

using namespace std;

int main()
{
	list<string> lst;
	string word;

	auto it = lst.begin();
	while (cin >> word)
		it = lst.insert(it, word);    // 等价于调用push_front

	// 输出验证（反序输出）
	for (const auto &s : lst)
		cout << s << " ";
	cout << endl;

	return 0;
}
