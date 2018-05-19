练习16.44：使用与第一题中相同的三个调用，如果g的函数参数声明为T（而不是T&&），确定T的类型。如果g的函数参数是const T&呢？

练习16.42：对下面的每个调用，确定T和val的类型：

```c++
template<typename T> void g(T&& val);
int i = 0; const int ci = i;
```

---

**如果是g(T val)**

(a) g(i);			// int

(b) g(ci);			// int

(c) g(i * ci);		// int

**如果是g(const T&)**

(a) g(i);			// int

(b) g(ci);			// int

(c) g(i * ci);		// int
