> 练习7.49：对于combine函数的三种不同声明，当我们调用`i.combine(s)`时分别发生什么情况？其中i是一个Sales_data，而s是一个string对象。

(a) Sales_data &combine(Sales_data);

(b) Sales_data &combine(Sales_data&);

(c) Sales_data &combine(const Sales_data&) const;

---

(a) s隐式转换成一个临时的Sales_data对象，然后作为实参传递给成员函数。

(b) 错误，临时对象没有办法初始化非常量引用。

(c) 声明错误，传入const this的函数不能返回非常量的自身引用。
