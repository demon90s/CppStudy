// test: 测试类型转换

#include <iostream>

using namespace std;

void test()
{
	// int -> bool
	cout << "[TEST] int -> bool" << endl;
	cout << "5 -> bool: " << ((bool)5 ? "true" : "false") << endl;	
	cout << "0 -> bool: " << ((bool)0 ? "true" : "false") << endl;
	cout << endl;

	// bool -> int
	cout << "[TEST] bool -> int" << endl;
	cout << "true -> int: " << (int)true << endl;
	cout << "false -> int: " << (int)false << endl;
	cout << endl;

	// float -> int
	cout << "[TEST] float -> int" << endl;
	cout << "3.14 -> int: " << (int)3.14f << endl;
	cout << endl;

	// int -> float
	cout << "[TEST] int -> float" << endl;
	cout << "3 -> float: " << (float)3 << endl;
	cout << endl;

	// unsigned int out of range
	cout << "[TEST] unsigned int out of range" << endl;
	cout << "(4294967295LL + 1) -> unsigned int: " << (unsigned int)(4294967295LL + 1) << endl;
	cout << endl;
}

int main()
{
	test();

	return 0;
}
