/*
    请编写一个程序把用户录入的一系列单词进行排序，并且显示删除的重复部分。提示：采用指针数组，
    且每个指针都指向动态分配的字符串。额外加分：使用 qsort 函数（17.7节）进行排序操作。
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define WORD_COUNT 10
#define WORD_LEN 32

int find_word(char *words[WORD_COUNT], int word_count, const char *word)
{
    int i;
    for (i = 0; i < word_count; i++) {
        if (strcmp(words[i], word) == 0)
            return i;
    }
    return -1;
}

int compare_str(const void *p1, const void *p2)
{
    return strcmp(*(char**)p1, *(char**)p2);
}

int main(int argc, char const *argv[])
{
    int word_count = 0;
    int i;
    char *words[WORD_COUNT] = {0};
    char word[WORD_LEN];

    while (1) {
        printf("Enter word(# to quit): ");
        scanf("%s", word);
        if (word[0] == '#') break;
        
        if (find_word(words, word_count, word) >= 0) {
            printf("Duplicate word: %s\n", word);
            continue;
        }
        
        words[word_count] = malloc(sizeof(char) * strlen(word) + 1);
        strcpy(words[word_count], word);
        word_count++;
    }

    qsort(words, word_count, sizeof(char*), compare_str);

    printf("words:");
    for (i = 0; i < word_count; i++) {
        printf(" %s", words[i]);
    }
    printf("\n");

    for (i = 0; i < word_count; i++) {
        free(words[i]);
    }

    return 0;
}
