/*
 * 练习4.22：本节的示例程序将成绩划分成high pass、pass和fail三种，扩展该程序使其进一步将60分到75分之间的成绩设定为low pass。要求程序包含两个版本：一个版本只使用条件运算符；另外一个版本使用1个或多个if语句。哪个版本的程序更容易理解呢？为什么？
 */

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;

int main()
{
	unsigned grade = 0;
	cout << "Enter grade: ";
	cin >> grade;

	if (grade > 100) {
		cout << "Invalid grade";
		return 1;
	}

	string finalgrade = (grade > 90) ? "high pass" : (grade > 75) ? "pass" : (grade >= 60) ? "low pass" : "fail";
	cout << finalgrade << endl;

	return 0;
}
