/*
 * 判断下列哪些是不合法的C语言标识符？
 * (a) 100_bottles
 * (b) _100_bottles
 * (c) one_hundred_bottles
 * (d) bottles_by_the_hundred
 */

int main()
{
	/* int 100_bottles; */	/* 不合法 */
	int _100_bottles;
	int one_hundred_bottles;
	int bottles_by_the_hundred;

	return 0;
}
