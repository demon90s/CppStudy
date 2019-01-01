/*
    假设下列声明有效：

    struct point { int x, y; };
    struct rectangle { struct point upper_left, lower_right; };
    struct rectangle *p;

    假设希望p指向结构 rectangle , 其中此结构左上角位于(0,1)的位置上，而右下角位于(1,0)的位置
    上。请编写一系列语句用来分配这样一个结构，并且像说明的那样进行初始化。
*/

#include <stdlib.h>
#include <stdio.h>

struct point { int x, y; };
struct rectangle { struct point upper_left, lower_right; };
struct rectangle *p;

void print_rectangle(struct rectangle *p)
{
    printf("{(%d,%d), (%d,%d)}",
        p->upper_left.x,
        p->upper_left.y,
        p->lower_right.x,
        p->lower_right.y);
}

int main(int argc, char const *argv[])
{
    p = malloc(sizeof(struct rectangle));
    if (p == NULL) {
        printf("No space left!\n");
        return 1;
    }
    p->upper_left.x = 0;
    p->upper_left.y = 1;
    p->lower_right.x = 1;
    p->lower_right.y = 0;

    printf("p: ");
    print_rectangle(p);
    printf("\n");

    free(p);
    
    return 0;
}
