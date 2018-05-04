练习2.38：说明由decltype指定类型和由auto指定类型有何区别。请举出一个例子，decltype指定的类型与auto指定的类型一样；再举一个例子，decltype指定的类型与auto指定的类型不一样。

auto定义的变量必须有初始值，因为编译器是根据其初始值推断其类型，decltype是根据给它的表达式来推断类型。
auto定义的类型和其初始值类型可能并不完全一样，decltype得到的类型和给它的表达式类型一样。
auto一般会忽略掉顶层const，而decltype会保留。

一样的例子：
int i = 0;
decltype(i) a = i; // a is int
auto b = i; // b is int

不一样的类型：
int i = 0, &r = i;
decltype(r) a = i; // a is int&
auto b = r; // b is int
