/*
 * 利用 switch 语句编写一个程序，把数字显示的成绩转化为字母显示的等级：
 *
 * Enter numerical grade: 84
 * Letter grade: B
 *
 * 使用下面这套等级评定规则：A=90~100，B=80~89，C=70~79，D=60~69，F=0~59。如果成绩
 * 高于100或低于0则显示出错信息。提示：把成绩拆分成2个数字，然后使用 switch 判定十位上的数字。
 *
 */

#include <stdio.h>

int main()
{
	int number_grade, g;
	char letter_grade;

	printf("Enter numerical grade: ");
	scanf("%d", &number_grade);

	if (number_grade < 0 || number_grade > 100) {
		printf("Invalid grade\n");
		return 1;
	}

	g = number_grade / 10;

	switch (g) {
		case 10:
		case 9:
			letter_grade = 'A'; break;

		case 8:
			letter_grade = 'B'; break;

		case 7:
			letter_grade = 'C'; break;

		case 6:
			letter_grade = 'D'; break;

		default:
			letter_grade = 'F'; break;
	}

	printf("Letter grade: %c\n", letter_grade);

	return 0;
}
