/*
    freopen
    freopen(filename, mode, stream);

    首先，试图关闭与 stream 关联的文件，忽略任何错误。然后，若 filename 非空，则试图用 mode 打开 filename 所指定
    的文件，如同用 fopen ，然后将该文件与 stream 所指向的文件流关联。若 filename 为空，则函数试图重新打开已与
    stream 关联的文件（此情况下是否允许模式改变是实现定义的）。

    成功时返回 stream 的副本，失败返回 NULL 。

    PS：关联的意思是说，向 stream 进行操作，等同于操作该文件。
*/

#include <stdio.h>

#define FILE_NAME "example.dat"

int main(int argc, char const *argv[])
{
    puts("stdout is printed to console");

    if (freopen(FILE_NAME, "w", stdout) == NULL) {
        perror("freopen() failed");
        return 1;
    }

    puts("stdout is redirected to file");   // 写入 FILE_NAME

    return 0;
}
