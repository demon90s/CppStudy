// 练习18.6：已知下面的异常类型和catch语句，书写一个throw表达式使其创建的
// 异常对象能被这些catch语句捕获。

#include <iostream>
#include <stdexcept>

using namespace std;

class exceptionType {};
typedef int EXCPTYPE;

int main()
{
	try {
		//static exceptionType pet;
		//throw &pet;

		//throw 42;

		throw runtime_error("oops!!");

	} catch (exceptionType *pet) {
		cout << "catch exceptionType" << endl;
	} catch (EXCPTYPE) {
		cout << "catch EXCPTYPE" << endl;
	} catch (...) {
		cout << "catch other exception" << endl;
	}

	return 0;
}
