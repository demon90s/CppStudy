/*
    请编写一个函数，要求在给定字符串作为实际参数时，此函数搜索下列所示的结构数组寻找匹配的
    命令名，然后调用和匹配名称相关的函数：

    struct {
        char *cmd_name;
        void (*cmd_pointer)(void);
    } file_cmd[] = {
        {"new", new_cmd},
        {"open", open_cmd}
    };
*/

#include <string.h>
#include <stdio.h>

#define ARR_LEN(arr) ((int)sizeof(arr)/sizeof((arr)[0]))

void new_cmd(void)
{
    printf("new_cmd called\n");
}

void open_cmd(void)
{
    printf("open_cmd called\n");
}

struct {
    char *cmd_name;
    void (*cmd_pointer)(void);
} file_cmd[] = {
    {"new", new_cmd},
    {"open", open_cmd}
};

void Invoke(const char *func_name)
{
    int i;
    for (i = 0; i < ARR_LEN(file_cmd); i++) {
        if (strcmp(file_cmd[i].cmd_name, func_name) == 0) {
            (*file_cmd[i].cmd_pointer)();
            return;
        }
    }

    printf("No such function\n");
}

int main(int argc, char const *argv[])
{
    char func_name[32];
    printf("Enter func_name: ");
    scanf("%s", func_name);
    Invoke(func_name);
    
    return 0;
}
