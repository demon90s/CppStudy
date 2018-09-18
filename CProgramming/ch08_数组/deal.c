/* Deals a random hand of cards. */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define NUM_SUITS 4
#define NUM_RANKS 13

int main()
{
	int inhand_cards[NUM_SUITS][NUM_RANKS] = {0};
	char suit_list[NUM_SUITS] = {'c', 'd', 'h', 's'};
	char rank_list[NUM_RANKS] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 't', 'J', 'Q', 'K'};
	int need_cards;
	int rank, suit;

	printf("Enter number of cards in hand: ");
	scanf("%d", &need_cards);

	printf("Your hand:");

	srand((unsigned int)time(NULL));
	while (need_cards > 0)
	{
		int suit = rand() % NUM_SUITS;
		int rank = rand() % NUM_RANKS;
		if (inhand_cards[suit][rank] == 0)
		{
			inhand_cards[suit][rank] = 1;
			-- need_cards;

			printf(" %c%c", suit_list[suit], rank_list[rank]);
		}
	}
	printf("\n");

	return 0;
}
