#include "rule02.h"
#include <iostream>

const int GamePlayer::NumTurns;		// NumTurnsµÄ¶¨Òå

extern void rule02_f(int i)
{
	std::cout << i << std::endl;
}

extern void Rule02()
{
	CallWithMax(3, 5);
}