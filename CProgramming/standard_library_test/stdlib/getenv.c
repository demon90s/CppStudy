/*
    #include <stdlib.h>
    char *getenv(const char* name);

    访问外部环境中的环境变量 name 的值。

    失败返回 NULL 。
*/

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    char *p = getenv("PATH");
    if (p) {
        printf("PATH=%s\n", p);
    }
    
    return 0;
}
