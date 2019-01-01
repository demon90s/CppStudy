/*
 * 练习3.1：使用恰当的using声明重做1.4.1节（第11页）和2.6.2节（第67页）的练习。
 */

#include <iostream>

using std::cout;
using std::endl;
using std::cin;

// 1.4.1节 练习1.9
/*
int main()
{
	int sum = 0, i = 50;

	while (i <= 100) {
		sum += i;
		++i;
	}

	cout << "Sum of 50 to 100 inclusive is " << sum << endl;

	return 0;
}
*/

// 1.4.1节 练习1.10
/*
int main()
{
	int val = 10;
	while (val >= 0) {
		cout << val << endl;
		--val;
	}

	return 0;
}
*/

// 1.4.1节 练习1.11

int main()
{
	int lval = 0, rval = 0;

	cout << "Enter two integers:" << endl;
	cin >> lval >> rval;

	while (lval <= rval) {
		cout << lval << endl;
		lval++;
	}

	return 0;
}

// 2.6.2节练习，类似，去掉std::即可 
