/*
 * 指出下面的程序预处理后的形式。其中有几行可能会导致编译错误，请找出这些错误。
 *
 * #define N = 10
 * #define INC(x) x+1
 * #define SUB(x,y) x - y
 * #define SQR(x) ((x)*(x))
 * #define CUBE(x) (SQR(x)*(x))
 * #define M1(x,y) x##y
 * #define M2(x,y) #x #y
 *
 * main()
 * {
 * 	int a[N], i, j, k, m;
 * 	#ifdef N
 * 	i = j;
 * 	#else
 * 	j = i;
 * 	#endif
 * 	i = 10 * INC(j);
 * 	i = SUB(j, k);
 * 	i = SQR(SQR(j++));
 * 	i = CUBE(j);
 * 	i = M1(j, k);
 * 	puts(M2(i, j));
 * 	#undef SQR
 * 	i = SQR(j);
 * 	#define SQR
 * 	i = SQR(j);
 * 	return 0;
 * }
 */

#include <stdio.h>

#define N = 10
#define INC(x) x+1
#define SUB(x,y) x - y
#define SQR(x) ((x)*(x))
#define CUBE(x) (SQR(x)*(x))
#define M1(x,y) x##y
#define M2(x,y) #x #y

int main()
{
	int a[=10], i, j, k, m; /* 编译错误 */
	i = j;
	i = 10 * j+1;
	i = j - k;
	i = ((((j++)*(j++)))*(((j++)*(j++))));
	i = (((j)*(j))*(j));
	i = jk;	/* 编译错误 */
	puts("i" "j");
	i = SQR(j); /* 编译错误 */
	i =; /* 编译错误 */

	return 0;
}
