/*
	async() 和 future

	async 使用一个可调用对象，若可能的话，令其在后台异步运行，成为一个独立的线程
	class future<> 等待线程并获得等待的结果。
*/

#include <future>
#include <thread>
#include <chrono>
#include <random>
#include <iostream>
#include <exception>

using namespace std;

int doSomething(char c)
{
	// random number generator
	default_random_engine dre(c);
	uniform_int_distribution<int> id(10, 1000);

	// loop to print charactor after a random period time
	for (int i = 0; i < 10; ++i) {
		this_thread::sleep_for(chrono::milliseconds(id(dre)));
		cout.put(c).flush();
	}

	return c;
}

int func1()
{
	return doSomething('-');
}

int func2()
{
	return doSomething('+');
}

int main()
{
	std::cout << "starting func1 in background "
		<< "and func2 in foreground\n";

	// start func1 aync (later or never)
	std::future<int> result1(async(func1));

	int result2 = func2();

	// wait func1 to finish and add the result
	int result = result1.get() + result2;

	std::cout << "result: " << result << std::endl;

	return 0;
}
