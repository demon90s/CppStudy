// 练习10.22：重写统计长度小于等于6的单词数量的程序，使用函数代替lambda。

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;
using namespace std::placeholders;

bool func(const string &w, size_t n)
{
	return w.size() > n;
}

int main()
{
	vector<string> words = {"hello", "programmer", "project", "mom", "daddy"};

	auto cnt = count_if(words.begin(), words.end(), bind(func, _1, 6));

	cout << cnt << endl;

	return 0;
}
