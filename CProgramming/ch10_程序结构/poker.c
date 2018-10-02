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
void analyse_hand(void);
void print_result(void);

/*
 * main: Calls read_cards, analyse_hand, and print_result
 * 		 repeatedly.
 */
int main()
{
	for (;;) { /* infinite loop */
		read_cards();
		analyse_hand();
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
}
