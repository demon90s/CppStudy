using声明（using declaration）是一种将命名空间中的某个名字注入当前作用域的机制：

```c++
using std::cout;
```

上述语句使得命名空间std中的名字cout在当前作用域可见。之后，我们就可以直接使用cout而无须前缀std::了。
