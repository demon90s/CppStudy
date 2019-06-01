/*
    Tests the case-mapping functions
*/

#include <stdio.h>
#include <ctype.h>

int main(int argc, char const *argv[])
{
    char *p;
    for (p = "aA0!"; *p != '\0'; p++) {
        printf("tolower('%c') is '%c'; ", *p, tolower(*p));
        printf("toupper('%c') is '%c'\n", *p, toupper(*p));
    }
    
    return 0;
}
