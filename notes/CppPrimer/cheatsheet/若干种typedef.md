# 若干种typedef

---

## 代码案例

```c++
typedef long long 		Int64;			// 简单的类型别名
typedef char			Name[32];		// 数组类型别名（char[32]）
typedef void 			(*Func)(int);	// 函数指针类型
typedef Blob<string>	StrBlob;		// 模板类型别名
```

## 函数指针在类中

```c++
class Funcs;
typedef void		(Funcs::*f)();	// Funcs类里面的函数指针类型
class Funcs {
public:
	Funcs() {
		funcs_map.insert({"f1", &Funcs::f1});
	}

	void Call(const std::string &func)
	{
		auto it = funcs_map.find(func);
		if (it != funcs_map.end())
		{
			auto func = it->second;
			(this->*func)();
		}
	}

private:
	void f1() { cout << "f1" << endl; }
	std::map<std::string, f> funcs_map;
};
```
