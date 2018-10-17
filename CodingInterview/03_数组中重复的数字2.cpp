/*
 * 面试题3：数组中重复的数字
 *
 * 题目二：在一个长度为n+1的数组里的所有数字都在1~n的范围内，所以数组中至少有一个数字是重复的。
 * 请找出数组中任意一个重复的数字，但是不能修改输入数组。例如，如果输出长度为8的数组
 * {2,3,5,4,3,2,6,7}，那么对应输出是重复的数字2或者3。
 */

/*
 * 思路：采用二分思想，如数组长度为8，则取4，遍历数组，得到1~4之间数的个数和
 * 5~7之间的数的个数，如果这个个数多于4或者3，那么这个区间就有重复的值。
 */

#include <stdio.h>

#define LEN 8

int countRange(const int* numbers, int length, int start, int end)
{
	if (numbers == nullptr)
		return 0;

	int count = 0;
	for (int i = 0; i < length; i++)
		if (numbers[i] >= start && numbers[i] <= end)
			++count;
	return count;
}

int getDup(const int *numbers, int length)
{
	if (numbers == nullptr || length <= 0)
		return -1;

	int start = 1;
	int end = length - 1;
	while (end >= start)
	{
		int middle = ((end - start) >> 1) + start;
		int count = countRange(numbers, length, start, middle);
		if (end == start)
		{
			if (count > 1)
				return start;
			else
				break;
		}

		if (count > (middle - start + 1))
			end = middle;
		else
			start = middle + 1;
	}

	return -1;
}

void Test1()
{
	int a[LEN] = {2,3,5,4,3,2,6,7};
	printf("dup: %d\n", getDup(a, LEN));
}

int main()
{
	Test1();

	return 0;
}
