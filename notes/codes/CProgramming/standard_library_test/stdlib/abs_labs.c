/*
    #include <stdlib.h>
    int abs(int j);
    long int labs(long int j);

    返回 j 的绝对值。
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    long int li;

    printf("Enter a number: ");
    scanf("%ld", &li);

    printf("abs(%ld) = %ld\n", li, abs(li));
    
    return 0;
}
