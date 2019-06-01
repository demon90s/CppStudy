/*
 * 编写下列函数：
 *
 * void split_time(long int total_sec,
 * 				   int *hr, int *min, int *sec);
 *
 * total_sec 是从午夜计算的秒数表示的时间。hr、min、和sec都是指向变量的指针，这些变量在
 * 函数中分别存储着按小时算（0~23）、按分钟算（0~59）和按秒算（0~59）的等价时间。
 */

#include <stdio.h>

void split_time(long int total_sec, int *hr, int *min, int *sec);

int main()
{
	long int total_sec;
	int hr, min, sec;

	printf("Enter sec: ");
	scanf("%ld", &total_sec);

	split_time(total_sec, &hr, &min, &sec);

	printf("%2.2d:%2.2d:%2.2d\n", hr, min, sec);

	return 0;
}

void split_time(long int total_sec, int *hr, int *min, int *sec)
{
	*hr = total_sec / 3600;
	*min = total_sec / 60 % 60;
	*sec = total_sec % 60;
}
