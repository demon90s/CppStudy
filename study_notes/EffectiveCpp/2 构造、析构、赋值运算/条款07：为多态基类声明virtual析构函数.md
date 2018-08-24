# 条款07：为多态基类声明virtual析构函数

---

## 问题1：多态基类将析构函数声明成non-virtual

当我们使用一个heap上的对象后，为了避免泄漏内存和其他资源，需要对其进行delete。

```c++
TimeKeeper *ptk = getTimeKeeper();		// 获得一个动态分配的对象（派生类对象）
//...
delete ptk;								// 释放它，避免泄漏资源
```

假如TimeKeeper有一个non-virtual的析构函数，那么这就会引发灾难。因为C++明白指出，当derived class对象经由一个base class指针被删除，而该bass class带着一个non-virtual析构函数，其结果未定义。

实际执行时通常发生的是对象的derived成分没被销毁。然而其base class成分通常会被销毁，于是造成一个“局部销毁”对象。

消除这个问题的做法很简单：给base class一个virtual析构函数。此后删除derived class对象就会如你想要的那般，销毁整个对象。

```c++
class TimeKeeper
{
public:
	TimeKeeper();
	virtual ~TimeKeeper();
};
```

任何class只要带有virtual函数几乎确定应该也有一个virtual析构函数。

## 问题2：非多态基类声明了一个virtual函数

如果class不含virtual函数，通常表示它并不意图被用做一个base class。这个时候，令其析构函数为virtual往往是个馊主意。比如：

```c++
class Point
{
public:
	Point(int xCoord, int yCoord);
	~Point();

private:
	int x, y;
};
```

如果int占用32bits，那么Point对象可塞入一个64-bit缓存器中。

欲实现出virtual函数，对象必须携带某些信息，主要用来在运行期决定哪一个virtual函数该被调用。这份信息通常是由一个所谓vptr(virtual table pointer)指针指出。vptr指向一个由函数指针构成的数组，称为vtbl(virtual table)；每一个带有virtual函数的class都有一个相应的vtbl。当对象调用某一virtual函数，实际被调用的函数取决于该对象的vptr所指的那个vtbl。

如果Point class内含virtual函数，其对象的体积会增加：32bit - 64bit。因此，无端地将所有classes的析构函数声明为virtual，是错误的。

如果你企图继承一个标准库容器或任何其他“带有non-virtual析构函数”的class，拒绝诱惑！

## pure virtual析构函数

pure virtual函数导致abstract classes，也就是不能被实体化的class。有时候你希望拥有抽象class，但手上没有任何pure virtual函数怎么办？很简单：为它声明一个pure virtual析构函数：

```c++
class AWOV							// AWOV = "Abstract w/o Virtuals"
{
public:
	virtual ~AWOV() = 0;			// 声明pure virtual析构函数
};
```

你必须为这个pure virtual析构函数提供一份定义：

```c++
AWOV::~AWOV() {}
```

析构函数的运作方式是，最深层派生（most derived）的那个class其析构函数最先被调用，然后是其每一个base class的析构函数被调用。编译器会在AWOV的derived classes的析构函数中创建一个对`~AWOV`的调用动作，所以你必须为这个函数提供一份定义。

!!!tip "请记住"
	- polymorphic（带有多态性质的）base classes应该声明一个virtual析构函数。如果class带有任何virtual函数，它就应该拥有一个virtual析构函数。
	- Classes的设计目的如果不是作为base classes使用，或不是为了具备多态性，就不该声明virtual析构函数。