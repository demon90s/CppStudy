/*
 * 在线运动的名人之一是一个称为 BIFF 的家伙，他在编写消息上有独一无二的方法。下面是一条典
 * 型的 BIFF 公告：
 *
 * H3Y DUD3, C 15 R1LLY C00L!!!!!!!!!!
 *
 * 编写一个“ BIFF 过滤器”，它可以读取用户录入的消息并且把此消息翻译成 BIFF 的表达风格：
 *
 * Enter message: Hey dude, C is rilly cool
 * In BIFF-speak: H3Y DUD3, C 15 R1LLY C00L!!!!!!!!!!
 *
 * 程序需要把消息转换成大写字母，用数字代替特定的字母（A->4, B->8, E->3, I->1, O->0, S->5），然
 * 后添加10个感叹号。提示：在字符数组中存储原始消息，然后从数组头开始逐个翻译并且显示字符。
 */

#include <stdio.h>
#include <ctype.h>

#define MESSAGE_LEN 32

int main()
{
	char message[MESSAGE_LEN + 1];
	char word;
	int i, word_cnt;

	word_cnt = 0;

	printf("Enter message: ");
	while ((word = getchar()) != '\n') {
		message[word_cnt] = toupper(word);
		++word_cnt;

		if (word_cnt >= MESSAGE_LEN) break;
	}
	message[word_cnt] = '\0';

	for (i = 0; i < word_cnt; ++i) {
		switch (message[i]) {
			case 'A' : message[i] = '4'; break;
			case 'B' : message[i] = '8'; break;
			case 'E' : message[i] = '3'; break;
			case 'I' : message[i] = '1'; break;
			case 'O' : message[i] = '0'; break;
			case 'S' : message[i] = '5'; break;
		}
	}

	printf("In BIFF-speak: %s!!!!!!!!!!\n", message);

	return 0;
}
