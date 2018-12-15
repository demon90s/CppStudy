/* Tests string conversion functions */

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

#define CHK_VALID printf("\t\t%s\t%s\n",\
        errno != ERANGE ? "Yes" : "No",\
        *ptr == '\0' ? "Yes" : "No")

int main(int argc, char const *argv[])
{
    char *ptr;

    if (argc != 2) {
        printf("usage: tstrconv string\n");
        return 1;
    }

    printf("Function\tReturn Value\n");
    printf("--------\t------------\n");
    printf("atof\t\t%g\n", atof(argv[1]));
    printf("atoi\t\t%d\n", atoi(argv[1]));
    printf("atol\t\t%ld\n", atol(argv[1]));
    
    printf("\nFunction\tReturn Value\tValid?\tStringConsumed?\n");
    printf("--------\t------------\t------\t---------------\n");

    errno = 0;
    printf("strtod\t\t%g", strtod(argv[1], &ptr));
    CHK_VALID;

    errno = 0;
    printf("strtol\t\t%ld", strtol(argv[1], &ptr, 10));
    CHK_VALID;

    errno = 0;
    printf("strtoul\t\t%lu", strtoul(argv[1], &ptr, 10));
    CHK_VALID;

    return 0;
}
