/*
    std::this_thread::sleep_for(duration)

    阻塞当前线程执行, 至少经过指定的 duration 时间
*/

#include <thread>
#include <iostream>

void test1()
{
    auto duration = std::chrono::milliseconds(1000);    // 1s

    while (true) {
        std::cout << "hello~~~" << std::endl;
        std::this_thread::sleep_for(duration);
    }
}

int main()
{
    test1();

    return 0;
}