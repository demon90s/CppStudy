> 练习6.48：说明下面这个循环的含义，它对assert的使用合理吗？

```
string s;
while (cin >> s && s != sought) {} // 空函数体
assert(cin);
```
---

不合理，因为读到文件尾也会使得cin失效。这种属于正常情况，但assert会导致程序异常结束。
