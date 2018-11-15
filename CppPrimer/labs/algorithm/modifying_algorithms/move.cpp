/*
    move
    移动范围[first, last)中的元素到始于 d_first 的另一范围，从首元素开始逐次到末元素。
    move(first, last, d_first)

    move_backward
    移动来自范围[first, last)的元素到终于 d_last 的另一范围。以逆序移动元素（首先复制末元素），打保持相对顺序
    move_backwar(first, last, d_last)

    如果元素定义了 move 语义，才会被移动，否则会被拷贝
    
*/

#include <algorithm>
#include <vector>
#include <iostream>
#include <string>

template<typename T>
void Print(std::vector<T> &v)
{
    for (const auto& i : v)
        std::cout << i << ' ';
    std::cout << std::endl;
}

// 没有定义 move 语义，等同于拷贝
void Test_move_1()
{
    std::vector<int> vec {1, 2, 3};
    std::vector<int> des(vec.size() * 2);

    std::cout << "before move: " << std::endl;
    std::cout << "vec: ";
    Print(vec);
    std::cout << "des: ";
    Print(des);

    std::move(vec.begin(), vec.end(), des.begin());
    
    std::cout << "after move: " << std::endl;
    std::cout << "vec: ";
    Print(vec);
    std::cout << "des: ";
    Print(des);
}

// 定义 move 语义，确实移动
class Foo {
    friend std::ostream& operator<<(std::ostream &os, const Foo&);
public:
    Foo() : m_v(new int(0)) {}
    ~Foo() { if (m_v) delete m_v; }
    Foo(int v) : m_v(new int(v)) {}
    Foo(const Foo& foo) : m_v(new int(*foo.m_v)) {}
    Foo(Foo &&foo) : m_v(foo.m_v) { foo.m_v = nullptr; }
    Foo& operator=(const Foo& foo) {
        int *tmp = new int(*foo.m_v);
        delete m_v;
        m_v = tmp;
        return *this; 
    }
    Foo& operator=(Foo&& foo) {
        if (&foo == this) return *this;
        m_v = foo.m_v;
        foo.m_v = nullptr;
        return *this;    
    }

private:
    int *m_v;
};

std::ostream& operator<<(std::ostream &os, const Foo& foo)
{
    if (foo.m_v) os << *foo.m_v;
    else os << "null";
    return os;
}

void Test_move_2()
{
    std::vector<Foo> vec {1, 2, 3};
    std::vector<Foo> des(vec.size() * 2);

    std::cout << "before move: " << std::endl;
    std::cout << "vec: ";
    Print(vec);
    std::cout << "des: ";
    Print(des);

    std::move(vec.begin(), vec.end(), des.begin());
    
    std::cout << "after move: " << std::endl;
    std::cout << "vec: ";
    Print(vec);
    std::cout << "des: ";
    Print(des);
}

void Test_move_backward()
{
    std::vector<std::string> vec {"foo", "bar", "goo"};
    std::vector<std::string> des(vec.size() * 2);

    std::cout << "before move: " << std::endl;
    std::cout << "vec: ";
    Print(vec);
    std::cout << "des: ";
    Print(des);

    std::move_backward(vec.begin(), vec.end(), des.end());
    
    std::cout << "after move: " << std::endl;
    std::cout << "vec: ";
    Print(vec);
    std::cout << "des: ";
    Print(des);
}

int main(int argc, char const *argv[])
{
    //Test_move_1();
    //Test_move_2();
    Test_move_backward();

    return 0;
}
