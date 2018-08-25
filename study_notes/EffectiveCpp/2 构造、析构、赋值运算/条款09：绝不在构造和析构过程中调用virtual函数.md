# 条款09：绝不在构造和析构过程中调用virtual函数

---

```c++
BuyTransaction b;
```

BuyTransaction是Transaction的派生类，而Transaction的构造函数中调用了一个虚函数logTransaction，那么这个虚函数将不会使用派生类的版本，而是Transaction的版本。

是的，base class构造期间virtual函数绝不会下降到derived classes阶层。非正式的说法是：在base class构造期间，virtual函数不是virtual函数。

这是由于base class构造函数的执行更早于derived class构造函数，当base class构造函数执行时derived class的成员变量尚未初始化。如果此期间调用的virtual函数下降至derived classes阶层，那么它的成员函数几乎必然取用local成员变量，但它们还没有初始化。所以C++不会允许这么做。

还有更根本的原因：在derived class对象的base class构造期间，对象的类型是base class而不是derived class。不只virtual函数会被编译器解析至（resolve to）base class，若使用运行期类型信息（runtime type information，例如dynamic_cast和typeid），也会把对象视为base class类型。

相同的道理也适用于析构函数。一旦derived class析构函数开始执行，对象内的derived class成员变量便呈现未定义值，所以C++视它们仿佛不存在。进入base class析构函数后对象就成为一个base class对象。

!!!note "my note"
	在构造或析构base class期间，派生类不存在，无法使用它。

## 正确的做法

但如何确保每一次一有Transaction继承体系上的对象被创建，就会有适当版本的logTransaction被调用呢？很显然，在Transaction构造函数内对着对象调用virtual函数是一种错误做法。

有一种做法是将logTransaction函数改为non-virtual，然后要求derived class构造函数传递必要的信息给Transaction构造函数。

```c++
class Transaction
{
public:
	explicit Transaction(const std::string& log_info)
	{
		logTransaction(log_info); // 如今是个non-virtual调用
	}

	void logTransaction(const std::string& log_info) const // 如今是个non-virtual函数
	{
		std::cout << log_info << std::endl;
	}
};

class BuyTransaction : public Transaction
{
public:
	BuyTransaction() : Transaction(createLogString("Construct")) {} // 将Log信息传递给base class构造函数

private:
	static std::string createLogString(const char* log) { return std::string("BuyTransaction_") + log; }
};
```

令createLogString为static，也就不可能意外指向“初期未成熟之BuyTransaction对象内尚未初始化的成员变量”。

!!!tip "请记住"
	在构造和析构期间不要调用virtual函数，因为这类调用从不下降至derived class（比起当前执行构造函数和析构函数那层）。