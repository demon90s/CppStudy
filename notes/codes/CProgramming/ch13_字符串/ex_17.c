/*
 * 修改8.2节的 deal.c 程序，使它显示出牌的全名：
 *
 * Enter number of cards in hand: 5
 * Your hand:
 * Seven of clubs
 * Two of spades
 * Five of diamonds
 * Ace of spaded
 * Two of hearts
 *
 * 提示：用指向字符串的指针数组来替换数组 rank_code 和数组 suit_code;
 */

/* Deals a random hand of cards. */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

#define NUM_SUITS 4
#define NUM_RANKS 13

int main()
{
	int inhand_cards[NUM_SUITS][NUM_RANKS];
	char* suit_list[NUM_SUITS] = {"clubs", "diamonds", "hearts", "spades"};
	char* rank_list[NUM_RANKS] = {"ACE", "TWO", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queue", "King"};
	int need_cards;
	int rank, suit;

	printf("Enter number of cards in hand: ");
	scanf("%d", &need_cards);

	printf("Your hand:\n");

	memset(inhand_cards, 0, sizeof(inhand_cards));

	srand((unsigned int)time(NULL));
	while (need_cards > 0)
	{
		suit = rand() % NUM_SUITS;
		rank = rand() % NUM_RANKS;
		if (inhand_cards[suit][rank] == 0)
		{
			inhand_cards[suit][rank] = 1;
			-- need_cards;

			printf("%s of %s\n", rank_list[rank], suit_list[suit]);
		}
	}
	return 0;
}
