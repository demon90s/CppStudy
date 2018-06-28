# 条款02：尽量以const, enum, inline替换#define

---

`#define`并不被视为语言的一部分。比如：

```c++
#define ASPECT_RATIO 1.653	// 宏定义不会计入记号表（symbol table）
```

宏定义在预编译阶段就被替换了，因此ASPECT_RATIO也许从未被编译器看到。这会导致这样的问题：如果运用这个宏获得一个编译错误时，错误信息也许不会提到ASPECT_RATIO，而提到了1.653，显然这会造成困惑。

解决这个问题的方法是用常量替换宏：

```c++
const double AspectRatio = 1.653;	// 使用常量替换上述宏
```

!!!note "my note"
	默认情况下，const对象仅在文件内有效，因此把这个定义放入头文件并不会造成重定义。

AspectRatio肯定会被编译器看到，并进入记号表。此外，对于浮点常量而言，使用常量可能比使用#define导致较小量的码。因为使用宏替换会导致出现多份1.653，而改用常量则不会。

关于常量替换#define，还有两种特殊情况。一种是常量指针。由于常量定义式通常被放在头文件中，因此就要把指针声明为const：

```c++
const char* const authorName = "Scott Meyers";
```

第二种情况是class专属常量，一个static成员。

```c++
class GamePlayer
{
private:
	static const int NumTurns = 5;	// 常量声明式
	int scores[NumTurns];			// 使用该常量
};
```

我们应该使用template inline函数来代替像函数一样的宏。它既能获得宏带来的效率，而且比宏更安全。

比如使用下面的函数：

```c++
template<typename T>
inline void CallWithMax(const T &a, const T &b)
{
	rule02_f(a > b ? a : b);
}
```

代替宏：

```c++
#define CALL_WITH_MAX(a, b) rule02_f((a) > (b) ? (a) : (b))
```

!!!tip "请记住"
	- 对于单纯常量，最好以const对象替换#define。
	- 对于形似函数的宏（macros），最好改用inline函数替换之。