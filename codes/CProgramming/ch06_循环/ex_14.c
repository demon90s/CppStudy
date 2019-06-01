/*
 * 下面的“素数判定”循环作为示例出现在6.4节中：
 *
 * for (d = 2; d < n; d++)
 * 	if (n % d == 0) break;
 *
 * 这个循环不是很有效。用n除以2~n-1所有数的方法来判断它是否为素数是没有必要的。事实上，只
 * 需要检查不大于n的平方根的除数。利用这一点来修改循环。提示：不要试图计算出n的平方根，而
 * 是用d*d和n进行比较。
 */

#include <stdio.h>

int main()
{
	int n;
	int d;

	printf("Enter a number: ");
	scanf("%d", &n);

	for (d = 2; d * d < n; ++d)
		if (n % d == 0) goto done;

done:
	if (d * d < n)
		printf("%d is divisible by %d\n", n, d);
	else
		printf("%d is prime\n", n);

	return 0;
}
