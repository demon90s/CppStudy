/*
    下列哪些声明是合法的？（假设 PI 是表示3.14159的宏。）
    (a) char c = 65;
    (b) static int i = 5, j = i * i;
    (c) float f = 2 * PI;
    (d) double angles[] = {0, PI / 2, PI, 3 * PI / 2};
*/

/*
    合法的有：a c d
*/

#define PI 3.14159

char c = 65;
/*static int i = 5, j = i * i;*/
float f = 2 * PI;
double angles[] = {0, PI / 2, PI, 3 * PI / 2};

int main(int argc, char const *argv[])
{
    return 0;
}
