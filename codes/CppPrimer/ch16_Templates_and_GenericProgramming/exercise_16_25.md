练习16.25：解释下面这些声明的含义：

```c++
extern template class vector<string>;
template class vector<Sales_data>;
```

---

对于带extern的声明，编译器不会在本文件将中生成模板的实例代码。将一个实例化声明为extern就表示承诺在程序其他位置有该实例化的一个非extern声明（定义）。

对于不带extern的声明，编译器会进行模板的实例化。
