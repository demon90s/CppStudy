/*
    #include <chrono>
    std::chrono::high_resolution_clock

    表示实现提供的拥有最小记次周期的时钟

    提供成员函数:
    static now 返回表示时钟当前值的 std::chrono::time_point
*/

#include <iostream>
#include <chrono>

void test1()
{
    auto start = std::chrono::high_resolution_clock::now();

    // do something heavy
    for (int i = 0; i < 100000; i++) {
        FILE *fp = tmpfile();
        fprintf(fp, "hello");
        fclose(fp);
    }

    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> diff = end - start;

    std::cout << "duration: " << diff.count() << "s" << std::endl;          // 得到执行上述任务所用的精确时间
}

int main()
{
    test1();

    return 0;
}