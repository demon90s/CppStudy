练习16.36：进行下面的调用会发生什么：

```c++
template <typename T> void f1(T, T);
tempalte <typename T1, typename T2> void f2(T1, T2);

int i = 0, j = 42, *p1 = &i, *p2 = &j;
const int *cp1 = &i, *cp2 = &j;
```

(a) f1(p1, p2);		// f1(int*, int*)

(b) f2(p1, p2);		// f2(int*, int*)

(c) f1(cp1, cp2);	// f1(const int*, const int*)

(d) f2(cp1, cp2);	// f2(const int*, const int*)

(e) f1(p1, cp1);	// 错误，p1和cp1类型不一致

(f) f2(p1, cp1);	// f2(int*, const int*);
