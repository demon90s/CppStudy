/*
    挂起执行线程若干毫秒的一种实现
*/

#include <thread>
#include <iostream>

void Sleep(int ms)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

int main()
{
    while (true) {
        std::cout << "hello\n";

        Sleep(300);
    }

    return 0;
}