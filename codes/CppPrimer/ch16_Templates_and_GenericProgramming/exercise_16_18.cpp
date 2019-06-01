// 练习16.18：解释下面每个函数模板声明并指出它们是否非法。更正你发现的每个错误。
/*
 * (a) template<typename T, U, typename V> void f1(T, U, V);
 * (b) template<typename T> T f2(int &T);
 * (c) inline template<typename T> T foo(T, unsigned int*);
 * (d) template<typename T> f4(T, T);
 * (e) typedef char Ctype;
 *     template<typename Ctype> Ctype f5(Ctype a);
 */

// (a) 错误：error: ‘U’ has not been declared
// template<typename T, U, typename V> void f1(T, U, V);
template<typename T, typename U, typename V> void f1(T, U, V);

// (b) 错误，T是一个类型，而非参数名
//template<typename T> T f2(int &T);
template<typename T> T f2(int&);

// (c) 错误，template必须放在开头
//inline template<typename T> T foo(T, unsigned int*);
template<typename T> inline T foo(T, unsigned int*);

// (d) 错误，函数没有返回值
//template<typename T> f4(T, T); 
template<typename T> void f4(T, T); 

// (e) 正确，模板参数隐藏了类型别名
typedef char Ctype;
template<typename Ctype> Ctype f5(Ctype a);

#include <iostream>

using namespace std;

int main()
{
	return 0;
}
