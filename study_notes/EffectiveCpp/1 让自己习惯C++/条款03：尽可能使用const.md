# 条款03：尽可能使用const

const允许你指定一个语义约束，而编译器会强制实施这项约束。

---

## const与指针

对于指针类型的变量，如果关键字const出现在星号左边，表示被指物是常量；如果出现在星号右边，表示指针自身是常量；如果出现在星号两边，表示被指物和指针两者都是常量。

```c++
char greeting[] = "Hello";
	
char *p = greeting;					// non-const pointer, non-const data
const char *lcp = greeting;			// non-const pointer, const data(low-level const)
char *const tcp = greeting;			// const pointer, non-const data(top-level const)
const char* const cp = greeting;	// const pointer, const data
```

!!!note
	low-level const（底层const），是指指针所指物为常量；top-level const（顶层const），是指指针自身是常量。

## const与迭代器

STL迭代器以指针为根据塑模出来，所以迭代器的作用就像个T\*指针。声明迭代器为const表示这个迭代器不得指向别的东西，但它所指的东西可以改变。如果你希望迭代器所指的值东西不可被改动，你需要的是const_iterator：

```c++
std::vector<int> vec{1, 2, 3, 4};

const std::vector<int>::iterator iter = vec.begin();	// iter的作用像个T *const
*iter = 10;				// 没问题，改变iter所指物
///++iter;				// 错误！iter是const

std::vector<int>::const_iterator citer = vec.begin();	// iter的作用像个const T*
//*citer = 10;			// 错误！*citer是const
++citer;				// 没问题，改变citer
```

## const与函数

在一个函数声明式内，const可以和函数返回值、参数、函数自身（如果是成员函数）产生关联。

令函数返回一个常量值，往往可以降低因客户错误而造成的意外。比如，有这样的operator\*声明式：

```c++
const Rational operator*(const Rational& lhs, const Rational& rhs);
```

返回一个const临时对象的原因是，客户可能出现这样的打字错误：

```c++
if (a * b = c) { /* ... */ }
```

如果operator\*返回一个const，那么就可以完全阻止这样的错误。使用const参数同样出于这样的原因。

**const成员函数**

将const实施于成员函数的目的，是为了确认该成员函数可以作用于const对象身上。这一类成员函数之所以重要，基于两个理由：

1. 它们使class接口比较容易被理解。因为可以方便得知哪些函数会修改对象内容。

2. 它们使操作const对象成为可能。