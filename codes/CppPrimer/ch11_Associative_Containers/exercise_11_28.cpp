// 练习11.28：对一个string到int的vector的map，定义并初始化一个变量来保存
// 在其上调用find所返回的结果。

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main()
{
	map<string, int> m;

	map<string, int>::iterator it = m.find("a");

	return 0;
}
