# 条款5: 优先选用auto而非显式型别声明

---

直接使用显式型别有诸多问题存在。

比如：

```c++
int x;
```

x的值忘记初始化了，它的值取决于它定义的位置。而使用auto，则我们必须对它初始化：

```c++
auto x = 10;
```

同时，对于复杂类型，使用auto会更加简单，比如：

```c++
template<typename It>
void dwim(It b, It e)
{
    while (b != e)
        typename std::iterator_traits<It>::value_type currValue = *b;
}
```

显然直接用auto会简单很多：

```c++
template<typename It>
void dwim(It b, It e)
{
    while (b != e)
        auto currValue = *b;
}
```

另外，lambda表达式的类型只有编译器知道，因此我们定义lambda表达式就只能使用auto：

```c++
auto f = [](const int &a) {};
```

在C++14中，我们还可以对形参的类型使用auto：

```c++
auto f = [](const auto &a) {};
```

我们可以用std::function存储闭包，但正如书本上讨论的，使用auto声明一个变量来存储它的优势更加显著。

我们有时候会手动声明出错误的类型，从而导致非期望的结果。比如：

```c++
std::vector<int> v;
unsigned sz = v.size();
```

vector的size方法返回的并非是一个unsigned类型，而是`std::vector<T>::size_type`, 它可能是64位的，而unsigned类型是32位的。

再比如：

```c++
std::unordered_map<std::string, int> m;

for (const std::pair<std::string, int> &p : m)
{

}
```

`std::pair<std::string, int>`并不是m的键值类型，准确的类型应该是`std::pair<const std::string, int>`。因此上述迭代会带来复制和析构成本，且引用也没有意义。

使用auto就可以避免我们声明出错误的类型：

```c++
auto sz = v.size();

for (const auto &p : m)
{

}
```

auto型别可以随着其初始化表达式型别的变化而自动随之改变，这意味着一种自动的重构。但如果是显式声明的话，就需要手动去修改各个位置的代码了。

我们可能心存疑虑，改用auto后写出来的源代码会有可读性问题。记住，auto是一个可选项，而非必选项，如果显式型别更清晰、可维护性更高，当然可以使用。
