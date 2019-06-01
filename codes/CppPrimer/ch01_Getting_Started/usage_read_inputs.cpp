#include <iostream>

// 对用户输入的一组数求和
int main()
{
	int sum = 0, value = 0;

	// 读取数据直到遇到文件尾，计算所有读入的值的和
	while (std::cin >> value)
		sum += value;

	std::cout << "Sum is: " << sum << std::endl;

	return 0;
}
