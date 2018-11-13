#include <ctype.h>
#include <stdio.h>
#include "readline.h"

int read_line(char str[], int n)
{
    int ch, i = 0;

    while (isspace(ch == getchar()));

    while (1) {            
        ch = getchar();
        if (ch == '\n' || ch == EOF) break;

        if (i < n) {
            str[i++] = ch;
        }
    }

    str[i] = '\0';

    return i;
}