// 练习9.47：编写程序，首先查找string"ab2c3d7R4E6"中的每个数字字符，然后查
// 找其中每个字母字符。编写两个版本的程序，第一个要使用find_first_of，第二个
// 要使用find_fisrt_not_of。

#include <iostream>
#include <string>

using namespace std;

string str = "ab2c3d7R4E6";
string numbers = "0123456789";
string alphas = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

void find_num()
{
	string::size_type pos = 0;
	cout << "numbers:" << endl;
	while ((pos = str.find_first_of(numbers, pos)) != string::npos) {
		cout << pos << ": " << str[pos] << endl;
		++pos;
	}

	pos = 0;
	cout << "alphas:" << endl;
	while ((pos = str.find_first_of(alphas, pos)) != string::npos) {
		cout << pos << ": " << str[pos] << endl;
		++pos;
	}
}

void find_alpha()
{
	string::size_type pos = 0;
	cout << "alphas:" << endl;
	while ((pos = str.find_first_not_of(numbers, pos)) != string::npos) {
		cout << pos << ": " << str[pos] << endl;
		++pos;
	}

	pos = 0;
	cout << "numbers:" << endl;
	while ((pos = str.find_first_not_of(alphas, pos)) != string::npos) {
		cout << pos << ": " << str[pos] << endl;
		++pos;
	}
}

int main()
{
	//find_num();
	find_alpha();

	return 0;
}
