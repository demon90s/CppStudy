// 在multimap中查找元素(p389)

#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
	multimap<string, string> authors = {{"Liudiwen", "CppNoob"}, 
		{"Liudiwen", "GameDesignNoob"}, 
		{"Liumiemie", "Smiling"}};

	string search_item("Liudiwen");				// 要查找的作者
	auto entries = authors.count(search_item);	// 元素的数量
	auto iter = authors.find(search_item);		// 此作者的第一本书

	// 用一个循环查找此作者的所有著作
	while (entries) {
		cout << iter->second << endl;			// 打印每个题目
		++iter;									// 前进到下一本书
		--entries;								// 记录已经打印了多少本书
	}

	return 0;
}
