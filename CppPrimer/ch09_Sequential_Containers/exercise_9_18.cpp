// 练习9.18：编写程序，从标准输入读取string序列，存入一个deque中。编写一个
// 循环，用迭代器打印deque中的元素。

#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main()
{
	deque<string> str_deq;
	string word;

	while (cin >> word)
		str_deq.push_back(word);

	for (auto it = str_deq.cbegin(); it != str_deq.cend(); ++it)
		cout << *it << " ";
	cout << endl;

	return 0;
}
