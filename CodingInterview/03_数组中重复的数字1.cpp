/*
 * 面试题3：数组中重复的数字
 *
 * 题目一：找出数组中重复的数字
 *
 * 在一个长度为n的数组里的所有数字都在0~n-1的。数组中某些数字是重复的，
 * 但不知道有几个数字重复了，也不知道每个数字c重复了几次。请找出数组中
 * 任意一个重复的数字。例如，如果输入长度为7的数组{2,3,1,0,2,5,3}，那么
 * 对应的输出是重复的数字2或者3。
 */

/*
 * 解决思路，由于数字范围是0~n-1，因此可以把数字i放到下标i上面，如果此时
 * 下标i的元素和数字i相等，那么就发生了重复。
 *
 * 时间复杂度为O(n)
 * 空间复杂度为O(1)
 *
 * 测试用例：
 *
 * 1. 数组中包含一个或多个重复数字
 * 2. 数组中没有重复数字
 *
 */

#include <stdio.h>
#include <utility>

#define LEN 7

bool IsDup(int a[], int len, int *dup_number)
{
	for (int i = 0; i < len; ++i) {
		while (i != a[i]) {
			if (a[i] == a[a[i]]) {
				*dup_number = a[i];
				return true;
			}

			using namespace std;
			swap(a[i], a[a[i]]);
		}
	}

	return false;
}

void Test1()
{
	int a[LEN] = {2, 3, 1, 0, 2, 5, 3};
	int dup_number;

	if (IsDup(a, LEN, &dup_number)) {
		printf("dup_number: %d\n", dup_number);
	}
	else {
		printf("no dup number\n");
	}
}

void Test2()
{
	int a[LEN] = {0, 6, 3, 4, 5, 1, 2};
	int dup_number;

	if (IsDup(a, LEN, &dup_number)) {
		printf("dup_number: %d\n", dup_number);
	}
	else {
		printf("no dup number\n");
	}
}

int main()
{
	//Test1();
	Test2();

	return 0;
}
