练习13.4：假定Point是一个类类型，它有一个public的拷贝构造函数，指出下面程序片段中哪些地方使用了拷贝构造函数：

```
Point global;
Point foo_bar(Point arg)
{
	Point local = arg, *heap = new Point(global);
	*heap = local;
	Point pa[4] = {local, *heap};
	return *heap;
}
```

---

- Point arg，调用函数时用于初始化参数

- Point local = arg

- *heap = new Point(global)

- Point pa[4] = {local, *heap}; 使用了两次拷贝构造函数构造数组元素

- return *heap，用于初始化返回值
