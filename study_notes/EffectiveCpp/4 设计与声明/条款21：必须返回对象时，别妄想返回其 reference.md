# 条款21：必须返回对象时，别妄想返回其 reference

如果传递一些 references 指向其实并不存在的对象，就是一个致命的错误。

---

以这个类型作为说明：

```c++
class Rational {
public:
	Rational(int numerator = 0, int denominator = 1) : n(numerator), d(denominator) {}

private:
	int n, d;

	friend const Rational operator* (const Rational& lhs, const Rational &rhs);
};

// 这里应该返回一个值，而不是 reference
inline const Rational operator* (const Rational& lhs, const Rational &rhs)
{
	return Rational(lhs.n * rhs.n, lhs.d * rhs.d);
}
```

可能会想把乘法运算的返回值设置成引用，从而避免拷贝带来的开销。那么可能会想几个办法。

```c++
// 错误的方式，返回了 stack 对象，函数返回后已经不存在了
inline const Rational& operator* (const Rational& lhs, const Rational &rhs)
{
	Rational res(lhs.n * rhs.n, lhs.d * rhs.d);
	return res;
}
```

应该拒绝这种做法，因为它是错误的，而且为了避免拷贝构造，实际上还是做了一次拷贝构造，这没有意义。

```c++
// 更加错误的写法，很可能内存泄漏，而且没有意义
inline const Rational& operator* (const Rational& lhs, const Rational &rhs)
{
	Rational res = new Rational(lhs.n * rhs.n, lhs.d * rhs.d);
	return res;
}
```

上述做法很可能造成内存泄漏：

```c++
Rational w, x, y, z;
w = x * y * z;
```

另一种做法是返回一个 local static 对象：

```c++
inline const Rational& operator* (const Rational& lhs, const Rational &rhs)
{
	static Rational res;
	res.n = lhs.n * rhs.n;
	res.d = lhs.d * rhs.d;
	return res;
}
```

就像所有用上 static 对象的设计一样，这一个也立刻造成我们对多线程安全性的疑虑。就算没有多线程，这样做仍然会出问题：

```c++
Rational a, b, c, d;
if (a * b == c * d) {}
else {}
```

表达式 `(a * b == c * d)` 将总是得到 true 。因为它们返回的是同一个对象。

别忘了，C++允许编译器实现者施行最优化，用以改善产出码的效率却不改变其可观察的行为。因此某些情况下， `operator*`返回值的构造和析构可被安全地消除。如果编译器运用这一事实（它们也往往如此），你的程序将继续保持它们该有的行为，而执行起来又比预期的更快。

!!!tip "请记住"
	绝不要返回 pointer 或 reference 指向一个 local stack 对象，或返回 reference 指向一个 heap-allocated 对象，或返回 pointer 或 reference 指向一个 local static 对象而有可能同时需要多个这样的对象。