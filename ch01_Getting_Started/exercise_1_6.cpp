/*
 * 练习1.6：解释下面程序片段是否合法：
 * std::cout << "The sum of " << v1;
 *           << " and " << v2;
 *           << " is " << v1 + v2 << std::endl;
 */

/*
 * 不合法。
 * expected primary-expression before ‘<<’ token
 * 解决办法：移除多余的分号。
 *
 * std::cout << "The sum of " << v1
 *           << " and " << v2
 *           << " is " << v1 + v2 << std::endl;
 *
 */

#include <iostream>

int main()
{
	int v1 = 0, v2 = 0;
	std::cout << "The sum of " << v1
	          << " and " << v2
			  << " is " << v1 + v2 << std::endl;

	return 0;
}
