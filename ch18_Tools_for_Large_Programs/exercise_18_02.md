练习18.2：当在指定的位置发生了异常时将出现什么情况？

```c++
void exercise(int *b, int *e)
{
	vector<int> v(b, e);
	int *p = new int[v.size()];
	ifstream in("ints");
	// 此处发生异常
}
```

---

p所指的内存发生泄漏。
