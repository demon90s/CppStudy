练习16.42：对下面的每个调用，确定T和val的类型：

```c++
template<typename T> void g(T&& val);
int i = 0; const int ci = i;
```

---

(a) g(i);			// T类型是 int&, val类型是 int& &&，折叠成 int&

(b) g(ci);			// T类型是 const int&，val类型是 const int& &&，折叠成 const int&

(c) g(i * ci);		// T类型是 int，val类型是int&&
