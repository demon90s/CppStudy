// 练习11.13：在上一题的程序中，至少有三种创建pair的方法。编写此程序的三
// 个版本，分别采用不同的方法创建pair。解释你认为哪种形式最易于编写和理解，
// 为什么？

// 练习11.12：编写程序，读入string和int的序列，将每个string和int存入一个
// pair中，pair保存在一个vector中。

#include <iostream>
#include <utility>
#include <string>
#include <vector>

using namespace std;

int main()
{
	vector<pair<string, int>> v;
	string w;
	int n;

	while (cin >> w >> n)
	{
		//v.push_back({w, n}); // 列表初始化
		//v.push_back(pair<string, int>(w, n)); // 默认构造函数
		//v.push_back(make_pair(w, n)); // 使用make_pair，可能更好，向下兼容，可读性好
		v.emplace_back(w, n); // 可以避免拷贝，效率更好
	}

	for (const auto &p : v)
	{
		cout << p.first << "****" << p.second << endl;
	}

	return 0;
}
