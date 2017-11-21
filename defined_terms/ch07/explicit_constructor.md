显式构造函数（explicit constructor）可以用一个单独的实参调用但是不能用于[隐式转换的构造函数](./converting_constructor.md)。通过在构造函数的声明之前加上explicit关键字就可以将其声明成显示构造函数。

见p265。

只能在类内声明构造函数时使用explicit关键字，在类外部定义时不应重复。
