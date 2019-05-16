/*
    member template

    成员模板，即类里面的模板成员函数。成员模板不能是虚函数

    对于类模板，也可以定义成员模板，其模板参数是独立的
*/

#include <memory>
#include <iostream>
#include <vector>
#include <string>

// 函数对象，对给定指针执行 delete
class Deletor {
public:
    Deletor(std::ostream &os) : os_(os) {}

    template<typename T>
    void operator()(T *p) {
        os_ << "delete: " << p << std::endl;
        delete p;
    }

private:
    std::ostream &os_;
};

void Test1()
{
    int *p = new int(42);

    Deletor deletor(std::cout);
    deletor(p);
}

void Test2()
{
    // 用作 unique_ptr 的删除器
    // unique_ptr 的析构函数会调用可调用对象，从而对成员模板执行实例化

    std::unique_ptr<int, Deletor> p(new int(42), Deletor(std::cout));
}

// 类模板的成员模板
template<typename T>
class Collection {
public:
    template<typename It>
    Collection(std::string name, It beg, It end) : name_(name), coll_(beg, end) {}

    template<typename M>
    friend std::ostream& operator<<(std::ostream& os, const Collection<M> coll);

private:
    std::ostream& print(std::ostream &os) const {
        std::cout << name_ << ":";
        for (const auto &item : coll_) {
            os << " " << item;
        }
        return os;
    }

    std::string name_;
    std::vector<T> coll_;
};

template<typename T>
std::ostream& operator<<(std::ostream& os, const Collection<T> coll) {
    return coll.print(os);
}

void Test3()
{
    int arr[] = {1, 2, 3, 4, 5};
    Collection<int> coll("coll", std::begin(arr), std::end(arr));

    std::cout << coll << std::endl;
}

int main()
{
    //Test1();
    //Test2();
    Test3();

    return 0;
}