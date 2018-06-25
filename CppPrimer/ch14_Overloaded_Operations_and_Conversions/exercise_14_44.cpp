// 练习14.44：编写一个简单的桌面计算器使其能处理二元运算。

// ./exercise_14_44 2 - 2

#include <iostream>
#include <map>
#include <functional>
#include <string>

using namespace std;

void Calc(string ops, int a, int b)
{
	static map<string, function<int(int, int)>> calc_f_map = {
		{"+", [](int i, int j) { return i + j; }},
		{"-", [](int i, int j) { return i - j; }},
		{"*", [](int i, int j) { return i * j; }},
		{"/", [](int i, int j) { return i / j; }},
	};

	if (calc_f_map.count(ops) == 0)
		cerr << "cant find ops: " << ops << endl;
	else
		cout << calc_f_map[ops](a, b) << endl;
}

int main(int args, char *argv[])
{
	if (args != 4) {
		cerr << "args != 4, return" << endl;
		return -1;
	}

	int lhs = stoi(argv[1]);
	string ops = argv[2];
	int rhs = stoi(argv[3]);
	
	Calc(ops, lhs, rhs);

	return 0;
}
