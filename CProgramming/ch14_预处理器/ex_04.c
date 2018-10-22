/*
 * 针对下面每一个宏，举例说明宏的问题，并提出修改方法。
 *
 * (a) #define AVG(x,y) (x+y)/2
 * (b) #define AREA(x,y) (x) * (y)
 */

#include <stdio.h>

#define AVG(x,y) (x+y)/2
#define AREA(x,y) (x) * (y)

#define AVG_FIX(x, y) (((x) + (y))/2)
#define AREA_FIX(x, y) ((x) * (y))

int main()
{
	int res;
	double d_res;

	res = AVG(4 || 1, 10); // 期望为1和10的平均值，但实际上计算了1/2
	printf("res: %d\n", res);

	res = AVG_FIX(4 || 1, 10);
	printf("res: %d\n", res);

	d_res = (int)AREA(3, 1.5);	// 期望为4，但实际上还是4.5
	printf("d_res: %g\n", d_res);

	d_res = (int)AREA_FIX(3, 1.5);
	printf("d_res: %g\n", d_res);

	return 0;
}
