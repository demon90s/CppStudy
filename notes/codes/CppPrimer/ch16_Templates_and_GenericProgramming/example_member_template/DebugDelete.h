#include <iostream>
#include <memory>

using namespace std;

// 函数对象类，对给定指针执行delete
class DebugDelete {
public:
	DebugDelete(std::ostream &s = std::cerr) : os(s) {}
	// 与任何函数模板相同，T的类型由编译器推断
	template<typename T> void operator()(T *p) const
	{ os << "deleting unique_ptr" << std::endl; delete p; }
private:
	std::ostream &os;
};
