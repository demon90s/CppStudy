// 一个最简单的 thread

#include <iostream>
#include <thread>
#include <unistd.h>

void thread_func()
{
	std::cout << "thread function begin" << std::endl;
	sleep(2);
	std::cout << "thread function end" << std::endl;
}

int main()
{
	std::thread t(thread_func); // t starts running

	t.join(); // main thread waits for t to finish
	//t.detach(); // t will freely on its own, once detached, forever detached

	std::cout << "main thread end" << std::endl;
	return 0;
}
