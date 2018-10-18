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


[条款18：让接口容易被正确使用，不易被误用](./src/rules/rule18.h)


[条款19：设计 class 犹如设计 type](./src/rules/rule19.h)


[条款20：宁以 pass-by-reference-to-const 替换 pass-by-value](./src/rules/rule20.h)


[条款21：必须返回对象时，别妄想返回其 reference](./src/rules/rule21.h)


[条款22：将成员变量声明为 private](./src/rules/rule22.h)


[条款23：宁以 non-member, non-friend 替换 member 函数](./src/rules/rule23.h)


[条款24：若所有参数皆需类型转换，请为此采用 non-member 函数](./src/rules/rule24.h)


[条款25：考虑写出一个不抛异常的 swap 函数](./src/rules/rule25.h)


[条款26：尽可能延后变量定义式的出现时间](./src/rules/rule26.h)

