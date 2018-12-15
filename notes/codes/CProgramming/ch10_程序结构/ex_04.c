/*
 * 把数组 num_in_rank 、数组 num_in_suit 和数组 card_exists 从 poker.c 程序中去掉。程序改用
 * 5*2d的数组来代替存储牌。
 */

/*
 * Classifies a poker hand
 */

#include <stdio.h>
#include <stdlib.h>

#define NUM_RANKS 13
#define NUM_SUITS 4
#define NUM_CARDS 5
#define TRUE 1
#define FALSE 0

typedef int Bool;

int cards[NUM_CARDS][2]; /* 第一列为 rank ，第二列为 suit */
Bool straight, flush, four, three;
int pairs; /* can be 0, 1, or 2 */

void sort_by_rank(int cards[][2], int count);
Bool card_exists(int cards[][2], int count, int rank, int suit);
void read_cards(void);
void analyze_hand(void);
void print_result(void);

/*
 * main: Calls read_cards, analyse_hand, and print_result
 * 		 repeatedly.
 */
int main()
{
	for (;;) { /* infinite loop */
		read_cards();
		analyze_hand();
		print_result();
	}

	return 0;
}

/*
 * sort_by_rank: 按照 rank 将 cards 排序（升序）
 */
void sort_by_rank(int cards[][2], int count)
{
	int i, max_index, tmp;

	if (count <= 1) return;

	max_index = 0;
	for (i = 1; i < count; i++) {
		if (cards[i][0] > cards[max_index][0])
			max_index = i;
	}

	tmp = cards[count - 1][0];
	cards[count - 1][0] = cards[max_index][0];
	cards[max_index][0] = tmp;

	tmp = cards[count - 1][1];
	cards[count - 1][1] = cards[max_index][1];
	cards[max_index][1] = tmp;

	sort_by_rank(cards, count - 1);
}

/*
 * card_exists: 查询 rank 和 suit 代表的卡牌是否已经存在于 cards
 */
Bool card_exists(int cards[][2], int count, int rank, int suit)
{
	int i;

	for (i = 0; i < count; i++) {
		if (cards[i][0] == rank && cards[i][1] == suit)
			return TRUE;
	}

	return FALSE;
}

/*
 * read_cards: Reads the cards into the external
 * 			   variables num_in_rank and num_in_suit;
 * 			   checks for bad cards and duplicate cards.
 */
void read_cards(void)
{
	char ch, rank_ch, suit_ch;
	int i, j, rank, suit;
	Bool bad_card;
	int cards_read = 0;

	for (i = 0; i < NUM_CARDS; i++) {
		for (j = 0; j < 2; j++) {
			cards[i][j] = -1;
		}
	}

	while (cards_read < NUM_CARDS) {
		bad_card = FALSE;

		printf("Enter a card: ");

		rank_ch = getchar();
		switch(rank_ch) {
			case '0':			exit(EXIT_SUCCESS); break;
			case '2':			rank = 0; break;
			case '3':			rank = 1; break;
			case '4':			rank = 2; break;
			case '5':			rank = 3; break;
			case '6':			rank = 4; break;
			case '7':			rank = 5; break;
			case '8':			rank = 6; break;
			case '9':			rank = 7; break;
			case 't': case 'T':	rank = 8; break;
			case 'j': case 'J':	rank = 9; break;
			case 'q': case 'Q': rank = 10;break;
			case 'k': case 'K': rank = 11;break;
			case 'a': case 'A': rank = 12;break;
			default:			bad_card = TRUE;
		}

		suit_ch = getchar();
		switch(suit_ch) {
			case 'c': case 'C':	suit = 0; break;
			case 'd': case 'D': suit = 1; break;
			case 'h': case 'H': suit = 2; break;
			case 's': case 'S': suit = 3; break;
			default:			bad_card = TRUE;
		}

		while ((ch = getchar()) != '\n')
			if (ch != ' ') bad_card = TRUE;

		if (bad_card)
			printf("Bad card; ignored.\n");
		else if (card_exists(cards, cards_read, rank, suit))
			printf("Duplicate card; ignored.\n");
		else {
			cards[cards_read][0] = rank;
			cards[cards_read][1] = suit;
			cards_read++;
		}
	}
}

/*
 * analyze_hand: Determines whether the hand contains a
 * 			     straight, a flush, four-of-a-kind,
 * 			     and/or a three-of-a-kind; determines the
 * 			     number of pairs; stores the result into
 * 			     the external variables straight, flush,
 * 			     four, three, and pairs.
 */

void analyze_hand()
{
	int num_consec = 0;
	int i, tmp;

	sort_by_rank(cards, NUM_CARDS);

	straight = FALSE;
	flush = FALSE;
	four = FALSE;
	three = FALSE;
	pairs = 0;

	/* check for flush */
	flush = TRUE;
	for (i = 1; i < NUM_CARDS; i++) {
		if (cards[i][1] != cards[0][1])
			flush = FALSE;
	}

	/* check for straight */
	straight = TRUE;
	for (i = 1; i < NUM_CARDS; i++) {
		if (cards[i][0] != cards[i - 1][0] + 1)
			straight = FALSE;
	}

	/* check for 4-of-kind, 3-of-kind, and pairs */
	tmp = cards[0][0];
	num_consec = 1;
	for (i = 1; i < NUM_CARDS; i++) {
		if (cards[i][0] == tmp) {
			num_consec++;
			if (num_consec == 4) four = TRUE;
			if (num_consec == 3) three = TRUE;
			if (num_consec == 2) pairs++;
		}
		else {
			tmp = cards[i][0];
			num_consec = 1;
		}
	}
}

/*
 * print_result: Notifies the user of the result, using
 * 			     the external variables straight, flush,
 * 			     four, three, and pairs.
 */
void print_result()
{
	if (straight && flush) 	printf("Straight flush\n\n");
	else if (four)			printf("Four of a kind\n\n");
	else if (three &&
			 pairs == 1)	printf("Full house\n\n");
	else if (flush)			printf("Flush\n\n");
	else if (straight)		printf("Straight\n\n");
	else if (three)			printf("Three of a kind\n\n");
	else if (pairs == 2)	printf("Two Pair\n\n");
	else if (pairs == 1)	printf("Pair\n\n");
	else					printf("High card\n\n");
}
