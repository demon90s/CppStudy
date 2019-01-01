#include <iostream>
#include <type_traits>
#include <typeinfo>

// 使用 is_same 检查两个类型是否一样

template<typename T1, typename T2>
void StaticCheckType(const T1&, const T2&)
{
	static_assert(std::is_same<T1, T2>::value, "StaticCheckType failure");
}

void Func() {}

int main()
{
	auto p = &Func;
	decltype(Func) f_t;
	decltype(Func) *pf_t;
	decltype(*Func) f2_t = Func;
	//StaticCheckType(f_t, p); // failure
	StaticCheckType(pf_t, p); // success
	//StaticCheckType(f2_t, p); // failure
	StaticCheckType(f2_t, Func); // succesz

	return 0;
}
