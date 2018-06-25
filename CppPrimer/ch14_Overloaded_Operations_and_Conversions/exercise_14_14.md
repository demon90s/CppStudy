练习14.14：你觉得为什么调用operator+=来定义operator+比其他方法更有效？

---

据说更高效（更少的拷贝次数）：https://stackoverflow.com/questions/21071167/why-is-it-more-efficient-to-define-operator-to-call-operator-rather-than-the

但我尚未能明白，假如我写成这样：

```
Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs)
{
	Sales_data sum;
	sum.units_sold = lhs.units_sold + rhs.units_sold;
	sum.revenue = lhs.revenue + rhs.revenue;
	return sum;
}
```

看上去效率是一样的。
