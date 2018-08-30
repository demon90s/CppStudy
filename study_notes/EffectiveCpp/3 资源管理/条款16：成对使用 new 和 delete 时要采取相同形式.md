# 条款16：成对使用 new 和 delete 时要采取相同形式

---

以下的写法有什么错？

```c++
std::string* stringArray = new std::string[100];

delete stringArray;
```

程序行为未有定义。在我的 vs 上面，程序崩溃。

当你使用 new ，有两件事发生。第一，内存被分配出来（通过 operator new 函数）。第二，针对此内存会有一个（或更多）构造函数被调用。

当你使用 delete ，也有两件事发生：针对此内存会有一个（或更多）析构函数被调用，然后内存才被释放（通过 operator delete 函数）。

delete 的最大问题在于：即将被删除的内存之内究竟存有多少对象？这个问题的答案决定了有多少个析构函数必须被调用起来。

单一对象的内存布局一般而言不同于数组的内存布局。更明确地说，数组所用的内存通常还包括“数组大小”的记录，以便 delete 知道要调用多少次析构函数。单一对象的内存则没有这笔记录。

!!!note
	经过测试，在 vs 下，这个数组大小的记录放到了数组首元素地址的前一个字的位置上。这是跟编译器实现有关的。

规则很简单：如果你调用 new 时使用[]，则必须在对应调用 delete 时也使用[]。如果调用 new 时没有使用[]，那么在调用 delete 时也不应该使用[]。

对于 typedef 出来的一个数组，这个规则也很重要。

```c++
// 如果 typedef 了一个数组，那么也要使用 delete[] 删除动态数组
typedef std::string AddressLines[4];
std::string *pal = new AddressLines;

//delete pal;	// 行为未有定义！
delete[] pal;	// 正确
```

!!!tip "请记住"
	如果你调用 new 时使用[]，则必须在对应调用 delete 时也使用[]。如果调用 new 时没有使用[]，那么在调用 delete 时也不应该使用[]。