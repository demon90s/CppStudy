// std::thread::hardware_concurrency()
// 返回实际上最多创建的线程数
// 可能是 CPU 的核心数量

#include <iostream>
#include <thread>

int main()
{
	std::cout << "hardware_concurrency: " <<
		std::thread::hardware_concurrency() << std::endl;

	return 0;
}
