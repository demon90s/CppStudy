练习16.27：对下面每条带标签的语句，解释发生了什么样的实例化（如果有的话）。如果一个模板被实例化，解释为什么；如果未实例化，解释为什么没有。

```c++
#include <iostream>

using namespace std;

template <typename T> class Stack {};

void f1(Stack<char>);					// (a) 不会被实例化，这里是函数声明，没有用到模板的实例

class Exercise {
	Stack<double> &rsd;					// (b) 不会被实例化，因为成员是引用
	Stack<int> si;						// (c) 实例化Stack<int>
};

int main()
{
	Stack<char> *sc;					// (d) 不会被实例化，这里只是定义了一个指针类型
	f1(*sc);							// (e) 实例化Stack<char>
	int iObj = sizeof(Stack<string>);	// (f) 实例化Stack<string>

	return 0;
}
```

---

这里都是普通的实例化，即当用到了模板的实例和模板实例的成员，才会实例化它们。
