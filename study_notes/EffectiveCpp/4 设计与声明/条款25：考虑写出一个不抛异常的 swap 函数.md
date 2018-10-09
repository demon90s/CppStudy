# 条款25：考虑写出一个不抛异常的 swap 函数

---

## 缺省 swap 的问题

swap 函数可以用于处理异常安全性编程，以及自我赋值。适当实现 swap 很重要。

所谓 swap 两对象的值，意思是将两对象的值彼此赋予对方。

缺省情况下， swap 动作可以由标准程序提供的 swap 算法完成。只要类型支持 copying 。

但缺省的实现版本有一个问题，复制的动作可能会降低效率。如果类型“以指针指向一个对象，内含真正数据”，那么缺省的操作仍然会拷贝这些数据，但实际上只需要交换指针就可以完成 swap 操作了。

```c++
class Widget {
public:
	Widget() : pImpl(new WidgetImpl) {}
	~Widget() { delete pImpl; }

	Widget(const Widget& rhs)	// 复制 Widget 时，令它复制其 WidghtImpl 对象
		: pImpl(new WidgetImpl(*rhs.pImpl))
	{}

	Widget& operator=(const Widget& rhs)
	{
		auto p = new WidgetImpl(*rhs.pImpl);
		delete pImpl;
		pImpl = p;
		return *this;
	}

	void swap(Widget& other)
	{
		using std::swap;
		swap(pImpl, other.pImpl);
	}

private:
	WidgetImpl *pImpl;		// 指针，所指对象含 Widget 数据
};
```

假如使用 std::swap 交换 Widget 对象，那么就会调用赋值操作，赋值操作会拷贝指针指向的数据，从而降低效率。

## 自己的解决方法

在书中，讨论了几种实现 swap 的方式，有在 std 命名空间中全特化 swap 函数的，但不能应用于模板类型，也有在 std 命名空间中偏特化 swap 函数的，但被标准拒绝。正确的做法就是在类中实现一个 swap 成员函数，这是为了能访问到私有成员。

然后在外部实现一个普通的 swap 函数，调用时，确定调用此函数：

```c++
inline void swap(Widget& a, Widget& b)
{
	a.swap(b);
}
```

对于调用标准的 swap 函数，应当指明其命名空间 std 。

## 书中给出的结论

首先，如果 swap 的缺省实现码对你的 class 或 class template 提供可接受的效率，你不需要做什么事情。

其次，如果 swap 的缺省实现版的效率不足，试着做以下事情：

1. 提供一个 public swap 成员函数，让它高效地置换你的类型的两个对象值，这个函数绝不该抛出异常。

2. 在你的 class 或 template 所在的命名空间内提供一个 non-member swap ，并令它调用上述 swap 成员函数。

3. 如果你正在编写一个 class （而非 class template），为你的 class 特化 std::swap 。并令它调用你的 swap 成员函数。

最后，如果你调用 swap ，请确定包含一个 using 声明式，以便让 std::swap 在你的函数内曝光可见，然后不加任何 namespace 修饰符，赤裸裸地调用 swap 。

!!!tip "请记住"
	- 当 std::swap 对你的类型效率不高时，提供一个 swap 成员函数，并确定这个函数不抛出异常。
	- 如果你提供一个 member swap ，也该提供一个 non-member swap 用来调用前者。对于 classes （而非 templates ），也请特化 std::swap 。
	- 调用 swap 时应针对 std::swap 使用 using 声明式，然后调用 swap 并且不带任何“命名空间资格修饰”。
	- 为“用户定义类型”进行 std templates 全特化是好的，但千万不要尝试在 std 内加入某些对 std 而言全新的东西。