/*
    在18.4节看到了下列非发的声明：

    int f(int)[];           // Functions can't return arrays
    int g(int)(int);        // Functions can't return functions
    int a[10](int);         // Array elements can't be functions

    然而，可以通过使用指针获得相似的效果：函数可以返回指向数组第一个元素的指针，也可以返回
    指向函数的指针，而且数组的元素可以是指向函数的指针。请根据这些描述重新修订上述每个声明。 
*/

int (*f(int i))[]
{
    static int arr[3];
    return &arr;
}

int test_g(int i) { return 0; }
int (*g(int i))(int)
{
    return test_g;
}

int (*a[10])(int);

int main(int argc, char const *argv[])
{
    
    return 0;
}
