// example: 嵌套if语句（p157）

/*
 * 书中使用if else语句的案例，在代码格式上自己做了微调
 * 把数字形式表示的成绩转换成字母形式
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
	if (grade < 60) {
		lettergrade = scores[0];
	}
	else {
		lettergrade = scores[(grade - 50) / 10];	// 获得字母形式的成绩
		if (grade != 100) { // 只要不是A++，就考虑添加加号或减号
			if (grade % 10 > 7) {
				lettergrade += '+';
			}
			else if (grade % 10 < 3) {
				lettergrade += '-';
			}
		}
		
	}

	cout << lettergrade << endl;

	return 0;
}
