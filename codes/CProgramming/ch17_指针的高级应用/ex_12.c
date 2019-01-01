/*
    请说明下列程序的输出结果，并且说明理由。

    #include <stdio.h>

    int f1(int (*f)(int));
    int f2(int i);

    int main()
    {
        printf("Answer: %d\n", f1(f2));
        return 0;
    }

    int f1(int (*f)(int))
    {
        int n = 0;
        while ((*f)(n)) n++;
        return n;
    }

    int f2(int i)
    {
        return i * i + i - 12;
    }
*/

/*
    Answer: 3
    当n为3时，f1 中的 while 循环条件检查失败，返回
*/

#include <stdio.h>

int f1(int (*f)(int));
int f2(int i);

int main()
{
    printf("Answer: %d\n", f1(f2));
    return 0;
}

int f1(int (*f)(int))
{
    int n = 0;
    while ((*f)(n)) n++;
    return n;
}

int f2(int i)
{
    return i * i + i - 12;
}