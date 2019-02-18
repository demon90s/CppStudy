/*
	std::thread::get_id
	std::thread::id get_id() const noexcept;

	返回标识与 *this 关联的线程的线程ID 。
	如果没有关联的线程，则返回默认构造的 std::thread::id

	std::thread::id 是作为 std::thread 对象的唯一标识符，它可以被复制。一旦线程结束，其值可以被复用。
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
	std::thread t1(foo);
	std::thread::id t1_id = t1.get_id();

	std::thread t2(foo);
	std::thread::id t2_id = t2.get_id();

	std::cout << "t1's id: " << t1_id << '\n';
	std::cout << "t2's id: " << t2_id << '\n';

	t1.join();
	t2.join();

	return 0;
}
