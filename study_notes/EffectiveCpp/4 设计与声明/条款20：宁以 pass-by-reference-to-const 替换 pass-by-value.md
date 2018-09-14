# 条款20：宁以 pass-by-reference-to-const 替换 pass-by-value

---

缺省情况下C++以 by value 方式传递对象至函数，这意味着函数参数都是以实际实参的副本为初值。这些副本系有对象的 copy 构造函数产出，这可能使得 pass-by-value 成为费时的操作。

对于这样的类型和这样的调用：

```c++
class Person
{
public:
	Person() {}
	virtual ~Person() {}

private:
	std::string name = "DefaultName";
	std::string address = "DefaultAddr";
};

class Student : public Person
{
public:
	Student() {}
	~Student() {}

private:
	std::string schoolName = "DefaultSchoolName";
	std::string schoolAddress = "DefaultSchoolAddr";
};

inline bool validateStudent(Student s) { /*...*/ } // 函数以 by-value	方式传递参数
```

## 提高效率

函数 validateStudent 调用时， Student 的 copy 构造函数会被调用，函数返回时，s会被销毁。因此，对函数而言，参数的传递成本是“一次 Student copy 构造函数的调用，加上一次 Student 析构函数的调用”。

又由于 Student 里面有两个 string 对象，其基类也有 string 对象，所以也必须执行若干次 string 的构造和析构操作。如果能以 pass by reference to const 的方式调用，就会高效很多：

```c++
inline bool validateStudent(const Student& s) { /*...*/ } // pass=by-reference-to-const
```

这种传递方式没有任何构造函数或析构函数被调用，因为没有任何新对象被创建。 将参数声明为 const 也是很重要的，这样就可以保证不会对实参做修改。

## 避免对象切割

以 by reference 方式传递参数也可以避免 slicing （对象切割）问题。当一个 derived class 对象以 by value 方式传递并被视为一个 bass class 对象， bass class 的 copy 构造函数会被调用，而“造成此对象的行为像个 derived class 对象”的那些特化性质全被切割掉了，仅仅留下一个 base class 对象。

!!!note "my note"
	就是拿派生类的实参采用 copy 初始化一个基类的形参，会被切割。

解决 slicing 问题的办法，就是以 by reference-to-const 的方式传递参数。

## 更多讨论

如果窥视C++编译器的底层， reference 往往以指针实现出来，因此 pass by reference 通常意味着真正传递的是指针。因此如果你有一个对象属于内置类型， pass by value 往往比 pass by reference 的效率更高些，这也适用于 STL 的迭代器和函数对象，因为习惯上它们都被设计为 pass by value 。

!!!tip "请记住"
	- 尽量以 pass-by-reference-to-const 替换 pass-by-value 。前者通常比较高效，并可避免切割问题（ slicing problem ）。
	- 以上规则并不适用于内置类型，以及 STL 的迭代器和函数对象。对它们而言， pass-by-value 往往比较适当。