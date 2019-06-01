练习12.7：下面的unique_ptr声明中，哪些是合法的，哪些可能导致后续的程序错误？解释每个错误的问题在哪里。

```
int ix = 1024, *pi = &ix, *pi2 = new int(1024);
typedef unique_ptr<int> IntP;
```

(a) IntP p0(ix); // 错误，unique_ptr只能指向一块动态内存

(b) IntP p1(pi); // 错误，pi指向的不是一块动态内存

(c) IntP p2(pi2); // 正确，但是pi2不能再手动释放

(d) IntP p3(&ix); // 错误，unique_ptr只能指向一块动态内存

(e) IntP p4(new int(2048)); // 正确

(f) IntP p5(p2.get()); // 错误，p2.get()获得的指针不可以初始化智能指针
