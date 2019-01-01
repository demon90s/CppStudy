// 练习9.43：编写一个函数，接受三个string参数s、oldVal和newVal。使用迭代器
// 及insert和erase函数将s中所有oldVal替换为newVal。测试你的程序，用
// 它替换通用的简写形式，如，将"tho"替换为"though"，将"thru"替换为"through"。

#include <iostream>
#include <string>

using namespace std;

void replace(string &s, const string &oldVal, const string &newVal)
{
	auto beg = s.begin();
	
	while (beg != s.end() && s.end() - beg >= (int)oldVal.length()) {
		string test_string(beg, beg + oldVal.length()); // 测试string
		// 可删除
		if (test_string == oldVal) {
			beg = s.erase(beg, beg + oldVal.length());

			for (auto c : newVal) {
				beg = s.insert(beg, c);
				++beg;
			}
		}
		else {
			// 测试下一个
			++beg;
		}
	}
}

int main()
{
	string s = "hello tho thru";
	cout << s << endl;

	replace(s, "tho", "though");
	cout << s << endl;

	replace(s, "thru", "through");
	cout << s << endl;

	return 0;
}
