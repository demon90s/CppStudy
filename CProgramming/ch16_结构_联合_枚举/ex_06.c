/*
    编写程序用来要求用户录入国家（地区）名称，然后可以在数组 country_codes 中查找到它。如果
    找到对应的国家（地区）名称，程序需要显示相应的国家（地区）电话代码。如果没有找到，程序应该
    显示出错消息。
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NAME_LEN 25
#define CODE_LEN 30
#define COUNT_COUNT 100

int country_count = 0;

struct counry {
    char name[NAME_LEN + 1];
    char phone_code[CODE_LEN + 1];
} country_codes[COUNT_COUNT];

int read_line(char str[], int n)
{
    int ch, i = 0;

    while (isspace(ch = getchar()));

    while (1) {            
        if (ch == '\n' || ch == EOF) break;

        if (i < n) {
            str[i++] = ch;
        }
        ch = getchar();
    }

    str[i] = '\0';

    return i;
}

/* 根据姓名查询，返回下标，-1代表没有找到 */
int find(char *name)
{
    int i;
    for (i = 0; i < country_count; i++) {
        if (strcmp(name, country_codes[i].name) == 0) {
            return i;
        }
    }
    return -1;
}

void insert()
{
    char name[NAME_LEN + 1];
    char phone_code[CODE_LEN + 1];

    if (country_count >= COUNT_COUNT) {
        printf("database full!\n");
        return;
    }

    printf("Enter country name: ");
    read_line(name, NAME_LEN);
    if (find(name) >= 0) {
        printf("country already exist!\n");
        return;
    }

    printf("Enter phone code: ");
    read_line(phone_code, CODE_LEN);

    strcpy(country_codes[country_count].name, name);
    strcpy(country_codes[country_count].phone_code, phone_code);

    country_count++;
}

void search()
{
    char name[NAME_LEN + 1];
    printf("Enter country name you want to search: ");
    read_line(name, NAME_LEN);

    int index = find(name);
    if (index < 0) {
        printf("no such country\n");
        return;
    }

    printf("country's phone code is: %s\n", country_codes[index].phone_code);
}

int main(int argc, char const *argv[])
{
    char op;
    for (;;) {
        printf("Enter options(i for insert, s for search, q for quit): ");
        scanf(" %c", &op);
        while (getchar() != '\n');

        switch (op) {
            case 'i': insert(); break;
            case 's': search(); break;
            case 'q': printf("bye\n"); return 0;
            default: printf("error input\n"); break;
        }
    }
    
    return 0;
}
