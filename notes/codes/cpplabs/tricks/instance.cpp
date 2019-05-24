/*
    单例模式的一种简单实现
*/

#include <iostream>

class SomeMgr {
public:
    static SomeMgr& Instance();

    int GetSomeValue() const { return some_value_; }
private:
    SomeMgr() : some_value_(42) {}
    ~SomeMgr() { std::cout << "~SomeMgr()\n"; }

    int some_value_;
};

SomeMgr& SomeMgr::Instance()
{
    static SomeMgr inst;
    return inst;
}

//----------------------------------------------------------------
int main()
{
    std::cout << SomeMgr::Instance().GetSomeValue() << std::endl;

    return 0;
}