// example: 格式化输入与输出（p666）

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// 控制布尔值的格式
void func1()
{
	cout << "default bool values: " << true << " " << false << endl;

	cout << "alpha bool values: " << boolalpha << true << " " << false << endl;

	cout << noboolalpha << endl; // 将内部状态恢复为默认格式
}

// 指定整型值的进制
void func2()
{
	cout << showbase; // 打印整型值时显示进制

	cout << "default: " << 20 << " " << 1024 << endl;

	cout << "octal: " << oct << 20 << " " << 1024 << endl;

	cout << "hex: " << hex << 20 << " " << 1024 << endl;

	cout << "decimal: " << dec << 20 << " " << 1024 << endl;

	cout << noshowbase; // 恢复流状态
}

// 指定打印精度
void func3()
{
	// 返回当前精度值
	cout << "Precision: " << cout.precision() << ", Value: " << sqrt(2.0) << endl;

	// 设置精度
	cout << setprecision(3) << "Precision: " << cout.precision() << ", Value: " << sqrt(2.0) << endl;
}

// 输出补白
void func4()
{
	int i = -16;
	double d = 3.14159;
	
	// 补白第一列，使用输出中最小12个位置
	cout << "i: " << setw(12) << i << endl
	     << "d: " << setw(12) << d << endl;

	// 补白第一列，左对齐所有列
	cout << left
	     << "i: " << setw(12) << i << endl
	     << "d: " << setw(12) << d << endl;
	
	// 补白第一列，右对齐所有列
	cout << right
	     << "i: " << setw(12) << i << endl
	     << "d: " << setw(12) << d << endl;
	
	// 补白第一列，但补在域的内部
	cout << internal
	     << "i: " << setw(12) << i << endl
	     << "d: " << setw(12) << d << endl;
	
	// 补白第一列，用#作为补白字符
	cout << setfill('#')
	     << "i: " << setw(12) << i << endl
	     << "d: " << setw(12) << d << endl
		 << setfill(' '); // 恢复正常的补白字符
}

int main()
{
	//func1();
	//func2();
	//func3();
	func4();

	return 0;
}
