/*
 * 飞机票有冗长的标识数字，例如47715497443。为了有效，最后一位数字必须与其他位的数字为整体
 * 除以7后的余数相匹配。（例如，47715497443除以7的余数为3。）编写程序检查机票号是否有效：
 *
 * Enter ticket number: 47715497443
 * VALID
 *
 * 提示：不要试图在单步操作中读取数，而是使用 getchar 函数逐个获取数字。一次执行一个数字的除法，
 * 小心除法中不要包含最后一位数字。
 */

/*
 * PS: 提示的意思是，为了防止整型数值溢出。
 */

#include <stdio.h>

int main()
{
	int ch;
	int digit;			/* 当前处理的数字 0~9 */
	int check_number;	/* 当前判断的数字，超过了7则使用一次取余运算 */
	int tmp;

	printf("Enter ticket number: ");
	
	while ((ch = getchar()) != '\n') {
		digit = ch - '0';

		tmp = check_number * 10 + digit;
		check_number = tmp >= 7 ? tmp % 7 : tmp;
	}

	check_number = (tmp - digit) / 10;
	if (check_number == digit)
		printf("VALID\n");
	else
		printf("INVALID\n");

	return 0;
}
