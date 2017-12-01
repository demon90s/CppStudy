// 练习9.41：编写程序，从一个vector<char>初始化一个string。

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	vector<char> cvec = {'h', 'e', 'l', 'l', 'o'};
	string s(cvec.begin(), cvec.end());

	cout << s << endl;

	return 0;
}
