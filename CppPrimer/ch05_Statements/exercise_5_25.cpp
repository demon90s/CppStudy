/*
 * 练习5.25：修改上一题的程序，使用try语句块去捕获异常。catch子句应该为用户输出一条提示信息，询问其是否输出新数并重新执行try语句块的内容。
 */

#include <iostream>
#include <stdexcept>

using std::cout;
using std::endl;
using std::cin;

int main()
{
	int a = 0, b = 0;

	while (true)
	{
		try {
			cout << "Enter two number(a/b): ";
			cin >> a >> b;

			if (b == 0)
				throw std::runtime_error("second number can not equal 0");

			cout << a * 1.0 / b << endl;
			break;

		} catch (std::runtime_error err) {
			cout << err.what() << endl;
			
			cout << "Enter again[y or n]: ";
			char c;
			cin >> c;
			if (!cin || c != 'y')
				break;
		}
	}

	return 0;
}
