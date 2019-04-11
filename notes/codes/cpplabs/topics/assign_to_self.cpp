/*
    自赋值问题

    比如这样的操作可能是一种隐晦的自赋值: a[i] = a[j]
    必须正确处理
*/

class Foo {
public:
    Foo(int v = 0) : m_v(new int(v)) {}
    ~Foo() { delete m_v; }
    Foo(const Foo& rhs) : m_v(new int(*rhs.m_v)) {}
    
    Foo& operator=(const Foo& rhs) {
        // 第一种方法
        //*m_v = *rhs.m_v;

        // 第二种方法
        int *tmp = new int(*rhs.m_v);
        delete m_v;
        m_v = tmp;

        return *this;
    }

private:
    int *m_v;
};

int main()
{
    Foo foo1;
    Foo foo2(42);

    foo1 = foo2;

    return 0;
}
