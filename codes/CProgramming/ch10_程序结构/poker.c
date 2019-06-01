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

int num_in_rank[NUM_RANKS];
int num_in_suit[NUM_SUITS];
Bool straight, flush, four, three;
int pairs; /* can be 0, 1, or 2 */

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
 * read_cards: Reads the cards into the external
 * 			   variables num_in_rank and num_in_suit;
 * 			   checks for bad cards and duplicate cards.
 */
void read_cards(void)
{
	Bool card_exists[NUM_RANKS][NUM_SUITS];
	char ch, rank_ch, suit_ch;
	int rank, suit;
	Bool bad_card;
	int cards_read = 0;

	for (rank = 0; rank < NUM_RANKS; rank++) {
		num_in_rank[rank] = 0;
		for (suit = 0; suit < NUM_SUITS; ++suit) {
			card_exists[rank][suit] = FALSE;
		}
	}

	for (suit = 0; suit < NUM_SUITS; suit++) {
		num_in_suit[suit] = 0;
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
		else if (card_exists[rank][suit])
			printf("Duplicate card; ignored.\n");
		else {
			num_in_rank[rank]++;
			num_in_suit[suit]++;
			card_exists[rank][suit] = TRUE;
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
	int rank, suit;

	straight = FALSE;
	flush = FALSE;
	four = FALSE;
	three = FALSE;
	pairs = 0;

	/* check for flush */
	for (suit = 0; suit < NUM_SUITS; suit++) {
		if (num_in_suit[suit] == NUM_CARDS)
			flush = TRUE;
	}

	/* check for straight */
	rank = 0;
	while (num_in_rank[rank] == 0) rank++;
	for (; rank < NUM_RANKS && num_in_rank[rank]; ++rank)
		num_consec++;
	if (num_consec == NUM_CARDS) {
		straight = TRUE;
		return;
	}

	/* check for 4-of-kind, 3-of-kind, and pairs */
	for (rank = 0; rank < NUM_RANKS; rank++) {
		if (num_in_rank[rank] == 4) four = TRUE;
		if (num_in_rank[rank] == 3) three = TRUE;
		if (num_in_rank[rank] == 2) pairs++;
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
