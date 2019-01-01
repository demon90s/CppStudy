// example: do while语句（p169）

/*
 * 使用do while循环询问用户
 */

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;

int main()
{
	// 不断提示用户输入一对数，然后求其和
	string rsp;	// 作为循环的条件，不能定义在do的内部
	do {
		cout << "please enter two values: ";
		int val1 = 0, val2 = 0;
		cin >> val1 >> val2;
		cout << "The sum is: " << val1 + val2 << endl;
		cout << "More? Enter yes or no: ";
		cin >> rsp;
	} while (!rsp.empty() && rsp[0] != 'n');

	return 0;
}
