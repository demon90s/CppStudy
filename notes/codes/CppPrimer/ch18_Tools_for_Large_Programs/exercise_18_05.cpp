// 练习18.5：修改下面的main函数，使其能捕获图18.1（第693页）所示的任何异常类型：
// int main() { // 使用C++标准库 }
// 处理代码应该首先打印异常相关的错误信息，然后调用abort（定义在cstdlib头文件中）
// 终止main函数。

#include <iostream>
#include <vector>
#include <stdexcept>
#include <bitset>
#include <string>

using namespace std;

void func_overflow_error()
{
	string str(128,'1');
	bitset<128> bs(str);
	bs.to_ulong();
}

void func_runtime_error()
{
	throw runtime_error("oop!!");
}

void func_exception()
{
	vector<int> vec;
	vec.at(0);
}

int main()
{
	try {
		// 使用C++标准库
		//func_overflow_error();
		func_runtime_error();
		func_exception();

	} catch(overflow_error eobj) {
		cout << "overflow_error: " << eobj.what() << endl;
		abort();
	} catch (const runtime_error &re) {
		cout << "runtime_error: " << re.what() << endl;
		abort();
	} catch (exception) {
		cout << "catch exception" << endl;
		abort();
	}

	return 0;
}
