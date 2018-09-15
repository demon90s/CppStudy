/*
 * 下列哪些在C语言中不是合法的类型？
 *
 * (a) short unsigned int
 * (b) short float
 * (c) long double
 * (d) unsigned long
 */

int main()
{
	short unsigned int sui; (void)sui;

	/* short float sf;  不合法的 */

	long double ld; (void)ld;

	unsigned long ul; (void)ul;

	return 0;
}
