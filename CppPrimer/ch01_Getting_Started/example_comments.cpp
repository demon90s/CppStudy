// example: C++中的注释使用（p8）

#include <iostream>

/*
 * 简单主函数：
 * 读取两个数，求它们的和
 */
int main()
{
	// 提示用户输入两个数
	std::cout << "Enter two numbers:" << std::endl;

	int a = 0, b = 0;	// 保存读入的输入数据的变量
	std::cin >> a >> b;	// 读取输入数据

	std::cout << "The sum is: " << a + b << std::endl;

	return 0;
}
