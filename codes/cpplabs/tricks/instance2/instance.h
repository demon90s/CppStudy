#pragma once

// 一种单例模式的实现方式, 采用内部的一根指针

class SomeMgr {
public:
    static SomeMgr* Instance();
    bool ReInit();      // 重新创建单例对象, 并执行 Init
    
     // user implements below
    bool Init();
    int GetSomeValue() const { return some_value_; }

private:
    SomeMgr() : some_value_(0) {}
    ~SomeMgr() {}

    int some_value_;
};