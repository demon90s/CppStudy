/*
    int system(const char* cmd);

    启动并执行一个程序 cmd。

    返回的值由实现定义，通常返回 cmd 的终止状态码。
*/

#include <stdlib.h>

int main(int argc, char const *argv[])
{
    system("echo Hello world");
    
    return 0;
}
