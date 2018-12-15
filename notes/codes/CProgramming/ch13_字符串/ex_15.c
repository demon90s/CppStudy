/*
 * 按如下方式改进 remind.c 程序：
 *
 * (a) 如果对应的天为负数或大于31，那么先是显示出错误信息，然后忽略提示。提示：使用 continue 语句
 *
 * (b) 允许用户输入天、24小时格式的时间（可能空白）和提示。显示的提示列表必须先按天排序存储，然后
 * 再根据时间排序存储。（原始的 remind.c 程序允许用户输入时间，但是它把时间作为提示的一部分来处理）
 *
 * (c) 程序需显示一年的提示列表。要求用户按照月/日的格式输入日期。
 */

/*
 * remind.c
 *
 * Prints a one-month reminder list
 */

/*
 * Enter day and reminder: 09/27 10:56 Susan birthday
 */

#include <stdio.h>
#include <string.h>

#define MAX_REMIND 50
#define MSG_LEN 60

int read_line(char str[], int n);

int main()
{
	char reminders[MAX_REMIND][MSG_LEN + 3];
	char day_str[12], msg_str[MSG_LEN + 1];
	int day, month, hour, min, i, j, num_remind = 0;

	for (;;) {
		if (num_remind == MAX_REMIND) {
			printf("-- No space left --\n");
			break;
		}

		printf("Enter day and reminder: ");
		day = 0;
		scanf("%2d/%2d", &month, &day);
		if (day == 0) break;

		if (day < 0 || day > 31) {
			printf("Bad day, ignored\n");
			while (getchar() != '\n');
			continue;
		}

		scanf("%2d:%2d", &hour, &min);

		sprintf(day_str, "%.2d/%.2d %.2d:%.2d", month, day, hour, min);
		read_line(msg_str, MSG_LEN);

		for (i = 0; i < num_remind; i++)
			if (strcmp(day_str, reminders[i]) < 0)
				break;
		for (j = num_remind; j > i; j--)
			strcpy(reminders[j], reminders[j-1]);

		strcpy(reminders[i], day_str);
		strcat(reminders[i], msg_str);

		num_remind++;
	}

	printf("\nDay Reminder\n");
	for (i = 0; i < num_remind; i++)
		printf(" %s\n", reminders[i]);

	return 0;
}

int read_line(char str[], int n)
{
	char ch;
	int i = 0;

	while ((ch = getchar()) != '\n') {
		if (i < n)
			str[i++] = ch;
	}
	str[i] = '\0';
	return i;
}
