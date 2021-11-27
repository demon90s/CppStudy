# 条款6: 当auto推导的型别不符合要求时使用带显式型别的初始化物习惯用法

---

以`std::vector<bool>`为例，这样写是正确的：

```c++
std::vector<bool> bvec;
...
bool b = bvec[5];
```

但下面的代码却有未定义行为：

```c++
std::vector<bool> bvec;
...
auto b = bvec[5];
// 使用b
```

为何？

`std::vector<bool>`经过了特化，它的`operator[]`返回的是一个`std::vector<bool>::reference`型别的对象，它是一个叫作“代理类”的东西。

我们无法得到一个引用到比特的对象（`std::vector<bool>`用比特存储一个bool），故而它的内部实现做了一些工作。

`bvec[5]`返回了一个临时的对象，而此对象会马上被析构，而其副本b就拥有了一个空悬的指针（可能的实现），对它进行解引用就会出现未定义行为。

但作者不认为这是auto的错，我们实际上要的是另一种型别，那么可以这样的方法：

```c++
auto b = static_cast<bool>(bvec[5]);
```

这种写法之所以被作者推崇，是因为它显式的表达了代码书写者的意图。比如，对于这样的代码：

```c++
double calcEpsilon();

float ep = calcEpsilon();
```

ep的型别表达的含义是模糊的，无法断定是疏忽大意，还是故意舍弃精度。

而这样：

```c++
auto ep = static_cast<float>(calcEpsilon());
```

就明显得多了，很显然就是故意舍弃了精度。