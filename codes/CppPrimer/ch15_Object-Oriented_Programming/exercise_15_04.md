练习15.4：下面哪条声明语句使不正确的？请解释原因。

class Base { ... };

(a) class Derived : public Derived { ... }; // 错误，一个类不能派生它本身

(b) class Derived : private Base { ... }; // 正确

(c) class Derived : public Base; // 错误，派生列表以及与定义有关的其他细节必须与类的主体一起出现。
