/*
 * 编写程序用来找到一组单词中“最大”单词和“最小”单词。当用户输入单词后，程序根据字典的排序
 * 决定排在最前面和最后面的单词。当用户输入了4个字母的单词时，程序必须停止读入。假设所有
 * 单词都不超过20个字母。程序与用户的交互显示如下所示：
 *
 * Enter word: dog
 * Enter word: zebra
 * Enter word: rabbit
 * Enter word: catfish
 * Enter word: walrus
 * Enter word: cat
 * Enter word: fish
 * Smallest word: cat
 * Largest word: zebra
 *
 * 提示：使用两个名为 smallest_word 和 largest_word 的字符串来记录当前输入“最小”单词和
 * “最大”单词。每次用户输入新单词，就用 strcmp 函数把它与 smallest_word 进行比较。如果
 * 新的单词比 smallest_word 小，就用 strcpy 函数把新单词保存到 smallest_word 中。用类似
 * 的方式与 largest_word 也进行比较。用 strlen 函数用来判断用户输入4个字符的单词的时候。
 */

#include <stdio.h>
#include <string.h>

#define LEN 20

int main()
{
	char smallest_word[LEN + 1];
	char largest_word[LEN + 1];
	char word[LEN + 1];

	printf("Enter word: ");
	scanf("%s", word);

	strcpy(smallest_word, word);
	strcpy(largest_word, word);

	while (strlen(word) != 4) {
		if (strcmp(smallest_word, word) > 0) strcpy(smallest_word, word);
		if (strcmp(largest_word, word) < 0) strcpy(largest_word, word);

		printf("Enter word: ");
		scanf("%s", word);
	}

	printf("Smallest word: %s\n", smallest_word);
	printf("Largest word: %s\n", largest_word);

	return 0;
}
