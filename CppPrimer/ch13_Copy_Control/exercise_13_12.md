练习13.12：在下面的代码片段中会发生几次析构函数调用？

```
bool fcn(const Sales_data *trans, Sales_data accum)
{
	Sales_data item1(*trans), item2(accum);
	return item1.isbn() != item2.isbn();
}
```

---

- accum，函数结束时析构

- item1，函数结束时析构

- item2，函数结束时析构

- item1.isbn() != item2.isbn()表达式产生了两个临时的string对象，它们在表达式结束时析构
