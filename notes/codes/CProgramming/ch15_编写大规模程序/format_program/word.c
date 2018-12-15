#include <stdio.h>
#include <string.h>
#include "word.h"

int read_char(void)
{
	int ch = getchar();

	if (ch == '\n' || ch == '\t')
		return ' ';
	return ch;
}

void read_word(char *word, int len)
{
	int ch, pos = 0;
	while ((ch = read_char()) == ' ');

	while (ch != ' ' && ch != EOF) {
		if (pos < len)
			word[pos++] = ch;
		ch = read_char();
	}

	word[pos] = '\0';
}

void read_word_ex09(char *word, int len)
{
	int ch, pos = 0;
	int word_len;
	while ((ch = read_char()) == ' ');

	while (ch != ' ' && ch != EOF) {
		if (pos < len)
			word[pos++] = ch;
		ch = read_char();
	}
	
	word[pos] = '\0';

	word_len = strlen(word);
	if (word_len > MAX_WORD_LEN)
			word[MAX_WORD_LEN] = '*';
}