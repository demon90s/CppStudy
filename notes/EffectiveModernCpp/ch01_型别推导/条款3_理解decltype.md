# 条款3: 理解decltype

---

对于给定的名字或表达式，decltype能告诉你该名字或表达式的型别。

如：

```c++
const int i = 0;                // decltype(i) 是 const int

bool f(const Widget& w);        // decltype(w) 是 const Widget&
                                // decltype(f) 是 bool(const Widget&)

struct Point {
    int x, y;                   // decltype(Point::x) 是 int
};                              // decltype(Point::y) 是 int

if (f(w)) ...                   // decltype(f(w)) 是 bool

template<typename T>
class vector {
public:
    T& operator[](std::size_t index);
};

vector<int> v;                  // decltype(v) 是 vector<int>
if(v[0] == 0) ...               // decltype(v[0]) 是 int&
```

C++11中，decltype主要用处大概在于声明那些返回值型别依赖于形参型别的函数模板。

```c++
template<typename Container, typename Index>
auto authAndAccess(Container& c, Index i)
    -> decltype(c[i])
{
    authenticateUser();
    return c[i];
}
```

这里的auto和型别推导没有关系，这是C++11中的返回值型别尾序语法。

C++14中可以去掉返回值型别尾序语法，只保留auto。此时auto会发生型别推导。

请看下面**错误**的示范：

```c++
template<typename Container, typename Index>
auto authAndAccess(Container& c, Index i)
{
    authenticateUser();
    return c[i];
}
```

由于在模板型别推导中，上述表达式引用性会被忽略，于是：

```c++
std::deque<int> d;
authAndAccess(d, 5) = 10;       // 返回 d[5] 但无法通过编译
```

上述函数返回值型别为int，作为函数的返回值，它是一个右值，所以无法将10赋给它。

如何修补？在C++14中通过decltype(auto)解决。即：

```c++
template<typename Container, typename Index>
decltype(auto) authAndAccess(Container& c, Index i)
{
    authenticateUser();
    return c[i];
}
```

此时推导规则采用的是decltype的规则。

上述函数无法传递一个右值的容器对象，如何做到？采用万能引用。同时在调用`operator[]`时使用`std::forward`保持其型别。

```c++
template<typename Container, typename Index>
decltype(auto)
authAndAccess(Container&& c, Index i)
{
    authenticateUser();
    return std::forward<Container>(c)[i];
}
```

如果decltype应用于复杂的左值表达式（非单纯只是一个名字）的话，decltype就保证得出的型别总是左值引用。

请看：

```c++
int x = 0;
```

decltype(x)结果是int。但如果`decltype((x))`的话，结果就成了`int&`。