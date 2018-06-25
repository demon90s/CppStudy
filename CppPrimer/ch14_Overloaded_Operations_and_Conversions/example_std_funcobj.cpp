// example: 标准库定义的函数对象（p509）

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

int main()
{
	vector<string> vec = {"A", "BB", "CCC"};
	sort(vec.begin(), vec.end(), greater<string>());

	for_each(vec.begin(), vec.end(), [](const string &s) { cout << s << " "; });
	cout << endl;

	return 0;
}
