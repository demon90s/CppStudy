# 条款19：设计 class 犹如设计 type

---

当你定义了一个新的 class ，也就定义了一个新 type 。身为C++程序员，你的许多时间主要用来扩张你的类型系统（ type system ）。

好的 type 有自然的语法，直观的语义，以及一个或多个高效实现品。

如果设计高效的 class 呢？首先你必须了解你面对的问题。几乎每一个 class 都要求你面对以下提问，而你的回答往往导致你的设计规范。

- 新的 type 的对象应该如何被创建和销毁？这会影响到你的 class 的构造函数和析构函数以及内存分配函数和释放函数的设计。

- 对象的初始化和对象的赋值该有什么样的差别？这个答案决定你的构造函数和赋值操作符的行为。

- 新 type 的对象如果被 pass by value ，意味着什么？记住， copy 构造函数用来定义一个 type 的 pass by value 该如何实现。

- 什么是新 type 的“合法值”？对 class 的成员变量而言，通常只有某些数值集是有效的。

- 你的新 type 需要什么样的转换？ 使用 type conversion operators 和 non-explicit-one-argument constructor 。

- 什么样的操作符和函数对此新 type 而言是合理的？

- 什么样的标准函数应该驳回？

- 谁该取用新 type 的成员？

- 什么是新 type 的“未声明接口”？

- 你的新 type 有多么一般化？或许你其实并非定义一个新 type ，而是定义一整个 types 家族。果真如此你就不该定义一个新 class ，而是应该定义一个新的 class template 。

- 你真的需要一个新 type 吗？如果只是定义新的 derived class 以便为既有的 class 添加机能，那么说不定单纯定义一个或多个 non-member 函数或 templates ，更能够达到目标。

!!!tip "请记住"
	class 的设计就是 type 的设计。在定义一个新 type 之前，请确定你已经考虑过本条款覆盖的所有讨论主题。