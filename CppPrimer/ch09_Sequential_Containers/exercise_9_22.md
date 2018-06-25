> 练习9.22：假定iv是一个int的vector，下面的程序存在什么错误？你将如何修改？

```
vector<int>::iterator iter = iv.begin(),
                      mid = iv.begin() + iv.size()/2;

while (iter != mid)
	if (*iter == some_val)
		iv.insert(iter, 2 * some_val);
```

---

1. 插入操作会使vector中所有的迭代器失效，如果继续使用将出现未定义的错误。

2. 没有递增iter，可能死循环。

这样修改：

```
vector<int>::iterator iter = iv.begin(),
                      mid = iv.begin() + iv.size()/2;

while (iter != mid) {
	if (*iter == some_val) {
		iter = iv.insert(iter, 2 * some_val);
		++iter;
		mid = iv.begin() + iv.size()/2;
	}
	++iter;
}
```
