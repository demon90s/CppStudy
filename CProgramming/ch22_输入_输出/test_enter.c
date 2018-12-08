/*
    测试标准输入中的回车键

    默认情况下，在敲击回车后，才会把输入流送给程序处理
*/

#include <stdio.h>

int main(int argc, char* argv[])
{
    // getchar，会读取换行符
    {
        printf("Test getchar()\n");
        int ch;
        ch = getchar();
        printf("read: 0x%02x\t%d\n", ch, ch);
    }
    
    // fgets，只有数组足够，才存放换行符
    {
        printf("\nTest fgets()\n");
        char buffer[4];
        fgets(buffer, 4, stdin);
        char* p = buffer;
        while (*p) {
            printf("read: 0x%02x\t%d\n", *p, *p);
            p++;
        }
    }

    // scanf，读取字符串时，遇到空白即停止扫描，因此不会读取换行符（以及其他空白字符）
    {
        printf("\nTest scanf()\n");
        char buffer[4];
        scanf("%s", buffer);
        char *p = buffer;
        while (*p) {
            printf("read: 0x%02x\t%d\n", *p, *p);
            p++;
        }
    }
    
    return 0;
}