// 练习9.44：重写上一题的函数，这次使用一个下标和replace。

#include <iostream>
#include <string>

using namespace std;

void replace(string &s, const string &oldVal, const string &newVal)
{
	string::size_type pos = 0;

	while (pos + oldVal.length() <= s.length() ) {
		string test_str = s.substr(pos, oldVal.length());

		if (test_str == oldVal) {
			s.replace(pos, oldVal.length(), newVal);
			pos += newVal.length();
		}
		else {
			++pos;
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
