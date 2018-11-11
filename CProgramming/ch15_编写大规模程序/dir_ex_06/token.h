#ifndef TOKEN_H
#define TOKEN_H

#define TYPE_NUMBER 0
#define TYPE_OP 1
#define TYPE_END 2
#define TYPE_CONTINUE 3

typedef int TokenType;

TokenType next_token();
int get_last_number();
char get_last_op();

#endif // TOKEN_H