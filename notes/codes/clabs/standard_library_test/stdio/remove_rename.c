/*
    remove(file)
    将 file 删除

    rename(old, new)
    将 old 文件改名为 new

    若成功，函数返回0，否则返回非零值。
*/

#include <stdio.h>

void test_remove()
{
    if (0 == remove("example.dat")) {
        printf("Remove succ\n");
    }
    else {
        printf("Remove failed\n");
    }
}

void test_rename()
{
    if (0 == rename("example.dat", "example.txt")) {
        printf("Rename succ\n");
    }
    else {
        printf("Rename failed\n");
    }
}

int main(int argc, char const *argv[])
{
    //test_remove();
    test_rename();

    return 0;
}
