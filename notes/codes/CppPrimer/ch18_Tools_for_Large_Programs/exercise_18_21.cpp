// 练习18.21：解释下列声明的含义，在它们当中存在错误吗？如果有，请指出来并说明
// 错误的原因。

// 为了通过编译，手动添加基类的定义
class CAD {};
class Vehicle {};
class List {};
class istream {};
class ostream {};

// (a) 正确，Vehicle默认使用private访问说明符
class CADVehicle : public CAD, Vehicle { };

// (b) 错误，在派生列表中，同一个基类只能出现一次
//class DblList : public List, public List { };

// (c) 正确
class iostream : public istream, public ostream {};

int main()
{
	return 0;
}
