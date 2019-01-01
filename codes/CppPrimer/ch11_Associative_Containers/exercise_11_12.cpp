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
		v.push_back({w, n});
	}

	for (const auto &p : v)
	{
		cout << p.first << "****" << p.second << endl;
	}

	return 0;
}
