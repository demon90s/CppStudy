#include <iostream>
#include "instance.h"

int main()
{
    std::cout << SomeMgr::Instance()->GetSomeValue() << std::endl;

    SomeMgr::Instance()->ReInit();
    std::cout << SomeMgr::Instance()->GetSomeValue() << std::endl;

    return 0;
}