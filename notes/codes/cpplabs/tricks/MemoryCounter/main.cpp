#include "MemoryCounter.h"
#include <iostream>

class Foo
{
public:
    Foo() : m_mem_counter("Foo") {}

private:
    MemoryCounter m_mem_counter;
};

int main()
{
    {
        Foo foo1, foo2, foo3;
        std::cout << "Foo Blocks: " << MemoryCounter::GetMemoryBlocks("Foo") << std::endl;  // 3
    }

    std::cout << "Foo Blocks: " << MemoryCounter::GetMemoryBlocks("Foo") << std::endl;      // 0
    
    return 0;
}