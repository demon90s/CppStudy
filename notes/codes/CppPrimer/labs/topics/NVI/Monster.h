#pragma once

class Monster {
public:
    Monster() {}
    virtual ~Monster() {}

    // 战吼
    void BattleCry(int times = 1) {
        this->DoBattleCry(times);
    }

private:
    virtual void DoBattleCry(int times) = 0;  // 战吼实现
};