练习14.11：下面的Sales_data输入运算符存在错误码？如果有，请指出来。对于这个输入运算符如果仍然给定上个练习的输入将发生什么情况？

```
istream& operator>>(istream& in, Sales_data& s)
{
	double price;
	in >> s.bookNo >> s.units_sold >> price;
	s.revenue = s.units_sold * price;
	return in;
}
```

---

有错误，因为可能出现IO错误，从而导致后续的读取失败。由于没有考虑失败的情况，源数据可能会被修改成错误的状态。

上个练习中的b就会出现这种情况。
