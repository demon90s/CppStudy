练习14.47：说明下面这两个类型转换运算符的区别。

```
struct Integral {
	operator const int();
	operator int() const;
}:
```

---

- 第一个说明实例对象不能是const的（因为传入普通的this指针），类型转换得到一个const int的值。

- 第二个说明实例对象可以是const的（因为传入const的this指针），类型转换得到一个int的值。
