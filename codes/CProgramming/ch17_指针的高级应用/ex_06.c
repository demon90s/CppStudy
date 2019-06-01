/*
    假设f和p的声明如下所示：

    struct {
        union {
            char a, b;
            int c;
        }d;
        int e[5];
    }f, *p = &f;

    那么下列哪些语句是合法的？
    (a) p->b = ' ';
    (b) p->e[3] = 10;
    (c) (*p).d.a = '*';
    (d) p->d->c = 20;
*/

/*
    合法的有：b c
*/

struct {
    union {
        char a, b;
        int c;
    }d;
    int e[5];
}f, *p = &f;

int main(int argc, char const *argv[])
{
    /* a */
    /* p->b = ' '; */

    /* b */
    p->e[3] = 10;

    /* c */
    (*p).d.a = '*';

    /* d */
    /* p->d->c = 20; */
    
    return 0;
}
