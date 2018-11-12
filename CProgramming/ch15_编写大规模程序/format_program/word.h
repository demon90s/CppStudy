#ifndef WORD_H
#define WORD_H

#define MAX_WORD_LEN 20

/*
 * read_word: Reads the next word from the input and
 * 			  stores it in word. Makes word empty if no
 * 			  word could be read because of end-of-file.
 * 			  Truncates the word if its length exceeds len.
 * 
 */
void read_word(char *word, int len);

/*
 * for ex_09
 */
void read_word_ex09(char *word, int len);

#endif
