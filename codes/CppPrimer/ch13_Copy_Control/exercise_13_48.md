练习13.48：定义一个vector<String>并在其上多次调用push_back。运行你的程序，并观察String被拷贝了多少次。

---

见[String案例func4](./example_String/main.cpp)

观察结果：当vector重新分配空间时，原来的对象也会被拷贝到新的空间。
