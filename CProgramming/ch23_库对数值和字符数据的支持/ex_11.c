/*
    编写一个程序，提示用户输入一系列单词。然后按相反的顺序显示出来。将输入按字符串的形式读入，
    然后使用 strtok 函数将它们重新分割成单词。
*/

#include <stdio.h>
#include <string.h>

int main()
{
    char buffer[1024];
    int stack_count = 0;
    const char *stack[1024];
    char *token;

    printf("Enter words: ");
    fgets(buffer, sizeof(buffer), stdin);
    if (buffer[strlen(buffer) - 1] == '\n')
        buffer[strlen(buffer) - 1] = '\0';

    token = strtok(buffer, " ");
	while (token != NULL) {
        stack[stack_count++] = token;
		token = strtok(NULL, " ");
	}

    printf("reserve: ");
    while (stack_count > 0) {
        printf("%s ", stack[--stack_count]);
    }
    printf("\n");

    return 0;
}