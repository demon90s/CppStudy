# 条款17：以独立语句将 newed 对象置入智能指针

在资源被创建和资源被转换为资源管理对象两个时间点之间有可能发生异常干扰。

---

## 问题

```c++
// 会抛出一个异常的函数
int priority();

// 一个可能会发生内存泄漏的函数，籍由错误的初始化 pw
void processWidget(std::shared_ptr<Widget> pw, int priority);
```

如果这样调用 processWidget:

```c++
processWidget(new Widget, priority());
```

是无法通过编译的，因为 shared_ptr 的构造函数是 explicit 的，不能隐式转换。所以必须写成这样：

```c++
processWidget(std::shared_ptr<Widget>(new Widget), priority());
```

但这样却可能造成资源泄漏。

## 错误的根源

编译器产出一个 processWidget 调用码之前，必须首先核算即将被传递的各个实参：

- 调用 priority

- 执行 new Widget

- 调用 shared_ptr 构造函数

C++ 编译器以什么样的次序完成这些事情呢？弹性很大，可以确定的是 new Widget 一定执行于 shared_ptr 的构造函数调用之前。但 priority 的调用却可能乱入，造成这样的操作序列：

1. 执行 new Widget

2. 调用 priority

3. 调用 shared_ptr 构造函数

这样，万一对 priority 的调用导致了异常，那么 new Widget 返回的指针就会遗失，因为它尚未被置入 shared_ptr 内，从而造成了资源泄露。

## 解决方法

避免这类问题的办法很简单：使用分离语句，在单独语句内以智能指针存储 newed 所得的对象

```c++
std::shared_ptr<Widget> pw(new Widget);
processWidget(pw, priority());
```

之所以行得通，因为编译器对于“跨越语句的各项操作”没有重新排列的自由（只有在语句内它才拥有那个自由度）。

!!!tip "请记住"
	以独立语句将 newed 对象存储于（置入）智能指针内。如果不这样做，一旦异常被抛出，有可能导致难以察觉的资源泄露。