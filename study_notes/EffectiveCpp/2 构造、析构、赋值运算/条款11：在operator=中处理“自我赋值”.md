# 条款11：在operator=中处理“自我赋值”

---

自我赋值：

```c++
Widget w(42);
w = w;				// 自赋值
```

尽管这看上去有点愚蠢，但实际上是可能发生的，这是由于别名的存在：

```c++
a[i] = a[j];		// 潜在的自我赋值
*px = *py;			// 潜在的自我复制

// rb和pd有可能指的是同一个对象
void DoSomething(const Base& rb, Derived* pd) {}
```

## 问题

假如类里面有一个指针ip管理着的动态资源，那么这样写就是错误的，它无法处理自赋值：

```c++
delete ip;
ip = new int(*rhs.ip);
return *this;
```

这是由于如果是自赋值，那么ip delete掉后，就无法再使用了。

## 使用证同测试

证同测试可以阻止这种错误：

```c++
if (this == &rhs) return *this;

delete ip;
ip = new int(*rhs.ip);
return *this;
```

但这种方法不具备“异常安全性”，new可能造成异常，这时候ip就丢失了状态了。而且证同测试有一个判断的步骤，这会使代码大一些，甚至降低执行速度。

## 正确的做法

只需要精心安排一些语句就可以做出异常安全的代码：

```c++
int *tmp = ip;
ip = new int(*rhs.ip);
delete tmp;
return *this;
```

!!!note "my note"
	即先 new ，然后 delete ，保证 new 成功。

## copy and swap技术

这也是一个正确的做法：

```c++
Widget tmp(rhs);	// 临时的副本是安全的，它会自动销毁
swap(tmp);
return *this;
```

将“copying动作”从函数本体内移至“函数参数构造阶段”可以令编译器有时生成更高效的代码。

!!!tip "请记住"
	- 确保当对象自我赋值时operator=有良好行为。其中技术包括比较“来源对象”和“目标对象”的地址、精心周到的语句顺序、以及copy-and-swap。
	- 确定任何函数如果操作一个以上的对象，而其中多个对象是同一个对象时，其行为仍然正确。