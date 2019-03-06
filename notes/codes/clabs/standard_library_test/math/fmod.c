/*
    fmod(arg1, arg2)
    返回 arg1 除以 arg2 所得的余数
*/

#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    printf("fmod(5.5, 2.2) = %f\n", fmod(5.5, 2.2));        // 1.100000
    printf("fmod(5, 2) = %f\n", fmod(5, 2));                // 1.000000
    
    return 0;
}
