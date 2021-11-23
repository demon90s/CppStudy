# 条款2: 理解auto型别推导

---

auto型别推导就是模板型别推导，除了一个例外。

对于模板型别推导的三种情况，auto型别推导的规则是一样的：

- 情况1 型别饰词是指针或引用 将原表达式的引用部分忽略
- 情况2 型别饰词是万能引用 若原表达式是左值 则推导为左值引用
- 情况3 型别饰词既非指针也非引用 将原表达式引用部分忽略 顶层const忽略

```c++
auto x = 27;            // 情况3 x型别推导为int
const auto cx = x;      // 情况3 cx型别推导为const int
const auto& rx = x;     // 情况1 rx型别推导为const int&

auto&& uref1 = x;       // 情况2 uref1型别推导为int&
auto&& uref2 = cx;      // 情况2 uref2型别推导为const int&
auto&& uref3 = 27;      // 情况2 uref3型别推导为int&&
```

对于数组和函数的推导规则，auto也是一样的。

```c++
const char name[] = "diwen";            // name的型别是const char[6]
auto arr1 = name;                       // arr1的型别是const char*
auto& arr2 = name;                      // arr2的型别是const (&)char[6]

void f(int, double);                    // f的型别是void(int, double)
auto func1 = f;                         // func1的型别是void(*)(int, double)
auto& func2 = f;                        // func2的型别是void(&)(int, double)
```

## 例外情况

对于 `auto x{27}` 这样的初始化语句，x推导出的型别是`std::initializer_list`。而模板型别推导面对这样的情况就会失败：

```c++
template<typename T>
void f(T param);

f({1, 2, 3});       // 错误！无法推导T的型别
```

在C++14中，auto可以用来说明函数返回值需要推导，此时应用的不是auto型别推导，而是模板型别推导，因此下面代码无法通过编译：

```c++
auto f()
{
    return {1, 2, 3};
}
```

在C++14中，auto可以用来指定lambda式的形参型别，此时也是应用模板型别推导，因此下面代码也无法通过编译：

```c++
auto f = [](const auto &v) {};
f({1, 2, 3});
```
