练习14.52：在下面的加法表达式中分别选用了哪个operator+？列出候选函数、可行函数及为每个可行函数的实参执行的类型转换：

```
struct LongDouble {
	LongDouble operator+(const SmallInt&);
};

LongDouble operator+(LongDouble&, double);
SmallInt si;
LongDouble ld;
ld = si + ld;
ld = ld + si;
```

---

**对于`ld = si + ld;`，都是可行函数，但有二义性。**

对于operator+(LongDouble&, double)，实参转换路径是：

- si -> int -> double -> LongDouble

- ld -> double

对于LongDouble::operator+(const SmallInt&)，实参转换路径是：

- si -> int -> double -> LongDouble

- ld -> double -> int -> SmallInt

**对于`ld = ld + si;`，都是可行函数，但LongDouble::operator+(const SmallInt&)更佳。**

对于operator+(LongDouble&, double)，实参转换路径是：

- ld无需转换

- si -> int -> double

对于LongDouble::operator+(const SmallInt&)，实参转换路径是：

- ld无需转换

- si无需转换
