// 参考 EffectC++ 条款12
// 在做拷贝的时候，即调用 copy constructor 或 copy assignment 的时候，需要拷贝所有内容，即：
// 1. 拷贝所有的成员
// 2. 调用基类的对应的 copy 方法

#include <string>
#include <iostream>

class Base {
public:
    Base(const std::string &n) : name_(n) {}
    Base(const Base& base) : name_(base.name_) {}
    Base& operator=(const Base &rhs) {
        name_ = rhs.name_;
        return *this;
    }

    const std::string &GetName() const { return name_; }

private:
    std::string name_;
};

class Derived : public Base {
public:
    Derived(const std::string &n, int power) : Base(n), power_(power) {}
    Derived(const Derived &derived) : Base(derived), power_(derived.power_) {}
    Derived& operator=(const Derived &rhs) {
        Base::operator=(rhs);
        power_ = rhs.power_;
        return *this;
    }

    // test
    void Show() {
        std::cout << "my name is: " << this->GetName() << " "
                    << "my power is: " << power_ << std::endl;
    }

private:
    int power_;
};

int main()
{
    Derived d1("guanyu", 98);
    Derived d2("zhangfei", 99);

    d1.Show();
    d2.Show();

    Derived d3(d1);
    d3.Show();

    d3 = d2;
    d3.Show();

    return 0;
}