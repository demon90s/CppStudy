/*
 * 练习1.7：编译一个包含不正确的嵌套注释的程序，观察编译器返回的错误信息
 */

/*
 * $ g++ exercise_1_7.cpp
 * error: expected unqualified-id before ‘/’ token
 */

/*
 * /*这是一个错误的嵌套注释*/
 *
 */
int main()
{
	return 0;
}

