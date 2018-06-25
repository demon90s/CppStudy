练习12.9：解释下面代码执行的结果：

```
int *q = new int(42), *r = new int(100);
r = q;	// 出现内存泄漏，r指向的动态对象无法被释放了

auto q2 = make_shared<int>(42), r2 = make_shared<int>(100);
r2 = q2; // 不会有问题，r2指向的动态对象被释放
```
