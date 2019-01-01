/*
    fread(ptr, size, nmemb, stream)
    从 stream 中读取数据块，此数据块由 nmemb 个每个大小为 size 的元素组成，块地址是 ptr
    返回实际读入元素的数量，应该等于 nmemb，除非达到了文件尾或者出现了错误。
    fread 不区别文件尾和错误，而调用者必须用 feof 和 ferror 鉴别出现者为何。

    fwrite(ptr, size, nmemb, stream)
    向 stream 写入数据块
    返回实际写入的元素的数量，如果出现错误，那么此数会小于 nmemb
*/

#include <stdio.h>
#include <string.h>

struct {
    int a;
    char b[32];
    float c;
} s;

void test_fwrite()
{
    int nwrite;
    FILE *fp = fopen("example.dat", "w");
    if (!fp) {
        perror("fopen");
        return;
    }

    s.a = 100;
    strcpy(s.b, "Hello");
    s.c = 3.14;
    nwrite = fwrite(&s, sizeof(s), 1, fp);
    printf("write %d block\n", nwrite);

    fclose(fp);
}

void test_fread()
{
    int nread;
    FILE *fp = fopen("example.dat", "r");
    if (!fp) {
        perror("fopen");
        return;
    }

    nread = fread(&s, sizeof(s), 1, fp);
    printf("read %d block\n", nread);
    if (nread == 1) {
        printf("s: %d %s %f\n", s.a, s.b, s.c);
    }

    fclose(fp);
}

// 测试一下当读取到文件尾，函数的返回结果
// 结果：会返回一个值，表示读取到的元素的个数，并且会设置文件尾标记
void test_fread2()
{
    int nread;
    char buffer[1024] = {0};
    nread = fread(buffer, sizeof(char), 100, stdin);
    if (nread > 0) {
        printf("read %d characters: %s\n", nread, buffer);
    }

    printf("fread returns: %d, is feof set(%d), is ferror set(%d)\n", nread, feof(stdin) != 0, ferror(stdin) != 0);
}

int main(int argc, char const *argv[])
{
    //test_fwrite();
    //test_fread();

    test_fread2();
    
    return 0;
}
