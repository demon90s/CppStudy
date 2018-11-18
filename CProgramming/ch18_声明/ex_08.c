/*
    请为下列变量和函数编写声明：
    (a) p是指向函数的指针，并且此函数带有字符型指针作为实际参数，函数返回的也是字符型指针。
    (b) f是带有两个实际参数的函数：一个参数是指向结构的指针p，且此结构标记为t；另一个参数是长
        整数n。f返回指向函数的指针，且指向的函数没有实际参数也无返回值。
    (c) a是含有4个元素的数组，且每个元素都是指向函数的指针，而这些函数都是没有实际参数且无返回
        值的。a的元素初始指向的函数名分别是 insert, search, update 和 print 。
    (d) b是含有10个元素的数组，且每个元素都是指向函数的指针，而这些函数都有两个int型实际参数
        且返回标记为t的结构。
*/

/* for a */
char* (*p)(char*);

/* for b */
typedef struct t_ { int v; } t;
typedef void (*bret_func)();
bret_func f(t *p, long n);

/* for c */
void insert() {}
void search() {}
void update() {}
void print() {}
typedef void (*a_func)();
a_func a[4] = {insert, search, update, print};

/* for d */
typedef t* (*d_func)(int, int);
d_func d[10];

int main(int argc, char const *argv[])
{
    
    return 0;
}
