# 条款10：令operator=返回一个reference to this

---

我们可以把赋值写成连锁的形式：

```c++
int x, y, z;
x = y = z = 15;
```

赋值采用右结合律，所以上述操作符解析为：

```c++
x = (y = (z = 15));
```

为了实现“连锁赋值”，赋值操作符必须返回一个reference指向操作符左侧的实参。这是你为classes实现赋值操作符时应该遵循的协议：

```c++
class Widget
{
public:
	Widget() : i(0) {}
	Widget& operator=(const Widget &rhs)
	{
		i = rhs.i;
		return *this;
	}

	Widget& operator+=(const Widget& rhs)	// 适用于+=, -=, *=, 等等
	{
		i += rhs.i;
		return *this;
	}

	Widget& operator=(int rhs)	// 也适用，即使参数类型不符合协定
	{
		i = rhs;
		return *this;
	}

private:
	int i;
};
```

这是个协议，如果不遵循它，代码一样可以通过编译。然而这份协议被所有内置类型和标准库程序遵守。所以你也应该遵守。

!!!tip "请记住"
	令赋值（assignment）操作符返回一个reference to \*this。