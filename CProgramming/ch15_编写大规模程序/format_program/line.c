#include <stdio.h>
#include <string.h>
#include "line.h"

#define MAX_LINE_LEN 60

char line[MAX_LINE_LEN + 1];
int line_len = 0;
int num_words = 0;

void clear_line(void)
{
	line[0] = '\0';
	line_len = 0;
	num_words = 0;
}

void add_word(const char *word)
{
	if (num_words > 0) {
		line[line_len] = ' ';
		line[line_len+1] = '\0';
		line_len++;
	}

	strcat(line, word);
	line_len += strlen(word);
	num_words++;
}

int space_remaining(void)
{
	return MAX_LINE_LEN - line_len;
}

void write_line(void)
{
	int extra_spaces, spaces_to_insert, i, j;

	extra_spaces = MAX_LINE_LEN - line_len;
	for (i = 0; i < line_len; i++) {
		if (line[i] != ' ')
			putchar(line[i]);
		else {
			spaces_to_insert = extra_spaces / (num_words - 1);
			for (j = 1; j <= spaces_to_insert + 1; j++)
				putchar(' ');
			extra_spaces -= spaces_to_insert;
			num_words--;
		}
	}

	putchar('\n');
}

// 练习5：在靠近末尾处的的单词之间放置较大的空隙 ，在行开始处的单词之间放置一般空隙
void write_line_ex5(void)
{
	int extra_spaces, i, j;
	extra_spaces = MAX_LINE_LEN - line_len;
	for (i = 0; i < line_len; i++) {
		if (line[i] != ' ')
			putchar(line[i]);
		else {
			if (num_words != 2) {
				putchar(' ');
			}
			else {
				for (j = 1; j < extra_spaces + 1; j++)
					putchar(' ');
			}
			num_words--;
		}
	}

	putchar('\n');
}

void flush_line(void)
{
	if (line_len > 0)
		puts(line);
}
