/*
 * 练习2.39：编译下面的程序观察其运行结果，注意，如果忘记写类定义体后面的分号会发生什么情况？记录下相关信息，以后可能会有用。
 */

/*
 * $ g++ -g -Wall -o exercise_2_39 exercise_2_39.cpp
 * error: expected ‘;’ after struct definition
 */

struct Foo {} // 注意：没有分号
int main()
{
	return 0;
}
