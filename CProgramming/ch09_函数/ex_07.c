/*
 * 假设函数f有下列定义：
 *
 * int f(int a, int b) { ... }
 *
 * 那么下列哪条语句是合法的？（假设i的类型为 int 而x的类型为 float 。）
 */

int f(int a, int b) { return 0; }

int main()
{
	int i;
	float x;

	(void)i;
	(void)x;

	/* a 合法 */
	i = f(83, 12);

	/* b 合法 */
	x = f(83, 12);

	/* c 合法 */
	i = f(3.15, 9.28);

	/* d 合法 */
	x = f(3.15, 9.28);

	/* e 合法 */
	f(83, 12);

	return 0;
}
