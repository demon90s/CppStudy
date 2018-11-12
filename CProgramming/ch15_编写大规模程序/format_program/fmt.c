/* Formats a file of text */

#include <string.h>
#include "line.h"
#include "word.h"

int main()
{
	char word[MAX_WORD_LEN + 2];
	int word_len;

	clear_line();

	/*
	for (;;) {
		read_word(word, MAX_WORD_LEN + 1);
		word_len = strlen(word);
		if (word_len == 0) {
			flush_line();
			return 0;
		}

		if (word_len > MAX_WORD_LEN)
			word[MAX_WORD_LEN] = '*';

		if (word_len + 1 > space_remaining()) {
			//write_line();
			write_line_ex5();
			clear_line();
		}
		add_word(word);
	}
	*/

	/*
		for ex_09
	*/
	for (;;) {
		read_word_ex09(word, MAX_WORD_LEN + 1);
		word_len = strlen(word);
		if (word_len == 0) {
			flush_line();
			return 0;
		}

		if (word_len + 1 > space_remaining()) {
			//write_line();
			write_line_ex5();
			clear_line();
		}
		add_word(word);
	}

	return 0;
}
