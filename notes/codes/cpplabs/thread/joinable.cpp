/*
	std::thread::joinable
	bool joinable() const noexcept;

	检查 thread 对象是否标识活跃的执行线程。
	完成执行代码，但未被合并的线程仍被认为是活跃线程，从而可合并。
*/

#include <iostream>
#include <thread>
#include <chrono>

void foo()
{
	std::this_thread::sleep_for(std::chrono::seconds(1));
}

int main()
{
	std::thread t;
	std::cout << "before starting, joinable: " << std::boolalpha << t.joinable() << "\n";

	t = std::thread(foo);
	std::cout << "after starting, joinable: " << t.joinable() << "\n";

	t.join();
	std::cout << "after joining, joinable: " << t.joinable() << "\n";
}
