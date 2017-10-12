/*
 * 练习3.22：修改之前那个输出text第一段的程序，首先把text的第一段全部改成大写形式，然后再输出它。
 */

#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
	vector<string> text = {"Hello World!", "", "Hi There!"};

	for (auto it = text.begin(); it != text.end() && !it->empty(); ++it) {
		for (auto s_it = it->begin(); s_it != it->end(); ++s_it) {
			*s_it = toupper(*s_it);
		}
		cout << *it << endl;
	}

	return 0;
}
