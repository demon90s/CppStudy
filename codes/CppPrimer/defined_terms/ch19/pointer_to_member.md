成员指针（pointer to member）其中既包含类类型，也包含指针所指的成员类型。成员指针的定义必须同时指定类的名字以及指针所指的成员类型：

```c++
T C::*pmem = &C::member;
```

该语句将pmem定义为一个指针，它可以指向类C的成员，并且该成员的类型是T，然后初始化pmem令其指向类C的名为member的成员。要使用该指针，我们提供C的一个对象或指针：

```c++
classobj.*pmem;
classptr->*pmem;
```

从classptr或classobj中获取member。
