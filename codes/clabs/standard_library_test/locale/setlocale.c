/*
    #include <locale.h>
    char *setlocale(int category, const char *locale);
    用来设置或者查询程序当前的区域选项。进而影响某些程序的行为。
    
    如果 locale 是 NULL, 则代表查询.

    如果 locale 不是 NULL ，就会设置 category 选项，其取值有：

    - LC_ALL - 代表所有部分
    
    可参考: https://zh.cppreference.com/w/c/locale/setlocale

    locale 对于用户偏好的本地环境为 "" , 对于最小本地环境为 "C" 。其余的根据C实现定义(使用命令行 locale -a 来显示出所有的可用值)
    一个本地环境的例子是 en_US.UTF-8 ， en 代表了语言， US 代表了国家， UTF-8 则代表了字符集。

    返回应用更改后的C本地环境，若存在。失败时为空指针。
*/

#include <locale.h>
#include <stdio.h>
#include <time.h>
#include <wchar.h>

void test1()
{
    printf("default region: %s\n", setlocale(LC_ALL, NULL));

    setlocale(LC_ALL, "C");
    printf("'C' region: %s\n", setlocale(LC_ALL, NULL));

    setlocale(LC_ALL, "");
    printf("local region: %s\n", setlocale(LC_ALL, NULL));
}

void test2()
{
    // C本地环境将为启用 UTF-8 的英文
    // 小数点将为德文
    // 日期和时间格式将为日文
    setlocale(LC_ALL, "en_US.UTF-8");
    setlocale(LC_NUMERIC, "de_DE");
    setlocale(LC_TIME, "ja_JP");

    wchar_t str[100];
    time_t t = time(NULL);
    wcsftime(str, 100, L"%A %c", localtime(&t));
    wprintf(L"Number: %.2f\nDate: %Ls\n", 3.14, str);
}

int main()
{
    test1();
    //test2();

    return 0;
}