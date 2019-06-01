// 练习9.14：编写程序，将一个list中的char*指针（指向C风格字符串）元素赋值
// 给一个vector中的string。

#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main()
{
	list<const char*> cstr_lst = {"hi", "hello", "wow"};
	vector<string> str_vec;

	str_vec.assign(cstr_lst.begin(), cstr_lst.end());
	for (const auto &s : str_vec)
		cout << s << endl;

	return 0;
}
