// 练习9.50：编写程序处理一个vector<string>，其元素表示整数值。计算vector
// 中所有元素之和。修改程序，使之计算表示浮点值得string之和。

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void func1()
{
	vector<string> v{"1", "2", "3", "4", "5"}; // 15
	int sum = 0;
	for (auto i : v)
		sum += stoi(i);
	
	cout << sum << endl;
}

void func2()
{
	vector<string> v{"1.2", "2.2", "3.2", "4.2", "5.3"}; // 16.1
	double sum = 0;
	for (auto i : v)
		sum += stod(i);
	
	cout << sum << endl;
}

int main()
{
	//func1();
	func2();
	return 0;
}
