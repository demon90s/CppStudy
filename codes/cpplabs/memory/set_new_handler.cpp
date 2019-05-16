/*
    当 operator new 抛出异常以反应一个未满足的内存需求之前, 它会先调用一个客户指定的错误处理函数
    见 Effective C++ rule 49

    namespace std
    {
        typedef void (*new_handler)();
        new_handler set_new_handler(new_handler p);
    }
*/

#include <iostream>
#include <cstdlib>

// 当 operator new 无法分配内存时, 该函数被调用
void outOfMem()
{
    std::cerr << "Unable to satisfy request for memory, exit\n";
    std::exit(1);
}

void test_outOfMem()
{
    std::set_new_handler(outOfMem);
    int *pBigDataArray = new int[100000000000L];
    delete []pBigDataArray;
}

int main()
{
    test_outOfMem();
    return 0;
}