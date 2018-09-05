# Effective C++ Rules

测试环境：vs2015 CentOS7，使用 CMake 构建

---

[条款01：视C++为一个语言联邦](./src/rules/rule01.h)


[条款02：尽量以const, enum, inline替换#define](./src/rules/rule02.h)


[条款03：尽可能使用const](./src/rules/rule03.h)


[条款04：确定对象被使用前已被初始化](./src/rules/rule04.h)


[条款05：了解C++默默编写并调用哪些函数](./src/rules/rule05.h)


[条款06：若不想使用编译器自动生成的函数，就该明确拒绝](./src/rules/rule06.h)


[条款07：为多态基类声明virtual析构函数](./src/rules/rule07.h)


[条款08：别让异常逃离析构函数](./src/rules/rule08.h)


[条款09：绝不在构造和析构过程中调用virtual函数](./src/rules/rule09.h)


[条款10：令operator=返回一个reference to this](./src/rules/rule10.h)


[条款11：在operator=中处理“自我赋值”](./src/rules/rule11.h)


[条款12：复制对象时勿忘其每一个成分](./src/rules/rule12.h)


[条款13：以对象管理资源](./src/rules/rule13.h)


[条款14：在资源管理类中小心 copying 行为](./src/rules/rule14.h)


[条款15：在资源管理类中提供对原始资源的访问](./src/rules/rule15.h)


[条款16：成对使用 new 和 delete 时要采取相同的形式](./src/rules/rule16.h)


[条款17：以独立语句将 newed 对象置入智能指针](./src/rules/rule17.h)

