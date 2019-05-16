#pragma once

#include "Monster.h"
#include <iostream>

class Tiger : public Monster {
private:
    virtual void DoBattleCry(int times) {
        for (int i = 0; i < times; ++i)
            std::cout << "WOW~~~Tiger Comming~~~~" << std::endl;
    }
};