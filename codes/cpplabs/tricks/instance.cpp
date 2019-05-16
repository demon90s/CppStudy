/*
    单例模式的一种简单实现
*/

class SomeMgr {
public:
    static SomeMgr& Instance();

    int GetSomeValue() const { return some_value_; }
private:
    SomeMgr() : some_value_(42) {}
    ~SomeMgr() {}

    int some_value_;
};

SomeMgr& SomeMgr::Instance()
{
    static SomeMgr inst;
    return inst;
}

//----------------------------------------------------------------
#include <iostream>
int main()
{
    std::cout << SomeMgr::Instance().GetSomeValue() << std::endl;

    return 0;
}