/*
    tmpfile
    tmpfile(void)
    创建并打开一个临时文件，该文件的打开模式是 wb+ ，该文件保证在文件系统中唯一。
    此函数创建的临时文件在程序正常退出时被关闭并删除，它在程序异常终止时是否被删除是实现定义的。

    返回文件流指针，失败返回 NULL 。

    tmpnam
    tmpnam(char* filename)
    创建独有的合法文件名，长度不长于 L_tmpnam ，并将它存储于 filename 所指向的字符串。

    若 filename 不为空，则返回 filename 。若生成失败返回 NULL 。
*/

#include <stdio.h>

void test_tmpfile()
{
    FILE *tmp = tmpfile();
    fputs("Hello, World", tmp);

    rewind(tmp);
    char buf[6];
    fgets(buf, sizeof(buf), tmp);
    printf("got back from the file: '%s'\n", buf);

    getchar();
}

void test_tmpnam()
{
    char name[L_tmpnam];
    tmpnam(name);
    printf("temporary file name: %s\n", name);
}

int main(int argc, char const *argv[])
{
    //test_tmpfile();
    test_tmpnam();
    
    return 0;
}
