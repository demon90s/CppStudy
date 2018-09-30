/* Asks user to guess a hidden number */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_NUMBER 100

/* prototypes */
int new_secret_number();
void read_guesses(int secret_number);

int main()
{
	char command;
	int secret_number;

	printf("Guess the secret_number between 1 and %d.\n", MAX_NUMBER);
	srand((unsigned int)time(0));

	do
	{
		secret_number = new_secret_number();

		printf("A new number has been choosen.\n");

		read_guesses(secret_number);

		printf("Play again? [Y/N] ");
		scanf(" %c", &command);
		printf("\n");

	} while (command == 'Y' || command == 'y');

	return 0;
}


/*
 @return: 生成一个新的随机数
*/
int new_secret_number()
{
	return rand() % MAX_NUMBER + 1;
}

/*
 读取用户输入，判断是否符合secret_number，并给予提示
*/
void read_guesses(int secret_number)
{
	int guess_number, guess_times;

	for (;;)
	{
		++ guess_times;

		printf("Enter guesses: ");
		scanf("%d", &guess_number);

		if (guess_number == secret_number)
		{
			printf("You won in %d guess(es)\n", guess_times);
			break;
		}
		else if (guess_number > secret_number)
		{
			printf("Too high, try again.\n");
		}
		else
		{
			printf("Too low, try again.\n");
		}
	}
}
