/*
 * 练习5.6：改写上一题的程序，使用条件运算符（参见4.7节，第134页）代替if else语句。
 */

#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::vector;
using std::string;

int main()
{
	const vector<string> scores =  { "F", "D", "C", "B", "A", "A++" };

	int grade;
	cout << "Enter grade: ";
	cin >> grade;

	// 如果grade小于60，对应的字母是F；否则计算其下标
	string lettergrade;
	lettergrade = (grade < 60 ? scores[0] : scores[(grade - 50) / 10]);
	lettergrade += (grade != 100 && grade >= 60 ? 
				   (grade % 10 > 7 ? "+" : (grade % 10 < 3 ? "-" : "")) : "");

	cout << lettergrade << endl;

	return 0;
}
