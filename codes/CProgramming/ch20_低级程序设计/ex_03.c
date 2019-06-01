/*
    请解释下面的宏对它的实际参数起什么作用。假设参数具有相同类型。

    #define M(x,y) ((x)^=(y), (y)^=(x), (x)^=(y))
*/

/*
    根据测试，作用是交换 x y
*/

#include <stdio.h>

#define M(x,y) ((x)^=(y), (y)^=(x), (x)^=(y))

int main(int argc, char const *argv[])
{
    int x = 500, y = 28;
    M(x, y);

    printf("%d %d\n", x, y);
    
    return 0;
}
