/*
    测试预处理器指令

    加入编译选项 -DXXX 表示定义一个预定义宏
*/

#include <stdio.h>
#include <assert.h>

// #if #elif #else #endif
void func1()
{
    #if (DEBUG)
        printf("DEBUG defined\n");
    #elif (RELEASE)
        printf("RELEASE defined\n");
    #else
        printf("Neither DEBUG nor RELEASE defined\n");
    #endif
}

// ! && ||
#define LOG_WARNING 1
#define LOG_ERROR 0
void func2()
{
    #if (!NDEBUG)
        printf("assert are valid\n");
        //assert(0);
    #endif

    #if (LOG_WARNING && LOG_ERROR)
        printf("both error log and warning log are valid\n");
    #endif

    #if (LOG_WARNING || LOG_ERROR)
        printf("one of log level are valid\n");
    #endif
}

// #ifdef #ifndef
// 0和1不影响是否 defined
#define PLAT_WIN 1
#define PLAT_LINUX 0
void func3()
{
    #ifdef PLAT_WIN
        printf("PLAT_WIN defined\n");
    #endif

    #ifdef PLAT_LINUX
        printf("PLAT_LINUX defined\n");
    #endif

    #ifdef PLAT_MAC
        printf("PLAT_MAC defined\n");
    #endif

    #ifndef PLAT_MAC
        printf("PLAT_MAC NOT defined\n");
    #endif
}

int main()
{
    //func1();
    //func2();
    func3();
    return 0;
}