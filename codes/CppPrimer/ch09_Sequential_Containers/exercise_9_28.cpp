// 练习9.28：编写函数，接受一个forward_list<string>和两个string共三个参数。
// 函数应在链表中查找第一个string，并将第二个string插入到紧接着第一个string
// 之后的位置。如第一个string未在链表中，则将第二个string插入到链表末尾。

#include <iostream>
#include <forward_list>
#include <string>

using namespace std;

void Insert(forward_list<string> &flst, const string &find_str, const string &insert_str)
{
	auto prev = flst.before_begin();
	auto it = flst.begin();
	while (it != flst.end()) {
		if (*it == find_str) {
			it = flst.insert_after(it, insert_str);
			break;
		}
		else {
			prev = it;
			++it;
		}
	}

	if (it == flst.end())
		flst.insert_after(prev, insert_str);
}

int main()
{
	forward_list<string> flst{"a", "b", "c", "d"};

	Insert(flst, "c", "X");
	for (const auto &s : flst)
		cout << s << " ";
	cout << endl;

	Insert(flst, "M", "U");
	for (const auto &s : flst)
		cout << s << " ";
	cout << endl;

	return 0;
}
