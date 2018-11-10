#ifndef LINE_H
#define LINE_H

/*
 * clear_line: Clears the current line.
 */
void clear_line(void);

/*
 * add_word: Adds word to the end of the current line.
 *           If this is not the first word on the line,
 *           puts one space before word.
 */
void add_word(const char *word);

/*
 * space_remaining: Returns the number of characters left
 *                  in the current line.
 */
int space_remaining(void);

/*
 * write_line: Writes the current line with justification
 */
void write_line(void);

/*
 * flush_line: Writes the current line without justification.
 *             If the line is empty, does nothing.
 */
void flush_line(void);

/*
 * 练习5改写的 write_line ,要求靠近末尾处的的单词之间放置较大的空隙 ，在行开始处的单词之间放置一般空隙
 */
void write_line_ex5(void);

#endif
