#include "token.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

static int last_number;
static char last_op;

int get_last_number()
{
    return last_number;
}

char get_last_op()
{
    return last_op;
}

TokenType next_token()
{
    char c;
    int number_str_index = 0;
    char number_str[100];
    while (1)
    {
        c = getchar();
        if (c == ' ' || c == '\n') break;
        if (c == '#' || c == EOF) break;

        if (c == '+' || c== '-' || c == '*' || c == '\\')
        {
            last_op = c;
            return TYPE_OP;
        }

        if (isdigit(c))
        {
            number_str[number_str_index++] = c;
        }
    }

    if (number_str_index > 0)
    {
        number_str[number_str_index] = '\0';
        last_number = atoi(number_str);
        return TYPE_NUMBER;
    }

    if (c == '#' || c == EOF)
    {
        return TYPE_END;
    }
    else
    {
        return TYPE_CONTINUE;
    }
}