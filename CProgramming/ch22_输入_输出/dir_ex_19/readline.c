#include <ctype.h>
#include <stdio.h>
#include "readline.h"

int read_line(char str[], int n)
{
    int ch, i = 0;

    while (isspace(ch = getchar()));

    while (1) {            
        if (ch == '\n' || ch == EOF) break;

        if (i < n) {
            str[i++] = ch;
        }
        ch = getchar();
    }

    str[i] = '\0';

    return i;
}