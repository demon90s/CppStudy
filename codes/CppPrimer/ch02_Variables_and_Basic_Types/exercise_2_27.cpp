/*
 * 练习2.27：下面哪些初始化是合法的？请说明原因。

(a) int i = -1, &r = 0;			(b) int *const p2 = &i2;
(c) const int i = -1, &r = 0;	(d) const int *const p3 = &i2;
(e) const int *p1 = &i2;		(f) const int &const r2;
(g) const int i2 = i, &r = i;

*/

/*

(a) 非法，r是一个普通引用，不能绑定到字面量。
(b) 合法，但前提是i2不是const int。
(c) 合法。r是一个常量引用，可以绑定到字面量。
(d) 合法。
(e) 合法。
(f) 非法。r2是一个引用，必须初始化，且没有const引用，只有指向常量的引用。
(g) 合法。

*/

int main()
{
	//const int i2 = 0;
	int i2 = 0;
	int *const p2 = &i2;
	*p2 = 1; // just use p2 to ignore warning

	//const int &const r2;

	return 0;
}
