# 条款24：若所有参数皆需类型转换，请为此采用 non-member 函数

---

比如有这样的有理数类型：

```c++
class Rational {
public:
	// 构造函数刻意不为 explicit ，从而允许 int-to-Rational 隐式转换
	Rational(int numberator = 0, int denominator = 1) : numberator_(numberator), denominator_(denominator) {}

	int numerator() const { return numberator_; }
	int denominator() const { return denominator_; }

private:
	int numberator_, denominator_;
};
```

为了使其支持乘法运算，那么可以将这个操作符重载为成员函数，也可以重载成一个非成员函数，那么该如何选择？

假如是成员函数，那么是这样的：

```c++
const Rational operator* (const Rational& rhs) const
{
	return Rational(numberator_ * rhs.numberator_, denominator_ * rhs.denominator_);
}
```

它支持这样的语句：

```c++
Rational oneEight(1, 8);
Rational result = oneEight * 2; // OK
```

但不支持这样的语句：

```c++
result = 2 * oneEight; // 不 OK
```

因为下面的2没有办法隐式转换成 Rational 类型，而上面的可以。

因此要选择非成员函数的版本：

```c++
const Rational operator*(const Rational &lhs, const Rational &rhs)
{
	return Rational(lhs.numerator() * rhs.numerator(), lhs.denominator() * rhs.denominator());
}
```

这样无论怎样都可以进行隐式转换了。

!!!tip "请记住"
	如果你需要为某个函数的所有参数（包括被 this 指针所指的那个隐喻参数）进行类型转换，那么这个函数必须是个 non-member 。