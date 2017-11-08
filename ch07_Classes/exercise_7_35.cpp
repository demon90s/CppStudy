/*
 * 练习7.35：解释下面代码的含义，说明其中的Type和initVal分别使用了哪个定
 * 义。如果代码存在错误，尝试修改它。
 */

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;

typedef string Type;
Type initVal();		// string
class Exercise {
public:
	typedef double Type;
	Type setVal(Type);	// double
	Type initVal();		// double
private:
	int val;
};

/*
 * 返回类型Type是string，类没有这个声明，是错误的。
 * 参数Type是double，没问题
 * initVal缺少实现，有链接错误
 */
/*
Type Exercise::setVal(Type parm) {
	val = parm + initVal();
	return val;
}
*/

// 改成下面这样
Exercise::Type Exercise::setVal(Type parm) {
	val = parm + initVal();
	return val;
}

inline
Exercise::Type Exercise::initVal()
{
	return 1.0;
}

int main()
{
	return 0;
}
